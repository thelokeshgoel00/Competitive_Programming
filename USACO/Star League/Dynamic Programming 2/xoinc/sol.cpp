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

int N, arr [2010], cumSum = 0, dp [2010][2010];

int main(){
    //freopen("fcount.in", "r", stdin); freopen("fcount.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++) cin >> arr[N-i+1];
    for(int i = 1; i <= N; i++){
        cumSum += arr[i];
        for(int j = 1; j <= N; j++){
            dp[i][j] = dp[i][j-1];
            if(i >= 2*j-1){
                dp[i][j] = max(dp[i][j], cumSum-dp[i-(2*j-1)][2*j-1]);
                if(i >= 2*j) dp[i][j] = max(dp[i][j], cumSum-dp[i-2*j][2*j]);
            }
        }
    }
    cout << dp[N][1] << '\n';
    return 0;
}
