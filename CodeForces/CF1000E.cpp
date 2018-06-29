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

int N, M, parents [300010], disc [300010], low [300010], tiempo = 0, compID = 0, compNum [300010], dists [300010];
vector<int> ori [300010], compress [300010];
vector<pair<int, int>> edges;
bool visited [300010];
set<pair<int, int>> bridges;
pair<int, int> ret = make_pair(0, 0);

void findBridges(int curr){
    visited[curr] = true; disc[curr] = low[curr] = tiempo++;
    for(int next : ori[curr]){
        if(!visited[next]){
            parents[next] = curr; findBridges(next);
            low[curr] = min(low[curr], low[next]);
            if(low[next] > disc[curr]){
                bridges.insert(make_pair(curr, next));
                bridges.insert(make_pair(next, curr));
            }
        }
        else if(next != parents[curr]) low[curr] = min(low[curr], disc[next]);
    }
}

void bfs(){
    memset(dists, -1, sizeof(dists)); ret.s = 0;
    queue<int> q; dists[ret.f] = 0; q.push(ret.f);
    while(q.size() > 0){
        int x = q.front(); q.pop();
        for(int nexty : compress[x])
            if(dists[nexty] == -1){
                dists[nexty] = dists[x]+1; q.push(nexty);
                if(dists[nexty] > ret.s) ret = make_pair(nexty, dists[nexty]);
            }
    }
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low));
    memset(parents, -1, sizeof(parents)); memset(visited, false, sizeof(visited)); memset(compNum, -1, sizeof(compNum));
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        ori[a].push_back(b); ori[b].push_back(a);
        edges.push_back(make_pair(a, b));
    }
    for(int i = 1; i <= N; i++)
        if(!visited[i])
            findBridges(i);
    for(int i = 1; i <= N; i++){
        if(compNum[i] > -1) continue;
        queue<int> q; q.push(i);
        while(q.size() > 0){
            int x = q.front(); q.pop();
            if(compNum[x] > -1) continue;
            compNum[x] = compID;
            for(int y : ori[x])
                if(compNum[y] == -1 && bridges.find(make_pair(x, y)) == bridges.end())
                    q.push(y);
        }
        compID++;
    }
    for(int i = 0; i < M; i++){
        if(compNum[edges[i].f] == compNum[edges[i].s]) continue;
        compress[compNum[edges[i].f]].push_back(compNum[edges[i].s]);
        compress[compNum[edges[i].s]].push_back(compNum[edges[i].f]);
    }
    bfs(); bfs(); cout << ret.s << '\n';
    return 0;
}
