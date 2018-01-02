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
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, subtreeSizes [100010], parents [100010];
vector<pair<int, int>> adjacency [100010];
vector<int> pathy;
unordered_map<int, long long> freq;
bool visited [100010];
long long ret;

void findSubtreeSizes(int curr){
    subtreeSizes[curr] = 1;
    for(pair<int, int> edge : adjacency[curr]){
        if(visited[edge.first] || parents[curr] == edge.first) continue;
        parents[edge.first] = curr; findSubtreeSizes(edge.first);
        subtreeSizes[curr] += subtreeSizes[edge.first];
    }
}

int getCentroid(int curr){
    parents[curr] = 0; findSubtreeSizes(curr);
    int sz = subtreeSizes[curr];
    while(true){
        pair<int, int> maxi = make_pair(0, 0);
        for(pair<int, int> edge : adjacency[curr]){
            if(visited[edge.first] || parents[curr] == edge.first) continue;
            maxi = max(maxi, make_pair(subtreeSizes[edge.first], edge.first));
        }
        if(maxi.first*2 > sz) curr = maxi.second;
        else return curr;
    }
    return -1;
}

void dfs(int curr, int weight){
    pathy.push_back(weight);
    for(pair<int, int> edge : adjacency[curr]){
        if(visited[edge.first] || parents[curr] == edge.first) continue;
        parents[edge.first] = curr;
        dfs(edge.first, weight+edge.second);
    }
}

void addIt(){
    for(int i : pathy){
        if(freq.find(-i+1) != freq.end()) ret += freq[-i+1];
        if(freq.find(-i-1) != freq.end()) ret += freq[-i-1];
    }
    for(int i : pathy) freq[i]++;
    pathy = vector<int>();
}

void solveIt(int curr){
    curr = getCentroid(curr); visited[curr] = true;
    freq = unordered_map<int, long long>(); freq[0] = 1;
    for(pair<int, int> edge : adjacency[curr]){
        if(visited[edge.first]) continue;
        parents[edge.first] = curr; dfs(edge.first, edge.second);
        addIt();
    }
    for(pair<int, int> edge : adjacency[curr])
        if(!visited[edge.first])
            solveIt(edge.first);
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; ret = -(N-1); memset(visited, false, sizeof(visited)); memset(parents, -1, sizeof(parents));
    for(int i = 0; i < N-1; i++){
        int a, b, w = 1; char c; cin >> a >> b >> c;
        if(c == 'b') w = -1;
        adjacency[a].push_back(make_pair(b, w)); adjacency[b].push_back(make_pair(a, w));
    }
    solveIt(1);
    cout << ret << '\n';
    return 0;
}
