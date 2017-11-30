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

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

long long factorial [1000010], modInverse [1000010], inverseFactorial [1000010];
string a, b;

long long fastPow(long long x, int pow){
    long long prod = 1;
    while(pow > 0){
        if(pow%2 == 1) prod = (prod*x)%MOD;
        x = (x*x)%MOD; pow /= 2;
    }
    return prod;
}

long long solveIt(string s, string upper){
    int freq [26], curr = factorial[s.length()], ret = 0; memset(freq, 0, sizeof(freq));
    for(int i = 0; i < s.length(); i++) freq[s[i]-'a']++;
    for(int i = 0; i < 26; i++) curr = (curr*inverseFactorial[freq[i]])%MOD;
    for(int i = 0; i < upper.length(); i++){
        for(int j = 0; j < upper[i]-'a'; j++){
            if(freq[j] == 0) continue;
            long long add = ((curr*modInverse[s.length()-i])%MOD*(long long)freq[j])%MOD;
            ret = (ret+add)%MOD;
        }
        if(freq[upper[i]-'a'] == 0) break;
        curr = ((curr*modInverse[upper.length()-i])%MOD*(long long)freq[upper[i]-'a'])%MOD;
        freq[upper[i]-'a']--;
    }
    return ret;
}

int main(){
    //freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> a >> b;
    factorial[0] = inverseFactorial[0] = 1;
    for(int i = 1; i < 1000010; i++){
        factorial[i] = ((long long)i*factorial[i-1])%MOD;
        modInverse[i] = fastPow((long long)i, MOD-2);
        inverseFactorial[i] = (modInverse[i]*inverseFactorial[i-1])%MOD;
    }
    cout << ((solveIt(a, b)-solveIt(a, a)+MOD)%MOD-1+MOD)%MOD << '\n';
    return 0;
}
