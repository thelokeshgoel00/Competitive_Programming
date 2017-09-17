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

int F, V, dp [110][110];

int main(){
    //freopen("subrev.in", "r", stdin); freopen("subrev.out", "w", stdout);
    scanf("%d %d", &F, &V); memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= F; i++)
        for(int j = 1; j <= V; j++){
            int val; scanf("%d", &val); val += 60;
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+val);
        }
    cout << dp[F][V]-60*F << '\n';
    return 0;
}
