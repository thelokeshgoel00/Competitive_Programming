/*
ID: vamaddu1
LANG: C++11
TASK: bcatch
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

int T, W, dp [1010][40][2], ret = 0;

int main(){
    freopen("bcatch.in", "r", stdin); freopen("bcatch.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> T >> W;
    for(int i = 0; i < 1010; i++)
        for(int j = 0; j < 40; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = -MOD;
    dp[0][W][0] = 0;
    for(int i = 1; i <= T; i++){
        int loc; cin >> loc; loc--;
        for(int j = 0; j <= W; j++){
            if(loc == 0){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j+1][1])+1;
                dp[i][j][1] = dp[i-1][j][1];
            }
            else{
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j+1][0])+1;
                dp[i][j][0] = dp[i-1][j][0];
            }
            ret = max(ret, max(dp[i][j][0], dp[i][j][1]));
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
