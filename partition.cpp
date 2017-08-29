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

int n, numWalls, grid [20][20], ret = 1000000, cost [20][20], dp [20][20], cumSum [20];


int main(){
    freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d %d", &n, &numWalls);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);
    for(int mask = 0; mask < (1<<(n-1)); mask++){
        int numBits = __builtin_popcount(mask);
        if(numBits > numWalls) continue;
        for(int i = 0; i < n+1; i++){
            memset(cumSum, 0, sizeof(cumSum));
            for(int k = i+1; k < n+1; k++){
                cost[i][k] = 0;
                int tempSum = 0;
                for(int j = 0; j < n; j++){
                    cumSum[j] += grid[k-1][j]; tempSum += cumSum[j];
                    cost[i][k] = max(cost[i][k], tempSum);
                    if((mask&(1<<j)) > 0) tempSum = 0;
                }
            }
        }
        memset(dp, 1000000, sizeof(dp)); dp[0][0] = 0;
        for(int j = 1; j <= min(n, numWalls-numBits+1); j++){
            for(int i = 0; i < n+1; i++)
                for(int k = i+1; k < n+1; k++)
                    dp[j][k] = min(dp[j][k], max(dp[j-1][i], cost[i][k]));
            ret = min(ret, dp[j][n]);
        }
    }
    cout << ret << '\n';
    return 0;
}
