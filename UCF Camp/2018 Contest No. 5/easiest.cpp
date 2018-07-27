#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <sstream>
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, K, maxDist, parents [100010], subtreeSizes [100010], depths [100010];
char breed [100010];
vector<int> adjacency [100010];
bool visited [100010];
map<int, long long> runningFreq, curFreq;
long long ret = 0;

void findSubtreeSizes(int curr, int d){
    subtreeSizes[curr] = 1; depths[curr] = d;
    for(int nexty : adjacency[curr]){
        if(visited[nexty] || parents[curr] == nexty) continue;
        parents[nexty] = curr; findSubtreeSizes(nexty, d+1);
        subtreeSizes[curr] += subtreeSizes[nexty];
    }
}

int getCentroid(int curr){
    parents[curr] = 0; findSubtreeSizes(curr, 0);
    int sz = subtreeSizes[curr];
    while(true){
        pair<int, int> maxi = make_pair(0, 0);
        for(int nexty : adjacency[curr]){
            if(visited[nexty] || parents[curr] == nexty) continue;
            maxi = max(maxi, make_pair(subtreeSizes[nexty], nexty));
        }
        if(maxi.first*2 > sz) curr = maxi.second;
        else return curr;
    }
    return -1;
}

void dfs(int curr, int weight){
    curFreq[weight]++;
    for(int nexty : adjacency[curr]){
        if(visited[nexty] || parents[curr] == nexty) continue;
        parents[nexty] = curr; dfs(nexty, weight+1);
    }
}

void addIt(){
    auto other = runningFreq.begin(); long long sum = 0;
    for(auto it = curFreq.rbegin(); it != curFreq.rend(); it++){
        while(other != runningFreq.end() && (*it).f+(*other).f <= K){
            sum += (*other).s;
            other++;
        }
        ret += sum*(*it).s;
    }
    for(pair<int, long long> x : curFreq) runningFreq[x.f] += curFreq[x.f];
}

void solveIt(int curr){
    curr = getCentroid(curr); visited[curr] = true;
    runningFreq = map<int, long long>(); runningFreq[0] = 1;
    for(int nexty : adjacency[curr]){
        if(visited[nexty]) continue;
        parents[nexty] = curr; curFreq = map<int, long long>();
        dfs(nexty, 1); addIt();
    }
    for(int nexty : adjacency[curr])
        if(!visited[nexty])
            solveIt(nexty);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> N >> K; memset(visited, false, sizeof(visited)); memset(parents, -1, sizeof(parents));
    for(int i = 1; i <= N; i++) cin >> breed[i];
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        if(breed[a] != breed[b]) continue;
        adjacency[a].pb(b); adjacency[b].pb(a);
    }
    for(int i = 1; i <= N; i++)
        if(!visited[i])
            solveIt(i);
    cout << ret << '\n';
    return 0;
}
