/*
ID: vamaddu1
LANG: C++11
TASK: storage
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

int N, B, heights [260], dp [2][260][260], ret = 0;
pair<int, int> arr [260];

int main(){
    freopen("storage.in", "r", stdin); freopen("storage.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> B;
    for(int i = 0; i < N; i++){ cin >> arr[i].s >> arr[i].f; arr[i].s *= -1; }
    for(int i = 0; i < B; i++) cin >> heights[i];
    sort(arr, arr+N); reverse(arr, arr+N);
    for(int i = 0; i < N; i++) arr[i].s *= -1;
    for(int k = 0; k < N; k++){
        int curr = k&1, nexty = curr^1;
        for(int i = 0; i < B; i++){
            if(i+arr[k].s <= B && arr[k].f <= min(heights[i], heights[i+arr[k].s-1])){
                dp[nexty][i][i+arr[k].s-1] = max(dp[nexty][i][i+arr[k].s-1], arr[k].f*arr[k].s);
                ret = max(ret, dp[nexty][i][i+arr[k].s-1]);
            }
            for(int j = i; j < B; j++){
                if(j+arr[k].s < B && arr[k].f <= min(heights[i], heights[j+arr[k].s])){
                    dp[nexty][i][j+arr[k].s] = max(dp[nexty][i][j+arr[k].s], dp[curr][i][j]+arr[k].f*arr[k].s);
                    ret = max(ret, dp[nexty][i][j+arr[k].s]);
                }
                if(i-arr[k].s > -1 && arr[k].f <= min(heights[i-arr[k].s], heights[j])){
                    dp[nexty][i-arr[k].s][j] = max(dp[nexty][i-arr[k].s][j], dp[curr][i][j]+arr[k].f*arr[k].s);
                    ret = max(ret, dp[nexty][i-arr[k].s][j]);
                }
                dp[nexty][i][j] = max(dp[nexty][i][j], dp[curr][i][j]);
            }
        }
        for(int i = 0; i < B; i++)
            for(int j = i; j < B; j++){
                if(i+1 < B) dp[nexty][i][j] = max(dp[nexty][i][j], dp[nexty][i+1][j]);
                if(j-1 > -1) dp[nexty][i][j] = max(dp[nexty][i][j], dp[nexty][i][j-1]);
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
