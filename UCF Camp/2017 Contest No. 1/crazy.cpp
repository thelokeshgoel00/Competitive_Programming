#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

long long a, b, num, MOD = 1000000000;

void multiply(long long F[2][2], long long M[2][2]){
    long long x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MOD;
    long long y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MOD;
    long long z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MOD;
    long long w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MOD;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(long long F[2][2], long long n){
  if(n == 0 || n == 1) return;
  long long M[2][2] = {{1ll, 1ll}, {1ll, 0ll}};
  power(F, n/2); multiply(F, F);
  if(n%2ll != 0ll) multiply(F, M);
}

long long fib(long long n){
  long long F[2][2] = {{1ll, 1ll}, {1ll, 0ll}};
  if(n == 0ll) return 0ll;
  power(F, n-1ll);
  return F[0][0]%MOD;
}

int main(){
    cin >> a >> b >> num;
    if(num == 0) cout << a << '\n';
    else cout << ((a*fib(num-1))%MOD+(b*fib(num))%MOD)%MOD << '\n';
    return 0;
}
