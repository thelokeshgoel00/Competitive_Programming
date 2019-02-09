/*
ID: vamaddu1
LANG: C++11
TASK: linegard
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

int N, M, dp [1000010][4][4], ret = 1;
string s;

int main(){
    freopen("linegard.in", "r", stdin); freopen("linegard.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M >> s;
    for(int maxi = 0; maxi < 3; maxi++)
        for(int mini = 0; mini < 3; mini++)
            dp[N][maxi][mini] = 1;
    for(int i = N-1; i > -1; i--)
        for(int maxi = 0; maxi < 3; maxi++)
            for(int mini = 0; mini < 3; mini++)
                dp[i][maxi][mini] = (dp[i+1][maxi+1][max(0, mini-1)]+dp[i+1][max(0, maxi-1)][mini+1])%M;
    for(int i = 0, maxi = 0, mini = 0; i < N; i++){
        if(s[i] == 'P'){
            ret = (ret+dp[i+1][max(0, maxi-1)][mini+1])%M;
            mini = max(0, mini-1); maxi++;
        }
        else{ maxi = max(0, maxi-1); mini++; }
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
