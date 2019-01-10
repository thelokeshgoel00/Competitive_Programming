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

int M, mid [1010][1010];
long long N, dp [1010][1010];
vector<long long> arr;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    while(cin >> N >> M){
        arr = vector<long long>(); arr.pb(0);
        for(int i = 0; i < M; i++){
            long long x; cin >> x;
            arr.pb(x);
        }
        arr.pb(N); M += 2;
        for(int len = 1; len <= M; len++)
            for(int li = 0; li+len-1 < M; li++){
                int ri = li+len-1;
                if(len <= 2){
                    dp[li][ri] = 0; mid[li][ri] = li;
                    continue;
                }
                int mleft = mid[li][ri-1], mright = mid[li+1][ri];
                dp[li][ri] = INF/5;
                for(int k = mleft; k <= mright; k++){
                    long long val = dp[li][k]+dp[k][ri]+arr[ri]-arr[li];
                    if(dp[li][ri] > val){
                        dp[li][ri] = val;
                        mid[li][ri] = k;
                    }
                }
            }
        cout << dp[0][M-1] << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
