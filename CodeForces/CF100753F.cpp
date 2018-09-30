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

bool isPrime [1000000];
vector<long long> primes;
long long N, ret = 1;

long long multMod(long long a, long long b, long long m){
    long long x = 0, y = a%m;
    while(b > 0){
        if (b%2) x = (x+y)%m;
        y = (y*2)%m;
        b /= 2;
    }
    return x;
}

long long modExpo(long long base, long long expo, long long m){
    long long x = 1, y = base;
    while(expo > 0){
        if(expo%2) x = multMod(x, y, m);
        y = multMod(y, y, m);
        expo = expo/2;
    }
    return x;
}

bool Miller(long long p, int repeats){
    if (p < 2) return false;
    if (p != 2 && p%2 == 0) return false;
    long long s = p-1;
    while(s%2 == 0) s /= 2;
    for(int i = 0; i < repeats; i++){
        long long a = rand()%(p-1)+1, temp = s;
        long long mod = modExpo(a, temp, p);
        while(temp != p-1 && mod != 1 && mod != p-1){
            mod = multMod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p-1 && temp%2 == 0) return false;
    }
    return true;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N; fill(isPrime+2, isPrime+1000000, true);
    for(int i = 2; i < 1000000; i++){
        if(!isPrime[i]) continue;
        primes.pb(i);
        for(int j = 2*i; j < 1000000; j += i) isPrime[j] = false;
    }
    for(int i = 0; i < primes.size(); i++){
        long long p = primes[i];
        if(p*p*p > N) break;
        long long cnt = 1;
        while(N%p == 0){ N /= p; cnt++; }
        ret *= cnt;
    }
    if(Miller(N, 1000)) ret *= 2;
    else{
        long long sq = (long long)sqrt(N);
        while(sq*sq < N) sq++;
        while(sq*sq > N) sq--;
        if(sq*sq == N && Miller(sq, 1000)) ret *= 3;
        else if(N != 1) ret *= 4;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
