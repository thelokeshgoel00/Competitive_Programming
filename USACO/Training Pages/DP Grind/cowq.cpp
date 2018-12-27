/*
ID: vamaddu1
LANG: C++11
TASK: cowq
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

int N, P, Q;
bool swappy;
double dp [2][110][110], catalan [110];

int main(){
    freopen("cowq.in", "r", stdin); freopen("cowq.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> P >> Q; catalan[0] = catalan[1] = 1;
    for(int i = 2; i <= N; i++)
        for(int j = 0; j < N; j++)
            catalan[i] += catalan[j]*catalan[i-j-1];
    if(P > Q){ swappy = true; swap(P, Q); }
    dp[0][0][N+1] = 1;
    for(int i = 0; i < 2*N; i++){
        int now = i%2, nexty = (i+1)%2;
        memset(dp[nexty], 0, sizeof(dp[nexty]));
        for(int j = 0; j <= N; j++){
            if((i+j)%2 || j > i) continue;
            int opens = (i+j)/2, closes = i-opens;
            if(opens == P-1) dp[nexty][j+1][j] += dp[now][j][N+1];
            else dp[nexty][j+1][N+1] += dp[now][j][N+1];
            if(j > 0) dp[nexty][j-1][N+1] += dp[now][j][N+1];
            dp[nexty][j+1][N+2] += dp[now][j][N+2];
            if(j > 0) dp[nexty][j-1][N+2] += dp[now][j][N+2];
            if(opens >= Q) continue;
            for(int k = 0; k <= N; k++){
                dp[nexty][j+1][k] += dp[now][j][k];
                if(j > 0){
                    if(j-1 == k) dp[nexty][j-1][N+2] += dp[now][j][k];
                    else dp[nexty][j-1][k] += dp[now][j][k];
                }
            }
        }
    }
    cout << (swappy ? 1-dp[0][0][N+2]/catalan[N] : dp[0][0][N+2]/catalan[N]) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
