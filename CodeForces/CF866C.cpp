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

int N, R, F [60], S [60];
double P [60], lo = 0.0, hi = INF, dp [60][5010];

bool checkIt(double mid){
    for(int i = N-1; i > -1; i--)
        for(int j = 0; j <= R; j++){
            double val = 0.0;
            if(j+F[i] <= R) val += (dp[i+1][j+F[i]]+(double)F[i])*P[i];
            else val += (mid+(double)F[i])*P[i];
            if(j+S[i] <= R) val += (dp[i+1][j+S[i]]+(double)S[i])*(1.0-P[i]);
            else val += (mid+(double)S[i])*(1.0-P[i]);
            dp[i][j] = min(mid, val);
        }
    return dp[0][0] < mid;
}

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> R; memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++){ cin >> F[i] >> S[i] >> P[i]; P[i] /= 100.0; }
    for(int i = 0; i < 100; i++){
        double mid = (lo+hi)/2.0;
        if(checkIt(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
    return 0;
}
