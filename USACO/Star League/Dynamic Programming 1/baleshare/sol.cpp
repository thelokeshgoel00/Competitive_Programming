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

int N, summy = 0, ret = 810;
bool dp [2][810][810];

int main(){
    //freopen("grassplant.in", "r", stdin); freopen("grassplant.out", "w", stdout);
    scanf("%d", &N); memset(dp, false, sizeof(dp)); dp[0][0][0] = true;
    for(int b = 0; b < N; b++){
        int val; scanf("%d", &val); summy += val;
        for(int i = 0; i < 810; i++)
            for(int j = 0; j < 810; j++){
                if(!dp[b%2][i][j]) continue;
                dp[(b+1)%2][i][j] = true;
                if(i+val < 810) dp[(b+1)%2][i+val][j] = true;
                if(j+val < 810) dp[(b+1)%2][i][j+val] = true;
            }
    }
    for(int i = 0; i < 810; i++)
        for(int j = 0; j < 810; j++)
            if(dp[N%2][i][j] && summy-i-j < 810)
                ret = min(ret, max(summy-i-j, max(i, j)));
    cout << ret << '\n';
    return 0;
}
