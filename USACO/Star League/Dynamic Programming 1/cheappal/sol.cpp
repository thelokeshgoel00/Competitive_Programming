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

int N, M, costs [26], dp [2010][2010];
char s [2010];

int main(){
    //freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d %d %s", &N, &M, &s); fill(costs, costs+26, 200000000);
    for(int i = 0; i < N; i++){
        char c [5]; int x, y; scanf("%s %d %d", &c, &x, &y);
        costs[c[0]-'a'] = min(x, y);
    }
    for(int i = 0; i < M-1; i++){
        dp[i][i] = 0;
        if(s[i] == s[i+1]) dp[i][i+1] = 0;
        else dp[i][i+1] = min(costs[s[i]-'a'], costs[s[i+1]-'a']);
    }
    dp[M-1][M-1] = 0;
    for(int extend = 2; extend < M; extend++)
        for(int i = 0; i < M-extend; i++){
            dp[i][i+extend] = min(dp[i+1][i+extend]+costs[s[i]-'a'], dp[i][i+extend-1]+costs[s[i+extend]-'a']);
            if(s[i] == s[i+extend]) dp[i][i+extend] = min(dp[i][i+extend], dp[i+1][i+extend-1]);
        }
    cout << dp[0][M-1] << '\n';
    return 0;
}
