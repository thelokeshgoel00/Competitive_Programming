/*
ID: vamaddu1
LANG: C++11
TASK: ontherun
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

int N;
long long L, cowPos [1010], dp [2][1010][2];

int main(){
    freopen("ontherun.in", "r", stdin); freopen("ontherun.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N >> L; cowPos[1] = 0; N++; memset(dp[0], 63, sizeof(dp[0]));
    for(int i = 2; i <= N; i++){ cin >> cowPos[i]; cowPos[i] -= L; }
    sort(cowPos+1, cowPos+N+1);
    for(int i = 1; i <= N; i++)
        if(cowPos[i] == 0)
            dp[0][i][0] = 0;
    for(int len = 1; len < N; len++){
        memset(dp[len%2], 63, sizeof(dp[len%2]));
        for(int i = 1; i+len <= N+1; i++){
            dp[len%2][i-1][0] = min(dp[len%2][i-1][0], min(dp[(len-1)%2][i][0]+(N-len)*(cowPos[i]-cowPos[i-1]),
                                                           dp[(len-1)%2][i][1]+(N-len)*(cowPos[i+len-1]-cowPos[i-1])));
            dp[len%2][i][1] = min(dp[len%2][i][1], min(dp[(len-1)%2][i][0]+(N-len)*(cowPos[i+len]-cowPos[i]),
                                                           dp[(len-1)%2][i][1]+(N-len)*(cowPos[i+len]-cowPos[i+len-1])));
        }
    }
    cout << min(dp[(N-1)%2][1][0], dp[(N-1)%2][1][1]) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
