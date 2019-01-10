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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int kase;
long long n, e, miniMod;

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
    //freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> n >> e;
        for(long long i = 2; i*i < n; i++)
            if(n%i == 0)
                miniMod = (i-1ll)*(n/i-1ll);
        cout << modInverse(e, miniMod) << '\n';
    }
    return 0;
}
