/*
ID: vamaddu1
LANG: C++11
TASK: books
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

int N, K;
long long books [210], people [210], costs [210][210], dp [210][110];

int main(){
    freopen("books.in", "r", stdin); freopen("books.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N >> K;
    for(int i = 0; i < 210; i++)
        for(int j = 0; j < 110; j++)
            dp[i][j] = INF/5;
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++) cin >> books[i];
    for(int j = 1; j <= N; j++) cin >> people[j];
    for(int i = 1; i <= N; i++)
        for(int j = i; j <= N; j++)
            costs[i][j] = costs[i][j-1]+people[j-i+1]*books[j];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= K; j++){
            dp[i][j] = dp[i][j-1];
            for(int k = i; k > 0; k--)
                dp[i][j] = min(dp[i][j], dp[k-1][j-1]+costs[k][i]);
        }
    cout << dp[N][K] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
