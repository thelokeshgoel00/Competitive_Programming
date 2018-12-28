/*
ID: vamaddu1
LANG: C++11
TASK: smrtfun
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

int N, mid, dp [200010], ret = 0;

int main(){
    freopen("smrtfun.in", "r", stdin); freopen("smrtfun.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N; mid = 1000*N; fill(dp, dp+200010, -MOD); dp[mid] = 0;
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        if(a > 0){
            for(int j = mid*2; j >= a; j--)
                dp[j] = max(dp[j], dp[j-a]+b);
        }
        else{
            for(int j = 0; j <= mid*2+a; j++)
                dp[j] = max(dp[j], dp[j-a]+b);
        }
    }
    for(int i = mid; i <= mid*2; i++)
        if(dp[i] > 0)
            ret = max(ret, i-mid+dp[i]);
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
