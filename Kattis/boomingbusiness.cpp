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

int W, H;
long long dp [310][310];

long long solveIt(int w, int h){
    if(dp[w][h] != -1) return dp[w][h];
    if(w == 1) return dp[w][h] = (h > 0);
    if(h == 0) return dp[w][h] = (w == 0);
    dp[w][h] = 0;
    for(int i = 1; i < w; i++)
        dp[w][h] = (dp[w][h]+(solveIt(i, h-1)*solveIt(w-i, h))%MOD)%MOD;
    return dp[w][h];
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> H >> W; memset(dp, -1, sizeof(dp));
    cout << (solveIt(W, H)-solveIt(W, H-1)+MOD)%MOD << '\n';
    return 0;
}
