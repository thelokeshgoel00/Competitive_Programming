#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define INF 1000000000

int N, M, sizes [10], dp [11][10001];

int main(){
    //freopen("tilechng.in", "r", stdin); freopen("tilechng.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%d", &sizes[i]);
    for(int i = 1; i <= M; i++) dp[0][i] = INF;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j <= M; j++){
            dp[i][j] = INF;
            for(int k = 0; k*k <= j; k++)
                dp[i][j] = min(dp[i][j], dp[i-1][j-k*k]+(sizes[i-1]-k)*(sizes[i-1]-k));
        }
    if(dp[N][M] == INF) cout << -1 << endl;
    else cout << dp[N][M] << endl;
    return 0;
}
