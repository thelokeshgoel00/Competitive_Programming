#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

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
long long arr [500010];
set<long long> dp [2], ret;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    dp[0].insert(arr[0]); ret.insert(arr[0]);
    for(int i = 1; i < N; i++){
        dp[(i&1)] = set<long long>();
        dp[(i&1)].insert(arr[i]); ret.insert(arr[i]);
        for(long long x : dp[(i&1)^1])
            if(x != 1){
                long long val = __gcd(x, arr[i]);
                dp[(i&1)].insert(val); ret.insert(val);
            }
    }
    cout << ret.size() << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
