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

int N, numCoasters = 0, dp [2][25010], Q;

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(dp[0], 0, sizeof(dp[0]));
    for(int i = 0; i < N; i++){
        int a, b, t; cin >> a >> b >> t;
        if(a == 0) continue;
        if(b == 0){
            numCoasters++;
            for(int j = 0; j < 25010; j++){
                dp[numCoasters%2][j] = dp[(numCoasters-1)%2][j];
                if(j >= t) dp[numCoasters%2][j] = max(dp[numCoasters%2][j], dp[numCoasters%2][j-t]+a);
            }
            continue;
        }
        for(int k = 1; k < 35; k++){
            if(a-(k-1)*(k-1)*b <= 0) break;
            int profit = a-(k-1)*(k-1)*b; numCoasters++;
            for(int j = 0; j < 25010; j++){
                dp[numCoasters%2][j] = dp[(numCoasters-1)%2][j];
                if(j >= t) dp[numCoasters%2][j] = max(dp[numCoasters%2][j], dp[(numCoasters-1)%2][j-t]+profit);
            }
        }
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int x; cin >> x;
        cout << dp[numCoasters%2][x] << '\n';
    }
    return 0;
}
