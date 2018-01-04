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

int N, colors [100010];
vector<int> adjacency [100010];
long long dp [100010][2]; // 0 : white :: 1 : black

void dfs(int curr, int prevy){
    dp[curr][0] = 1-colors[curr]; dp[curr][1] = colors[curr];
    long long temp0, temp1;
    for(int nexty : adjacency[curr]){
        if(nexty == prevy) continue;
        dfs(nexty, curr);
        temp0 = dp[curr][0]; temp1 = dp[curr][1];
        dp[curr][0] = (temp0*(dp[nexty][0]+dp[nexty][1])%MOD)%MOD;
        dp[curr][1] = ((temp0*dp[nexty][1])%MOD+(temp1*(dp[nexty][0]+dp[nexty][1])%MOD)%MOD)%MOD;
    }
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 1; i < N; i++){
        int x; cin >> x;
        adjacency[i].push_back(x); adjacency[x].push_back(i);
    }
    for(int i = 0; i < N; i++) cin >> colors[i];
    dfs(0, -1); cout << dp[0][1] << '\n';
    return 0;
}

// https://abitofcs.blogspot.in/2014/12/dynamic-programming-on-tree-forming-up.html
