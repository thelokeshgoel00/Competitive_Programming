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

int N, H, ret = 0;
bool dp [45010];

int main(){
    //freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d %d", &H, &N); fill(dp, dp+45010, false); dp[0] = true;
    for(int i = 0; i < N; i++){
        int x; scanf("%d", &x);
        for(int j = H; j >= x; j--){
            if(!dp[j-x]) continue;
            dp[j] = true;
            ret = max(ret, j);
        }
    }
    cout << ret << '\n';
    return 0;
}
