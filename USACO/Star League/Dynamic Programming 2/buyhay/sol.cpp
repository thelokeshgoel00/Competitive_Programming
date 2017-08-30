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

int N, H;
long long dp [55010], ret = INF;
pair<int, long long> supplies [110]; //pounds and dollars

int main(){
    //freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d %d", &N, &H); fill(dp, dp+55010, INF); dp[0] = 0ll;
    for(int i = 0; i < N; i++) scanf("%d %lld", &supplies[i].first, &supplies[i].second);
    for(int i = 0; i <= H+5000; i++){
        if(dp[i] == INF) continue;
        if(i >= H){ ret = min(ret, dp[i]); continue; }
        for(int j = 0; j < N; j++) dp[i+supplies[j].first] = min(dp[i+supplies[j].first], dp[i]+supplies[j].second);
    }
    cout << ret << '\n';
    return 0;
}
