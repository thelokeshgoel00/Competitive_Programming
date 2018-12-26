/*
ID: vamaddu1
LANG: C++11
TASK: turnin
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

int C, H, B, dp [1010][1010][2], ret = MOD;
pair<int, int> places [1010];

int main(){
    freopen("turnin.in", "r", stdin); freopen("turnin.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> C >> H >> B; memset(dp, 63, sizeof(dp));
    for(int i = 1; i <= C; i++) cin >> places[i].f >> places[i].s;
    sort(places+1, places+C+1);
    dp[1][C][0] = max(places[1].f, places[1].s); dp[1][C][1] = max(places[C].f, places[C].s);
    for(int i = 1; i <= C; i++)
        for(int j = C; j >= i; j--){
            if(i > 1){
                dp[i][j][0]=min(dp[i][j][0], dp[i-1][j][0]+places[i].f-places[i-1].f);
                dp[i][j][1]=min(dp[i][j][1], dp[i-1][j][0]+places[j].f-places[i-1].f);
            }
            if(j < C){
                dp[i][j][0]=min(dp[i][j][0], dp[i][j+1][1]+places[j+1].f-places[i].f);
                dp[i][j][1]=min(dp[i][j][1], dp[i][j+1][1]+places[j+1].f-places[j].f);
            }
            dp[i][j][0] = max(dp[i][j][0], places[i].s); dp[i][j][1] = max(dp[i][j][1], places[j].s);
            if(i == j) ret = min(ret, min(dp[i][i][0], dp[i][i][1])+abs(places[i].f-B));
        }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
