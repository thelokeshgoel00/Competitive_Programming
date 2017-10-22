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

int N, K, L, F [1010], D [1010], dp [2][20010], ret;

int main(){
    //freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(true){
        cin >> N >> K >> L;
        if(N == 0 && K == 0 && L == 0) break;
        for(int i = 1; i <= N; i++) cin >> F[i] >> D[i];
        memset(dp, -1, sizeof(dp)); dp[0][0] = 0; ret = 0;
        for(int i = 1; i <= N; i++)
            for(int j = 0; j < 20*i+1; j++){
                int temp1 = -1, temp2 = dp[(i-1)%2][j];
                if(j >= F[i]) temp1 = dp[(i-1)%2][j-F[i]];
                if(temp1 > -1 && temp1+D[i] <= L){
                    dp[i%2][j] = temp1+D[i];
                    if(temp2 > -1) dp[i%2][j] = min(dp[i%2][j], max(temp2-K, 0));
                }
                else if(temp2 > -1) dp[i%2][j] = max(temp2-K, 0);
                if(dp[i%2][j] > -1) ret = max(ret, j);
            }
        cout << ret << '\n';
    }
    return 0;
}
