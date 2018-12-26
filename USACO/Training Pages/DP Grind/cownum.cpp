/*
ID: vamaddu1
LANG: C++11
TASK: cownum
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

int N, M, dp [1010][1010], helper [1010][1010];

int main(){
    freopen("cownum.in", "r", stdin); freopen("cownum.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){ dp[1][i] = i%M; dp[2][i] = (i*i)%M; }
    for(int i = 3; i <= N; i++)
        for(int j = 1; j <= N; j++){
            if(j >= 2) helper[i][j] = (helper[i][j-1]+dp[i-2][j-2])%M;
            dp[i][j] = (dp[i][j-1]+dp[i-1][j-1]+dp[i-2][j-1]+helper[i][j])%M;
        }
    cout << dp[N][N] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
