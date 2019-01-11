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

using namespace std;

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

int kase;
string a, b;
long long dp [60][40][40][2][2], ret;

bool isGood(string s){
    int x = 0, y = 0, z = 0;
    for(int i = 0; i < s.length(); i++){
        x += s[i] == '3';
        y += s[i] == '6';
        z += s[i] == '9';
    }
    return x == y && y == z && x > 0;
}

long long solveIt(int idx, int diff36, int diff39, int match, int used, string &s){
    long long &ans = dp[idx][diff36][diff39][match][used];
    if(ans != -1) return ans;
    if(idx == s.length()){
        if(diff36 == 20 && diff39 == 20 && used) ans = 1;
        else ans = 0;
        return ans;
    }
    ans = 0;
    if(max(abs(diff36-20), abs(diff39-20)) > s.length()-idx) return ans;
    for(int i = 0; i < 10; i++){
        if(match && i > s[idx]-'0') break;
        int nmatch = match && (i == s[idx]-'0'), nused = 1, n36 = diff36, n39 = diff39;
        if(i == 3){ n36--; n39--; }
        else if(i == 6) n36++;
        else if(i == 9) n39++;
        else nused = 0;
        nused |= used;
        if(n36 > -1 && n39 > -1 && n36 < 40 && n39 < 40)
            ans = (ans+solveIt(idx+1, n36, n39, nmatch, nused, s))%MOD;
    }
    return ans;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(9);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> a >> b;
        memset(dp, -1, sizeof(dp)); ret = solveIt(0, 20, 20, 1, 0, b);
        memset(dp, -1, sizeof(dp)); ret = (ret+MOD-solveIt(0, 20, 20, 1, 0, a))%MOD;
        if(isGood(a)) ret = (ret+1)%MOD;
        cout << ret << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
