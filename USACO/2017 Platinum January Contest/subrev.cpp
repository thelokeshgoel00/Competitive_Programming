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

int N, arr[60], dp [60][60][60][60];

int recurse(int i, int j, int mini, int maxi){
    if(dp[i][j][mini][maxi] != -1) return dp[i][j][mini][maxi];
    if(mini > maxi) return dp[i][j][mini][maxi] = -1000;
    if(i > j) return dp[i][j][mini][maxi] = 0;
    if(i == j) return dp[i][j][mini][maxi] = arr[i] >= mini && arr[i] <= maxi ? 1 : 0;
    dp[i][j][mini][maxi] = max(0, recurse(i+1, j-1, mini, maxi));
    if(arr[j] >= mini) dp[i][j][mini][maxi] = max(dp[i][j][mini][maxi], recurse(i+1, j-1, arr[j], maxi)+1);
    if(arr[i] <= maxi) dp[i][j][mini][maxi] = max(dp[i][j][mini][maxi], recurse(i+1, j-1, mini, arr[i])+1);
    if(arr[i] >= arr[j] && arr[i] <= maxi && arr[j] >= mini) dp[i][j][mini][maxi] = max(dp[i][j][mini][maxi], recurse(i+1, j-1, arr[j], arr[i])+2);
    dp[i][j][mini][maxi] = max(dp[i][j][mini][maxi], max(recurse(i+1, j, mini, maxi), recurse(i, j-1, mini, maxi)));
    if(arr[i] >= mini) dp[i][j][mini][maxi] = max(dp[i][j][mini][maxi], recurse(i+1, j, arr[i], maxi)+1);
    if(arr[j] <= maxi) dp[i][j][mini][maxi] = max(dp[i][j][mini][maxi], recurse(i, j-1, mini, arr[j])+1);
    return dp[i][j][mini][maxi];
}

int main(){
    freopen("subrev.in", "r", stdin); freopen("subrev.out", "w", stdout);
    scanf("%d", &N); memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    cout << recurse(0, N-1, 0, 50) << '\n';
    return 0;
}
