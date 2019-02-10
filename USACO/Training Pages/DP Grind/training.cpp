/*
ID: vamaddu1
LANG: C++11
TASK: training
*/

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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

struct Edge{
    int u, v, cost, LCA;
};

int N, M, totalCost = 0, tiempo = 0, dp [1010][1024];
int discover [1010], finish [1010], depths [1010], degree [1010], parity [1010];
Edge edges [5010];
vector<int> adjacency [1010];
pair<int, int> parents [1010];

void dfs(int curr){
    discover[curr] = tiempo++;
    for(int nexty : adjacency[curr]){
        if(nexty == parents[curr].f) continue;
        parity[nexty] = parity[curr]^1;
        depths[nexty] = depths[curr]+1;
        parents[nexty] = mp(curr, 1<<degree[curr]); degree[curr]++;
        dfs(nexty);
    }
    finish[curr] = tiempo++;
}

bool cmpLCA(Edge a, Edge b){ return finish[a.LCA] < finish[b.LCA]; }

int main(){
    freopen("training.in", "r", stdin); freopen("training.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M; parents[0] = mp(-1, -1);
    for(int i = 0; i < M; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].cost; edges[i].u--; edges[i].v--;
        totalCost += edges[i].cost;
        if(edges[i].cost == 0){
            adjacency[edges[i].u].pb(edges[i].v);
            adjacency[edges[i].v].pb(edges[i].u);
        }
    }
    dfs(0);
    for(int i = 0; i < M; i++){
        int u = edges[i].u, v = edges[i].v;
        while(depths[u] > depths[v]) u = parents[u].f;
        while(depths[v] > depths[u]) v = parents[v].f;
        while(u != v){
            u = parents[u].f;
            v = parents[v].f;
        }
        edges[i].LCA = u;
    }
    sort(edges, edges+M, cmpLCA);
    for(int i = 0; i < M; i++){
        if(edges[i].cost != 0 && parity[edges[i].u] != parity[edges[i].v]) continue;
        int sum = edges[i].cost; pair<int, int> lastyU, lastyV;
        for(pair<int, int> now = mp(edges[i].u, 0); now.f != edges[i].LCA; now = parents[now.f]){
            sum += dp[now.f][now.s];
            lastyU = parents[now.f];
        }
        for(pair<int, int> now = mp(edges[i].v, 0); now.f != edges[i].LCA; now = parents[now.f]){
            sum += dp[now.f][now.s];
            lastyV = parents[now.f];
        }
        for(int mask = (1<<degree[edges[i].LCA])-1; mask > -1; mask--)
            if((mask&lastyU.s) == 0 && (mask&lastyV.s) == 0)
                dp[edges[i].LCA][mask] = max(dp[edges[i].LCA][mask], dp[edges[i].LCA][mask|lastyU.s|lastyV.s]+sum);
    }
    cout << totalCost-dp[0][0] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
