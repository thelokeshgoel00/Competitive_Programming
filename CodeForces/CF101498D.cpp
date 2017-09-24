#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int kase, a, b;
long long factorials [100010];

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

long long combo(int a, int b){ return (((factorials[a]*modInverse(factorials[a-b], MOD))%MOD)*modInverse(factorials[b], MOD))%MOD; }

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d", &kase);
    factorials[0] = factorials[1] = 1ll;
    for(int i = 2; i < 100010; i++) factorials[i] = (factorials[i-1]*(long long)i)%MOD;
    for(int kk = 1; kk <= kase; kk++){
        scanf("%d %d", &a, &b);
        printf("%I64d\n", (2ll*combo(a-1, b))%MOD);
    }
    return 0;
}
