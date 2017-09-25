#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, cowPos [1010], dp [2][1010][2];

int main(){
    freopen("cowrun.in", "r", stdin); freopen("cowrun.out", "w", stdout);
    scanf("%d", &N); cowPos[1] = 0; N++;
    memset(dp[0], 63, sizeof(dp[0]));
    for(int i = 2; i <= N; i++) scanf("%d", &cowPos[i]);
    sort(cowPos+1, cowPos+N+1);
    for(int i = 1; i <= N; i++)
        if(cowPos[i] == 0)
            dp[0][i][0] = 0;
    for(int len = 1; len < N; len++){
        memset(dp[len%2], 63, sizeof(dp[len%2]));
        for(int i = 1; i+len <= N+1; i++){
            dp[len%2][i-1][0] = min(dp[len%2][i-1][0], min(dp[(len-1)%2][i][0]+(N-len)*(cowPos[i]-cowPos[i-1]),
                                                           dp[(len-1)%2][i][1]+(N-len)*(cowPos[i+len-1]-cowPos[i-1])));
            dp[len%2][i][1] = min(dp[len%2][i][1], min(dp[(len-1)%2][i][0]+(N-len)*(cowPos[i+len]-cowPos[i]),
                                                           dp[(len-1)%2][i][1]+(N-len)*(cowPos[i+len]-cowPos[i+len-1])));
        }
    }
    cout << min(dp[(N-1)%2][1][0], dp[(N-1)%2][1][1]) << '\n';
    return 0;
}
