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

int d, dp [101][101], ret = 0;

int main(){
    cin >> d; memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= d; i++){
        int cost, val; cin >> cost >> val;
        for(int j = 0; j <= i; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= cost) dp[i][j] = max(dp[i][j], dp[i-1][j-cost]+val);
            ret = max(ret, dp[i][j]);
        }
    }
    cout << ret << '\n';
    return 0;
}
