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

int N, M, R;
long long vals [40010][2], dp [40010][2], ret = 0ll;
pair<int, int> paths [100010];

int main(){
    freopen("route.in", "r", stdin); freopen("route.out", "w", stdout);
    scanf("%d %d %d", &N, &M, &R);
    for(int i = 0; i < N; i++){ scanf("%lld", &vals[i][0]); dp[i][0] = vals[i][0]; ret = max(ret, dp[i][0]); }
    for(int i = 0; i < M; i++){ scanf("%lld", &vals[i][1]); dp[i][1] = vals[i][1]; ret = max(ret, dp[i][1]); }
    for(int i = 0; i < R; i++) scanf("%d %d", &paths[i].first, &paths[i].second);
    sort(paths, paths+R);
    for(int i = 0; i < R; i++){
        int a = paths[i].first-1, b = paths[i].second-1;
        long long a0 = dp[b][1]+vals[a][0], b1 = dp[a][0]+vals[b][1];
        dp[a][0] = max(dp[a][0], a0);
        dp[b][1] = max(dp[b][1], b1);
        ret = max(ret, max(dp[a][0], dp[b][1]));
    }
    printf("%lld\n", ret);
    return 0;
}
