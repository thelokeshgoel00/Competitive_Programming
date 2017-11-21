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

int N, M, K, dp [2][10010];

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M >> K;
    fill(dp[M%2], dp[M%2]+K+1, 1);
    for(int i = M-1; i > 0; i--){
        int preSum = 0;
        for(int j = 0; j <= N; j++){
            preSum = (preSum+dp[(i+1)%2][j])%MOD;
            if(j > K) preSum = (preSum+MOD-dp[(i+1)%2][j-K-1])%MOD;
            dp[i%2][j] = preSum;
        }
    }
    cout << dp[1][N] << '\n';
    return 0;
}
