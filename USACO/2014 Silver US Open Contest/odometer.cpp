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

long long x, y, dp [30][2][50][2];
string a, b;

long long helpItOne(string s, int u, int idx, bool isUnder, int cnt, bool isZero){
    if(dp[idx][isUnder][cnt][isZero] != -1) return dp[idx][isUnder][cnt][isZero];
    if(idx == 25){
        if(cnt <= 25) return dp[idx][isUnder][cnt][isZero] = 1;
        else return dp[idx][isUnder][cnt][isZero] = 0;
    }
    dp[idx][isUnder][cnt][isZero] = 0;
    for(int dig = 0; dig < 10; dig++){
        if(dig > s[idx]-'0' && !isUnder) break;
        bool nZero = dig == 0 && isZero, nUnder = isUnder || dig < s[idx]-'0';
        int ncnt = cnt;
        if(!nZero) ncnt += (dig == u ? -1 : 1);
        dp[idx][isUnder][cnt][isZero] += helpItOne(s, u, idx+1, nUnder, ncnt, nZero);
    }
    return dp[idx][isUnder][cnt][isZero];
}

long long helpItTwo(string s, int u, int v, int idx, bool isUnder, int cnt, bool isZero){
    if(dp[idx][isUnder][cnt][isZero] != -1) return dp[idx][isUnder][cnt][isZero];
    if(idx == 25){
        if(cnt == 25) return dp[idx][isUnder][cnt][isZero] = 1;
        else return dp[idx][isUnder][cnt][isZero] = 0;
    }
    dp[idx][isUnder][cnt][isZero] = 0;
    for(int dig = 0; dig < 10; dig++){
        if(dig > s[idx]-'0' && !isUnder) break;
        if((dig > 0 || !isZero) && dig != u && dig != v) continue;
        bool nZero = dig == 0 && isZero, nUnder = isUnder || dig < s[idx]-'0';
        int ncnt = cnt;
        if(!nZero) ncnt += (dig == u ? -1 : 1);
        dp[idx][isUnder][cnt][isZero] += helpItTwo(s, u, v, idx+1, nUnder, ncnt, nZero);
    }
    return dp[idx][isUnder][cnt][isZero];
}

long long solveIt(string s){
    long long ret = 0;
    for(int i = 0; i < 10; i++){
        memset(dp, -1, sizeof(dp));
        ret += helpItOne(s, i, 0, false, 25, true);
        for(int j = i+1; j < 10; j++){
            memset(dp, -1, sizeof(dp));
            ret -= helpItTwo(s, i, j, 0, false, 25, true);
        }
    }
    return ret;
}

int main(){
    freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> x >> y; x--; a = to_string(x); b = to_string(y);
    while(a.length() < 25) a = '0'+a;
    while(b.length() < 25) b = '0'+b;
    cout << solveIt(b)-solveIt(a) << '\n';
    return 0;
}
