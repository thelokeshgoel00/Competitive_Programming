#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>

using namespace std;

int n, m, dp [210][2010];
double ret = 0;

int main(){
    cin >> n >> m; memset(dp, -1, sizeof(dp)); dp[0][0] = 0;
    for(int x = 0; x < m; x++){
        int q, s; cin >> q >> s;
        for(int i = n; i > 0; i--)
            for(int j = s; j < 10*n+1; j++){
                if(dp[i-1][j-s] == -1) continue;
                if(dp[i][j] == -1) dp[i][j] = dp[i-1][j-s]+q;
                else dp[i][j] = max(dp[i][j], dp[i-1][j-s]+q);
            }
    }
    for(int i = 0; i < 10*n+1; i++)
        if(dp[n][i] != -1)
            ret = max(ret, (double)((100+i)*(100+dp[n][i]))/10000.0);
    printf("%.5lf\n", ret);
    return 0;
}
