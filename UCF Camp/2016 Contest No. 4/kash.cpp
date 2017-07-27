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

int d, vals [101], costs [101], dp [101][101], ret = 0;

int main(){
    cin >> d; memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= d; i++) cin >> costs[i] >> vals[i];
    for(int i = 1; i <= d; i++)
        for(int j = costs[i]; j <= i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-costs[i]]+vals[i]);
            ret = max(ret, dp[i][j]);
        }
    cout << ret << '\n';
    return 0;
}
