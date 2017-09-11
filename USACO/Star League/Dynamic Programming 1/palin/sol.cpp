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
#define INF 1000000000000
#define MOD 1000000007

int N, dp [5010][3];
char s [5010];

int main(){
    //freopen("grassplant.in", "r", stdin); freopen("grassplant.out", "w", stdout);
    scanf("%d %s", &N, &s); dp[0][1] = 0;
    for(int i = 1; i < N; i++){
        dp[i][1] = 0;
        if(s[i-1] == s[i]) dp[i-1][2] = 0;
        else dp[i-1][2] = 1;
    }
    for(int len = 3; len <= N; len++)
        for(int i = 0; i <= N-len; i++){
            int j = i+len-1;
            if(s[i] == s[j]) dp[i][len%3] = dp[i+1][(len-2)%3];
            else dp[i][len%3] = 1+min(dp[i][(len-1)%3], dp[i+1][(len-1)%3]);
        }
    cout << dp[0][N%3] << '\n';
    return 0;
}
