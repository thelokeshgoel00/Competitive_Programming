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

int N;
long long vals [700010], dp [700010][2];

int main(){
    //freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%lld", &vals[i]);
    dp[N][0] = dp[N][1] = 0ll;
    for(int i = N-1; i > -1; i--){
        if(dp[i+1][1]+vals[i] >= dp[i+1][0]){
            dp[i][0] = dp[i+1][1]+vals[i];
            dp[i][1] = dp[i+1][0];
        }
        else{
            dp[i][0] = dp[i+1][0];
            dp[i][1] = dp[i+1][1];
        }
    }
    //cout << dp[0][0] << " " << dp[0][1] << endl;
    printf("%lld %lld\n", dp[0][0], dp[0][1]);
    return 0;
}
