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

int N, C, heights [100010], dp [2][101], ret = 2e9;

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> C;
    for(int i = 0; i < N; i++) cin >> heights[i];
    for(int j = 0; j < 101; j++){
        dp[0][j] = 2e9;
        if(j >= heights[0]) dp[0][j] = (j-heights[0])*(j-heights[0]);
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < heights[i]; j++) dp[i%2][j] = 2e9;
        int mini = 2e9;
        for(int j = 0; j < 101; j++){
            mini = min(mini, dp[(i-1)%2][j]-j*C);
            if(j >= heights[i]) dp[i%2][j] = (j-heights[i])*(j-heights[i])+mini+j*C;
        }
        mini = 2e9;
        for(int j = 100; j >= heights[i]; j--){
            mini = min(mini, dp[(i-1)%2][j]+j*C);
            dp[i%2][j] = min(dp[i%2][j], (j-heights[i])*(j-heights[i])+mini-j*C);
        }
    }
    for(int j = 0; j < 101; j++) ret = min(ret, dp[(N-1)%2][j]);
    cout << ret << '\n';
    return 0;
}
