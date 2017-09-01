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

int N, M, dist [10010], dp [10010][510];

int recurse(int tiempo, int tired){
    if(tiempo > N) return -20000000;
    if(dp[tiempo][tired] != -1) return dp[tiempo][tired];
    if(tiempo == N){
        if(tired == 0) return dp[tiempo][tired] = 0;
        return dp[tiempo][tired] = -20000000;
    }
    dp[tiempo][tired] = -20000000;
    if(tired < M) dp[tiempo][tired] = max(dp[tiempo][tired], recurse(tiempo+1, tired+1)+dist[tiempo]);
    dp[tiempo][tired] = max(dp[tiempo][tired], recurse(tiempo+max(1, tired), 0));
    return dp[tiempo][tired];
}

int main(){
    //freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d %d", &N, &M); memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) scanf("%d", &dist[i]);
    cout << recurse(0, 0) << '\n';
    return 0;
}
