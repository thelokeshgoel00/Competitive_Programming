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

int N, K, dp [5010];
long long heights [5010];

int main(){
    //freopen("subrev.in", "r", stdin); freopen("subrev.out", "w", stdout);
    scanf("%d %d", &N, &K);
    fill(dp, dp+5010, 10000); dp[0] = 1;
    for(int i = 0; i < N; i++) scanf("%lld", &heights[i]);
    for(int i = 0; i < N; i++){
        int best = 0;
        for(int stretchy = 1; i+stretchy < N && stretchy <= K; stretchy++)
            if((heights[i+stretchy]-heights[i])*best >= (heights[i+best]-heights[i])*stretchy){
                best = stretchy;
                dp[i+stretchy] = min(dp[i+stretchy], dp[i]+1);
            }
    }
    cout << dp[N-1] << '\n';
    return 0;
}
