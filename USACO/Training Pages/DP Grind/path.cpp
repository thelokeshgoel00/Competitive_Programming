/*
ID: vamaddu1
LANG: C++11
TASK: path
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
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, M, K, costs [5010][610], ret = MOD;
vector<pair<int, int>> adjacency [5010];
priority_queue<pair<int, pair<int, int>>> pq;

int main(){
    freopen("path.in", "r", stdin); freopen("path.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N >> M >> K; memset(costs, -1, sizeof(costs)); pq.push(mp(0, mp(1, 0)));
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        adjacency[a].pb(mp(b, c)); adjacency[b].pb(mp(a, c));
    }
    while(pq.size() > 0){
        pair<int, pair<int, int>> now = pq.top(); pq.pop();
        if(costs[now.s.f][now.s.s] != -1) continue;
        if(now.s.f == N && now.s.s == K) ret = min(ret, -now.f);
        costs[now.s.f][now.s.s] = -now.f;
        if(now.s.s == K) continue;
        for(pair<int, int> edge : adjacency[now.s.f]){
            int nexty = edge.f, newCost = now.f-edge.s;
            if(costs[nexty][now.s.s+1] == -1) pq.push(mp(newCost, mp(nexty, now.s.s+1)));
        }
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
