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
double probWinOver [70][70], roundWin [10][70], profits [10][70], ret = 0.0;

int main(){
    //freopen("subrev.in", "r", stdin); freopen("subrev.out", "w", stdout);
    scanf("%d", &K); N = 1<<K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf("%lf", &probWinOver[i][j]);
            probWinOver[i][j] /= 100.0;
        }
    fill(roundWin[0], roundWin[0]+70, 1.0); fill(profits[0], profits[0]+70, 0.0);
    for(int round = 0; round < K; round++)
        for(int winnie = 0; winnie < N; winnie++){
            roundWin[round+1][winnie] = 0.0; profits[round+1][winnie] = 0.0;
            int start = ((winnie>>round)<<round)^(1<<round);
            int fin = start+(1<<round);
            for(int i = start; i < fin; i++) roundWin[round+1][winnie] += roundWin[round][i]*probWinOver[winnie][i];
            roundWin[round+1][winnie] *= roundWin[round][winnie];
            for(int i = start; i < fin; i++) profits[round+1][winnie] = max(profits[round+1][winnie], profits[round][i]);
            profits[round+1][winnie] += roundWin[round+1][winnie]*(double)(1<<round)+profits[round][winnie];
        }
    for(int i = 0; i < N; i++) ret = max(ret, profits[K][i]);
    printf("%.18lf\n", ret);
    return 0;
}
