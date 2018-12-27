/*
ID: vamaddu1
LANG: C++11
TASK: naptime
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

int N, B, arr [4010], dp [2][4010][2], ret;

void fillTable(){
    for(int i = 2; i <= N; i++){
        int now = i%2, nexty = (i+1)%2;
        for(int j = 1; j <= i; j++){
            dp[nexty][j][0] = max(dp[now][j][0], dp[now][j][1]);
            dp[nexty][j][1] = dp[now][j-1][0];
            if(j > 1) dp[nexty][j][1] = max(dp[nexty][j][1], dp[now][j-1][1]+arr[i]);
        }
    }
}

int main(){
    freopen("naptime.in", "r", stdin); freopen("naptime.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N >> B;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    fillTable();
    ret = max(dp[(N+1)%2][B][0], dp[(N+1)%2][B][1]);
    memset(dp, 0, sizeof(dp)); dp[0][1][1] = arr[1];
    fillTable();
    ret = max(ret, dp[(N+1)%2][B][1]);
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
