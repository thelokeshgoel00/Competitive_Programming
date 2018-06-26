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
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N;
vector<int> children [100010];
long long D, dp [3010][3010], pascal [3010], vals [3010], mult = 1, ret = 0;

long long modPow(long long x, long long y){
    if(y == 0) return 1;
    long long prod = modPow(x, y/2);
    prod *= prod; prod %= MOD;
    if(y%2 == 1){ prod *= x; prod %= MOD; }
    return prod;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> D; memset(dp, 0, sizeof(dp)); memset(pascal, 0, sizeof(pascal));
    for(int i = 2; i <= N; i++){
        int x; cin >> x;
        children[x].push_back(i);
    }
    for(int i = N; i >= 1; i--)
        for(int j = 1; j <= N; j++){
            dp[i][j] = 1;
            for(int nexty : children[i]) dp[i][j] = (dp[i][j]*dp[nexty][j])%MOD;
            dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
        }
    pascal[0] = 1;
    for(int i = 1; i <= N; i++){
        long long add = dp[1][i];
        for(int j = i ; j >= 1; j--) pascal[j] = (pascal[j]+pascal[j-1])%MOD;
        for(int j = 1; j < i; j++) add = (add-(vals[i-j]*pascal[j])%MOD+MOD)%MOD;
        mult = (mult*(D-(i-1)))%MOD; mult = (mult*modPow((long long)i, MOD-2))%MOD;
        vals[i] = add;
        ret = (ret+(add*mult)%MOD)%MOD;
    }
    cout << ret << '\n';
    return 0;
}
