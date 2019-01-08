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
 
int H, W, N;
pair<int, int> locs [3010];
long long f [200010], dp [3010];
 
long long fastExpo(long long b, long long e){
    if(e == 0) return 1;
    long long meme = fastExpo(b, e/2);
    meme *= meme; meme %= MOD;
    if(e%2){ meme *= b; meme %= MOD; }
    return meme;
}
 
long long wombo(int x, int y){ return (f[x+y]*fastExpo((f[x]*f[y])%MOD, MOD-2))%MOD; }
 
int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> H >> W >> N; f[0] = 1;
    for(int i = 1; i <= H+W; i++) f[i] = (f[i-1]*(long long)i)%MOD;
    for(int i = 0; i < N; i++) cin >> locs[i].f >> locs[i].s;
    sort(locs, locs+N); locs[N++] = mp(H, W);
    for(int i = 0; i < N; i++){
        dp[i] = wombo(locs[i].f-1, locs[i].s-1);
        for(int j = 0; j < i; j++)
            if(locs[j].f <= locs[i].f && locs[j].s <= locs[i].s){
                dp[i] -= (wombo(locs[i].f-locs[j].f, locs[i].s-locs[j].s)*dp[j])%MOD;
                dp[i] = (dp[i]+MOD)%MOD;
            }
    }
    cout << dp[N-1] << '\n';
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
