#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001

int N, K, dp [100010][25];
vector<int> adjacency [100010];

int main() {
    freopen("nearcows.in", "r", stdin); freopen("nearcows.out", "w", stdout);
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N-1; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++){
        scanf("%d", &dp[i][0]); dp[i][1] += dp[i][0];
        for(int j : adjacency[i]) dp[j][1] += dp[i][0];
    }
    for(int radius = 2; radius <= K; radius++)
        for(int i = 1; i <= N; i++){
            for(int j : adjacency[i]) dp[i][radius] += dp[j][radius-1];
            dp[i][radius] -= (adjacency[i].size()-1)*dp[i][radius-2];
        }
    for(int i = 1; i <= N; i++) printf("%d\n", dp[i][K]);
    return 0;
}
