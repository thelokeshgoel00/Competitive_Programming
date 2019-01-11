#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
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

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, T, breakTimes [510], dp [510][5010], groupID [510];

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> T >> N; memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
    for(int i = 1; i <= N; i++){
        cin >> breakTimes[i];
        for(int j = 0; j <= T; j++){
            if(dp[i-1][j] > 0) dp[i][j] = 1;
            if(j >= breakTimes[i] && dp[i-1][j-breakTimes[i]] > 0) dp[i][j] = 2;
        }
    }
    while(dp[N][T] == 0) T--;
    for(int i = N; i > 0; i--){
        groupID[i] = dp[i][T];
        if(groupID[i] == 2) T -= breakTimes[i];
    }
    for(int i = 1, sum1 = 0, sum2 = 0; i <= N; i++){
        if(groupID[i] == 1){
            cout << sum1;
            sum1 += breakTimes[i];
        }
        else{
            cout << sum2;
            sum2 += breakTimes[i];
        }
        if(i != N) cout << ' ';
        else cout << '\n';
    }
    return 0;
}
