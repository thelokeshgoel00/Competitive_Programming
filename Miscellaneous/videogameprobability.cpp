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

int kase, g, numAttempt, indexer;
double dp [2510][10010], prob [2510], ret;

int main(){
    //freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d", &kase);
    for(int kk = 1; kk <= kase; kk++){
        scanf("%d", &g); indexer = 0; ret = 0.0;
        memset(dp, 0, sizeof(dp)); dp[0][0] = 1.0;
        for(int i = 0; i < g; i++){
            int num; double p; scanf("%d %lf", &num, &p);
            while(num > 0){
                prob[indexer] = p;
                indexer++; num--;
            }
        }
        scanf("%d", &numAttempt);
        for(int i = 0; i < indexer; i++)
            for(int j = 0; j < numAttempt; j++){
                dp[i+1][j+1] += dp[i][j]*prob[i];
                dp[i][j+1] += dp[i][j]*(1.0-prob[i]);
            }
        for(int i = 0; i <= numAttempt; i++) ret += dp[indexer][i];
        printf("%.3lf\n", ret);
    }
    return 0;
}
