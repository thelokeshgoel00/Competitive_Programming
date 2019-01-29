/*
ID: vamaddu1
LANG: C++11
TASK: rivers
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

int N, K, weight [110], depths [110], starts [110], nexts [110], dp [110][110][60], total = 0;
vector<pair<int, int>> adjacency [110];

void dfs(int curr, int d){
    depths[curr] = d; total += weight[curr]*depths[curr];
    for(pair<int, int> edge : adjacency[curr]) dfs(edge.f, d+edge.s);
    if(adjacency[curr].size() > 0) starts[curr] = adjacency[curr][0].f;
    for(int i = 1; i < adjacency[curr].size(); i++)
        nexts[adjacency[curr][i-1].f] = adjacency[curr][i].f;
}

int solveIt(int curr, int above, int remain){
    if(dp[curr][above][remain] != -1) return dp[curr][above][remain];
    if(curr == 0) return dp[curr][above][remain] = 0;
    int ret = 0;
    for(int i = 0; i <= remain; i++){
        ret = max(ret, solveIt(starts[curr], above, i)+solveIt(nexts[curr], above, remain-i)+weight[curr]*depths[above]);
        if(i == remain) break;
        ret = max(ret, solveIt(starts[curr], curr, i)+solveIt(nexts[curr], above, remain-i-1)+weight[curr]*depths[curr]);
    }
    return dp[curr][above][remain] = ret;
}

int main(){
    freopen("rivers.in", "r", stdin); freopen("rivers.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> K; memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= N; i++){
        int w, v, d; cin >> w >> v >> d;
        weight[i] = w; adjacency[v].pb(mp(i, d));
    }
    dfs(0, 0);
    cout << total-solveIt(starts[0], 0, K) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
