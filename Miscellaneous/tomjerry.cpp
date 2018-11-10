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

int N, M, C;
long long factorial [100010], invfactorial [100010], ret = 0;
pair<int, int> locs [10];

long long choose(int n, int k){
    if(n < k) return 0;
    return ((factorial[n]*invfactorial[n-k])%MOD*invfactorial[k])%MOD;
}

void recurseIt(int curr, int taken, pair<int, int> prevy, long long ways){
    if(curr == C){
        if(taken == 0) return;
        ways *= choose(N-prevy.f+M-prevy.s, N-prevy.f); ways %= MOD;
        if(!(taken%2)) ret = (ret-ways+MOD)%MOD;
        else ret = (ret+ways)%MOD;
        return;
    }
    if(locs[curr].s >= prevy.s){
        long long nways = ways;
        nways *= choose(locs[curr].f-prevy.f+locs[curr].s-prevy.s, locs[curr].f-prevy.f); nways %= MOD;
        recurseIt(curr+1, taken+1, locs[curr], nways);
    }
    recurseIt(curr+1, taken, prevy, ways);
}

long long modInverse(long long a, long long m){ //Assume That a and m are relatively prime to each other
    long long m0 = m, t, q;
    long long x0 = 0ll, x1 = 1ll;
    while(a > 1ll){
        // q is quotient
        q = a/m;
        t = m;
        // m is remainder now, process same as
        // Euclid's Algorithm
        m = a%m, a = t;
        t = x0;
        x0 = x1-q*x0;
        x1 = t;
    }
    // Make x1 positive
    if(x1 < 0) x1 += m0;
    return x1;
}


int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M >> C; factorial[0] = invfactorial[0] = 1;
    for(int i = 1; i <= N+M; i++){
        factorial[i] = i; invfactorial[i] = modInverse(i, MOD);
        factorial[i] *= factorial[i-1]; factorial[i] %= MOD;
        invfactorial[i] *= invfactorial[i-1]; invfactorial[i] %= MOD;
    }
    for(int i = 0; i < C; i++) cin >> locs[i].f >> locs[i].s;
    sort(locs, locs+C); recurseIt(0, 0, mp(1, 1), 1);
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
