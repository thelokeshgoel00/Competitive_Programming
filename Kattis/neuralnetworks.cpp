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
#define MOD 998244353

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, arr [500010];
long long fact [500010], invfact [500010], powa [500010], ret = 1;

long long fastPow(long long base, long long expo){
    base %= MOD;
    if(expo == 0) return 1;
    long long halfy = fastPow(base, expo/2);
    long long bro = expo%2 ? base : 1;
    return (((halfy*halfy)%MOD)*bro)%MOD;
}

long long modInverse(long long x){ return fastPow(x, MOD-2); }

long long choose(long long n, long long k){ return (((fact[n]*invfact[k])%MOD)*invfact[n-k])%MOD; }

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N; fact[0] = invfact[0] = powa[0] = 1;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 1; i <= 500000; i++){
        powa[i] = (powa[i-1]*2)%MOD;
        fact[i] = (fact[i-1]*(long long)i)%MOD;
        invfact[i] = (invfact[i-1]*modInverse((long long)i))%MOD;
    }
    for(int i = 1; i < N; i++){
        long long a = arr[i-1], b = arr[i];
        long long mult = 0, signy = 1;
        for(long long num = a; num > 0; num--){
            long long combi = choose(a, num);
            //cout << a << ' ' << num << ' ' << combi << endl;
            long long val = (combi*fastPow(powa[num]-1+MOD, b))%MOD;
            mult += (val*signy)%MOD+MOD; mult %= MOD; signy = -signy;
        }
        ret = (ret*mult)%MOD;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
