#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5e18
#define MOD 1000000007
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
int N;
long long combo [3010][3010], f [3010], g [3010], h [3010];
 
long long fastPow(int expo){
    if(expo == 0) return 1;
    long long halfy = fastPow(expo/2); halfy *= halfy; halfy %= MOD;
    if(expo&1){ halfy *= 2; if(halfy >= MOD) halfy -= MOD; }
    return halfy;
}
 
int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(5);
    cin >> N; combo[0][0] = f[0] = 1;
    for(int i = 1; i <= N; i++){
        combo[i][0] = 1; f[i] = fastPow((i*(i-1))/2);
        for(int j = 1; j <= i; j++){
            combo[i][j] = combo[i-1][j]+combo[i-1][j-1];
            if(combo[i][j] >= MOD) combo[i][j] -= MOD;
        }
    }
    for(int i = 1; i <= N; i++){
        g[i] = f[i];
        for(int j = 1; j < i; j++){
            g[i] -= (combo[i-1][j-1]*(((g[j]*f[i-j]))%MOD))%MOD;
            if(g[i] < 0) g[i] += MOD;
        }
        for(int j = 1; j <= i; j++){
            h[i] += (combo[i-1][j-1]*((g[j]*((h[i-j]+f[i-j])%MOD)%MOD)))%MOD;
            if(h[i] >= MOD) h[i] -= MOD;
        }
    }
    cout << h[N] << '\n';
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
