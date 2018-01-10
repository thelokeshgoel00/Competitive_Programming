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

int N, K;
long long dp [710][710], ret = -INF;

int main(){
    //freopen("mowing.in", "r", stdin); freopen("mowing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K; memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= i; j++){
            cin >> dp[i][j];
            dp[i][j] += dp[i][j-1];
        }
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= i; j++){
            long long sum = 0, elements = 0;
            for(int k = 1; k <= 2*K; k++){
                if(i+(k-1) > N) break;
                sum += dp[i+(k-1)][j+(k-1)]-dp[i+(k-1)][j-1]; elements += k;
                if(k >= K) ret = max(ret, sum/elements);
            }
            sum = elements = 0;
            for(int k = 1; k <= 2*K; k++){
                if(i-(k-1) < 1 || j-(k-1) < 1 || j > i-(k-1)) break;
                sum += dp[i-(k-1)][j]-dp[i-(k-1)][j-k]; elements += k;
                if(k >= K) ret = max(ret, sum/elements);
            }
        }
    cout << ret << '\n';
    return 0;
}
