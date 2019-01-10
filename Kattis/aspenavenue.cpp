#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N;
double L, W, oriPos [2010], dp [1010][1010];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> L >> W;
    for(int i = 1; i <= N; i++) cin >> oriPos[i];
    sort(oriPos+1, oriPos+N+1);
    dp[0][0] = 0.0;
    for(int i = 0; i <= N/2; i++)
        for(int j = 0; j <= N/2; j++){
            if(i+j == 0) continue;
            dp[i][j] = INF;
            if(i > 0){
                double leftTemp = dp[i-1][j]+abs(oriPos[i+j]-(double)(i-1)*L/(double)(N/2-1));
                dp[i][j] = min(dp[i][j], leftTemp);
            }
            if(j > 0){
                double rightTemp = dp[i][j-1]+sqrt(pow(oriPos[i+j]-(double)(j-1)*L/(double)(N/2-1), 2.0)+W*W);
                dp[i][j] = min(dp[i][j], rightTemp);
            }
        }
    cout << dp[N/2][N/2] << '\n';
    return 0;
}
