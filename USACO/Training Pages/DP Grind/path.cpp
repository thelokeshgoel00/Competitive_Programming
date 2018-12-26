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

int N, M, K;
vector<pair<int, int>> adjacency [5010];
long long dp [2][5010];

int main(){
    freopen("path.in", "r", stdin); freopen("path.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N >> M >> K; fill(dp[0], dp[0]+N+1, MOD); dp[0][1] = 0;
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c;
        adjacency[a].pb(mp(b, c)); adjacency[b].pb(mp(a, c));
    }
    for(int k = 0; k < K; k++){
        int now = k%2, nexty = (k+1)%2;
        fill(dp[nexty], dp[nexty]+N+1, MOD);
        for(int i = 1; i <= N; i++)
            for(pair<int, int> edge : adjacency[i])
                dp[nexty][edge.f] = min(dp[nexty][edge.f], dp[now][i]+edge.s);
    }
    cout << dp[K%2][N] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
