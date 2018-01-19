/*
ID: vamaddu1
PROG: vans
LANG: C++11
*/


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
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

struct BigInteger{
    int digits [1010];
    BigInteger(){ for(int i = 0; i < 1010; i++) digits[i] = 0; }
    BigInteger(int x){ for(int i = 1000; i > -1; i--){ digits[i] = x%10; x /= 10;  } }
    BigInteger operator+(const BigInteger &other) const{
        BigInteger ret; int carry = 0;
        for(int i = 1000; i > -1; i--){
            ret.digits[i] = digits[i]+other.digits[i]+carry; carry = 0;
            if(ret.digits[i] > 9){ ret.digits[i] -= 10; carry = 1; }
        }
        return ret;
    }
};

int N;
BigInteger f [1010], g [1010], h [1010];

void printIt(BigInteger b){
    bool nz = false;
    for(int i = 0; i < 1001; i++){
        nz |= b.digits[i] != 0;
        if(nz) cout << b.digits[i];
    }
    if(!nz) cout << '0';
    cout << '\n';
}

int main(){
    freopen("vans.in", "r", stdin); freopen("vans.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    f[1] = BigInteger(0); f[2] = BigInteger(2); f[3] = BigInteger(4);
    g[1] = BigInteger(2); g[2] = BigInteger(2); g[3] = BigInteger(8);
    h[1] = BigInteger(2); h[2] = BigInteger(2); h[3] = BigInteger(2);
    for(int i = 4; i <= N; i++){
        f[i] = f[i-1]+g[i-1];
        h[i] = f[i-2]+f[i-2]+h[i-1];
        g[i] = f[i-1]+f[i-1]+g[i-2]+h[i];
    }
    printIt(f[N]);
    return 0;
}
