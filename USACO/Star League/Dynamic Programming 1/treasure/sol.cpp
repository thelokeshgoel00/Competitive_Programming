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

int N, vals [5010], dp [5010][5010];
int main(){
    //freopen("grassplant.in", "r", stdin); freopen("grassplant.out", "w", stdout);
    scanf("%d", &N); scanf("%d", &vals[0]); dp[0][0] = vals[0];
    for(int i = 1; i < N; i++){ scanf("%d", &vals[i]); dp[i][i] = vals[i]; dp[i-1][i] = max(vals[i-1], vals[i]); }
    for(int len = 3; len <= N; len++)
        for(int i = 0; i <= N-len; i++){
            int j = i+len-1;
            dp[i][j] = max(vals[i]+min(dp[i+2][j], dp[i+1][j-1]), vals[j]+min(dp[i+1][j-1], dp[i][j-2]));
        }
    cout << dp[0][N-1] << '\n';
    return 0;
}

/*
Space Saving Trick by Neal Wu

#include <cstdio>
#include <algorithm>
using namespace std;

FILE *in = fopen ("treasure.in", "r"), *out = fopen ("treasure.out", "w");

const int MAXN = 5005;

int N, coins [MAXN], psum [MAXN], dp [MAXN];

int main () {
    fscanf (in, "%d", &N);

    for (int i = 0; i < N; i++) {
        fscanf (in, "%d", coins + i);
        psum [i + 1] = psum [i] + coins [i];
    }

    for (int len = 1; len <= N; len++)
        for (int i = 0; i + len <= N; i++)
            dp [i] = psum [i + len] - psum [i] - min (dp [i], dp [i + 1]);

    fprintf (out, "%d\n", dp [0]);
    return 0;
}
*/
