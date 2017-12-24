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
#define INF 1000000000000000000
#define MOD 1000000007

int N, K, colors [100010];
vector<int> adjacency [100010];
long long dp [100010][3], ret;

long long solveIt(int curr, int prevy, int color){
    if(dp[curr][color] != -1) return dp[curr][color];
    dp[curr][color] = 1;
    for(int nexty : adjacency[curr]){
        if(nexty == prevy) continue;
        long long mult = 0;
        if(colors[nexty] == 3){
            for(int i = 0; i < 3; i++)
                if(i != color)
                    mult = (mult+solveIt(nexty, curr, i))%MOD;
        }
        else if(colors[nexty] != color) mult = solveIt(nexty, curr, colors[nexty]);
        dp[curr][color] = (dp[curr][color]*mult)%MOD;
    }
    return dp[curr][color];
}

int main(){
    freopen("barnpainting.in", "r", stdin); freopen("barnpainting.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K; fill(colors, colors+100010, 3); memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    for(int i = 0; i < K; i++){
        int a, b; cin >> a >> b; b--;
        colors[a] = b;
    }
    if(colors[1] == 3) ret = ((solveIt(1, 0, 0)+solveIt(1, 0, 1))%MOD+solveIt(1, 0, 2))%MOD;
    else ret = solveIt(1, 0, colors[1]);
    cout << ret << '\n';
    return 0;
}
