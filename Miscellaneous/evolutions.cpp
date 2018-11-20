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

int kase, dp [1000010];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    for(int i = 1; i <= 1000; i++)
        for(int j = 1; j < i; j++){
            if(__gcd(i, j) > 1) continue;
            for(int k = 2; ; k++){
                int add = pow(j, k), sum = add;
                for(int z = 0; z < k; z++){ add = (add/j)*i; sum += add; }
                if(sum > 1000000) break;
                dp[sum]++;
            }
        }
    for(int i = 1000000; i > 1; i--)
        for(int j = 2; j <= 1000000/i; j++)
            dp[i*j] += dp[i];
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        int x; cin >> x;
        cout << dp[x]+(x+1)/2 << (kk == kase ? '\n' : ' ');
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
