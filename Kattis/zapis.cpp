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

int N;
string open = "[{(", close = "]})", s;
long long dp [210][210];
bool needZeroes [210][210];
string ret;

long long solveIt(int li, int ri){
    if(dp[li][ri] != -1) return dp[li][ri];
    if(li > ri) return dp[li][ri] = 1;
    dp[li][ri] = 0ll;
    for(int i = li+1; i <= ri; i += 2)
        for(int j = 0; j < 3; j++)
            if(s[li] == open[j] || s[li] == '?')
                if(s[i] == close[j] || s[i] == '?'){
                    if(dp[li][ri]+solveIt(li+1, i-1)*solveIt(i+1, ri) >= 100000) needZeroes[li][ri] = true;
                    dp[li][ri] = (dp[li][ri]+solveIt(li+1, i-1)*solveIt(i+1, ri))%100000;
                }
    return dp[li][ri];
}

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> s; memset(dp, -1, sizeof(dp)); memset(needZeroes, false, sizeof(needZeroes));
    ret = to_string(solveIt(0, N-1));
    if(needZeroes[0][N-1])
      while(ret.length() < 5)
        ret = "0"+ret;
    cout << ret << '\n';
    return 0;
}
