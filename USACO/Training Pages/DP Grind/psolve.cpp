/*
ID: vamaddu1
LANG: C++11
TASK: psolve
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

int M, P, dp [310][310];
pair<int, int> arr [310];

int main(){
    freopen("psolve.in", "r", stdin); freopen("psolve.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> M >> P; arr[0] = mp(0, 0); fill(dp[0], dp[0]+310, MOD); dp[0][0] = 2;
    for(int i = 1; i <= P; i++){
        cin >> arr[i].f >> arr[i].s; int before = 0, aftermath = 0;
        for(int j = i; j > -1; j--){
            dp[i][j] = MOD; before += arr[j].f; aftermath += arr[j].s;
            if(before > M || aftermath > M) continue;
            if(j == 0){ dp[i][j] = dp[i][j+1]; continue; }
            int after = 0;
            for(int k = j-1; k > -1; k--){
                after += arr[k].s;
                if(dp[j-1][k] == MOD || after > M) break;
                if(before+after <= M) dp[i][j] = min(dp[i][j], dp[j-1][k]+1);
                else dp[i][j] = min(dp[i][j], dp[j-1][k]+2);
            }
        }
    }
    cout << *min_element(dp[P], dp[P]+P+1) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
