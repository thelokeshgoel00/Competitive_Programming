/*
ID: vamaddu1
LANG: C++11
TASK: trt
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

int N, arr [2010], dp [2][2010];

int main(){
    freopen("trt.in", "r", stdin); freopen("trt.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int len = N; len >= 1; len--)
        for(int i = 1; i <= N-len+1; i++){
            int age = N-len+1;
            dp[(age+1)%2][i] = max(dp[(age+1)%2][i], dp[age%2][i]+age*arr[i+len-1]);
            dp[(age+1)%2][i+1] = max(dp[(age+1)%2][i+1], dp[age%2][i]+age*arr[i]);
        }
    cout << *max_element(dp[(N+1)%2], dp[(N+1)%2]+2010) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
