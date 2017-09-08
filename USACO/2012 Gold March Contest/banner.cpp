#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

long long M, N, L, H, B, ret = 0ll;
vector<long long> primeDiv [100010];

// (# of rectangles with length a multiple of prod assuming they can hang off the grid)-
//     (# of rectangles that do hang off the grid with length a multiple of prod)
// Simplified version of (Sum From i = 0 to hi of (M+1-i*prod)) - (Sum From i = 0 to (lo-1) of (M+1-i*prod))

long long calcIt(long long lo, long long hi, long long prod){ 
    hi /= prod;
    lo = (lo+prod-1)/prod;
    return ((hi-lo+1)*(M+1)-prod*(hi*(hi+1)-(lo-1)*lo)/2)%B;
}

int main(){
    freopen("banner.in", "r", stdin); freopen("banner.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &M, &N, &L, &H, &B);
    for(int i = 2; i <= N; i++){
        if(primeDiv[i].size() > 0) continue;
        for(int j = i; j <= N; j += i) primeDiv[j].push_back(i);
    }
    long long lo = L, hi = H;
    for(long long wid = 1; wid <= min(N, H); wid++){
        while(lo > 1 && L*L-wid*wid <= (lo-1)*(lo-1)) lo--;
        while(H*H-wid*wid < hi*hi) hi--;
        if(lo > hi || M < lo) continue;
        long long add = 0ll;
        for(int mask = 0; mask < (1<<primeDiv[wid].size()); mask++){
            int numBits = __builtin_popcount(mask); long long num = 1ll;
            for(int i = 0; i < primeDiv[wid].size(); i++)
                if((mask&(1<<i)) > 0)
                    num *= primeDiv[wid][i];
            if(numBits%2 == 1) add -= calcIt(lo, min(hi, M), num);
            else add += calcIt(lo, min(hi, M), num);
        }
        ret = (ret+add*(N-wid+1))%B;
        if(ret < 0) ret += B;
        //cout << wid << " " << ret << endl;
    }
    ret = (2*ret)%B;
    if(L == 1) ret = (ret+N*(M+1)+M*(N+1))%B;
    cout << ret << '\n';
    return 0;
}
