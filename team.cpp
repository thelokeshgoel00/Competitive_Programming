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

int N, M, K;
pair<int, int> combined [2010]; // Score, OwnedByFP
long long dp [2010][15][15];

int main(){
    freopen("team.in", "r", stdin); freopen("team.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){ cin >> combined[i].first; combined[i].second = 0; }
    for(int i = N; i < N+M; i++){ cin >> combined[i].first; combined[i].second = 1; }
    sort(combined, combined+N+M); memset(dp, 0ll, sizeof(dp));
    dp[N+M][0][0] = 1ll;
    for(int k = N+M-1; k > -1; k--){
        //cout << combined[k].first << " " << combined[k].second << endl;
        for(int i = 0; i <= K; i++){
            for(int j = 0; j <= i; j++){
                dp[k][i][j] = dp[k+1][i][j];
                if(combined[k].second == 0){ if(i > j) dp[k][i][j] = (dp[k][i][j]+dp[k+1][i-1][j])%(MOD+2); }
                else{ if(j > 0) dp[k][i][j] = (dp[k][i][j]+dp[k+1][i][j-1])%(MOD+2); }
                //cout << dp[k][i][j] << " ";
            }
            //cout << endl;
        }
        //cout << endl;
    }
    cout << dp[0][K][K] << '\n';
    return 0;
}
