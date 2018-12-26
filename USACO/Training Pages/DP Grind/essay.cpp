/*
ID: vamaddu1
LANG: C++11
TASK: essay
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

int S, Q, dp [2][5010];

int main(){
    freopen("essay.in", "r", stdin); freopen("essay.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> S >> Q;
    for(int i = 0; i < S; i++){
        int now = i%2, nexty = (i+1)%2, inc, dec; cin >> inc >> dec;
        for(int j = 0; j <= Q; j++){
            dp[nexty][max(0, j-dec)] = max(dp[nexty][max(0, j-dec)], dp[now][j]);
            if(j+inc <= Q) dp[nexty][j+inc] = max(dp[nexty][j+inc], dp[now][j]+1);
        }
    }
    cout << *max_element(dp[S%2], dp[S%2]+Q+1) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
