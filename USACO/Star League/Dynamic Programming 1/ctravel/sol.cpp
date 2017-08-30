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

int N, M, T, sr, sc, er, ec, dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1};
long long dp [20][110][110];
char grid [110][110];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < N && y < M; }

int main(){
    //freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d %d %d", &N, &M, &T);
    for(int i = 0; i < N; i++) scanf("%s", &grid[i]);
    memset(dp[0], 0ll, sizeof(dp[0]));
    scanf("%d %d %d %d", &sr, &sc, &er, &ec); sr--; sc--; er--; ec--;
    dp[0][sr][sc] = 1ll;
    for(int t = 1; t <= T; t++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++){
                if(grid[i][j] == '*') continue;
                for(int k = 0; k < 4; k++){
                    int nr = i+dx[k], nc = j+dy[k];
                    if(inBounds(nr, nc) && grid[nr][nc] != '*') dp[t][i][j] += dp[t-1][nr][nc];
                }
            }
    cout << dp[T][er][ec] << '\n';
    return 0;
}
