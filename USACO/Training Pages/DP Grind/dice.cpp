/*
ID: vamaddu1
LANG: C++11
TASK: dice
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

int D1, S1, dp1 [2][1050], D2, S2, dp2 [2][1050], num1 = 0, num2 = 0, total1 = 0, total2 = 0;
bool sameSums = true;
bool sameProbs = true;

int main(){
    freopen("dice.in", "r", stdin); freopen("dice.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> D1 >> S1; dp1[0][0] = 1;
    for(int i = 1; i <= D1; i++){
        memset(dp1[i%2], 0, sizeof(dp1[i%2]));
        for(int j = 0; j < S1; j++){
            int x; cin >> x;
            for(int k = x; k <= 32*D1; k++){
                dp1[i%2][k] += dp1[(i-1)%2][k-x];
                dp1[i%2][k] %= MOD;
            }
        }
    }
    cin >> D2 >> S2; dp2[0][0] = 1;
    for(int i = 1; i <= D2; i++){
        memset(dp2[i%2], 0, sizeof(dp2[i%2]));
        for(int j = 0; j < S2; j++){
            int x; cin >> x;
            for(int k = x; k <= 32*D2; k++){
                dp2[i%2][k] += dp2[(i-1)%2][k-x];
                dp2[i%2][k] %= MOD;
            }
        }
    }
    for(int i = 0; i < 1050; i++){
        if(dp1[D1%2][i] > 0) num1++;
        if(dp2[D2%2][i] > 0) num2++;
        if((dp1[D1%2][i] == 0)^(dp2[D2%2][i] == 0)) sameSums = false;
        total1 += dp1[D1%2][i]; total2 += dp2[D2%2][i];
        total1 %= MOD; total2 %= MOD;
    }
    for(int i = 0; i < 1050; i++)
        if((long long)dp1[D1%2][i]*(long long)total2 != (long long)dp2[D2%2][i]*(long long)total1)
            sameProbs = false;
    cout << (sameSums ? 'Y' : 'N') << ' ' << (sameProbs ? 'Y' : 'N') << '\n';
    cout << num1 << ' ' << num2 << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
