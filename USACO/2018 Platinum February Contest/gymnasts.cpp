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

long long N, temp, ret;
vector<long long> base, power;

long long fastPow(long long x, long long expo){
    if(expo == 0) return 1;
    long long half = fastPow(x, expo/2);
    if(expo%2) return ((half*half)%MOD*x)%MOD;
    else return (half*half)%MOD;
}

void recurseIt(int i, long long num, long long div, long long mult){
    if(i == base.size()){
        if(num == N) return;
        ret = (ret+((fastPow(2, num)*(N/(num*div))%MOD)%MOD*mult)%MOD)%MOD;
        return;
    }
    for(int j = 0; j < power[i]; j++){
        recurseIt(i+1, num, div*base[i], mult*(base[i]-1));
        num *= base[i];
    }
    recurseIt(i+1, num, div, mult);
} 

int main(){
    freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
	  ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
	  cin >> N; temp = N; ret = (MOD-(N-2)%MOD)%MOD;
    for(long long i = 2; i*i <= N; i++){
		    if(N%i != 0) continue;
		    long long po = 0;
		    while(N%i == 0){ N /= i; po++; }
		    base.pb(i); power.pb(po);
	  }
    if(N > 1){ base.pb(N); power.pb(1); }
    N = temp; recurseIt(0, 1, 1, 1);
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
