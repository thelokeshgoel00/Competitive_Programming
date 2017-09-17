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
#define INF 1000000000000000000
#define MOD 1000000007

int N, V, dp [2][100010], consolePrice, numGames, gamePrice, gameValue;

int main(){
    //freopen("subrev.in", "r", stdin); freopen("subrev.out", "w", stdout);
    scanf("%d %d", &N, &V); memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++){
        scanf("%d %d", &consolePrice, &numGames);
        for(int j = consolePrice; j <= V; j++) dp[i%2][j] = dp[(i-1)%2][j-consolePrice];
        for(int k = 0; k < numGames; k++){
            scanf("%d %d", &gamePrice, &gameValue);
            for(int j = V; j >= gamePrice+consolePrice; j--) dp[i%2][j] = max(dp[i%2][j], dp[i%2][j-gamePrice]+gameValue);
        }
        for(int j = 0; j <= V; j++) dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j]);
    }
    cout << dp[N%2][V] << '\n';
    return 0;
}
