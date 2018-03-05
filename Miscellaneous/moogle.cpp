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
#include <sstream>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int kase, N, C;
double places [210], precomp [210][210], dp [210][210];

double solveIt(int curr, int remaining){
    if(dp[curr][remaining] > -epsilon) return dp[curr][remaining];
    if(remaining == 1) return dp[curr][remaining] = precomp[curr][N-1];
    dp[curr][remaining] = (double)MOD;
    for(int i = curr+1; i < N; i++){
        double test = solveIt(i, remaining-1)+precomp[curr][i];
        dp[curr][remaining] = min(dp[curr][remaining], test);
    }
    return dp[curr][remaining];
}

int main(){
    //freopen("vans.in", "r", stdin); freopen("vans.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N >> C;
        for(int i = 0; i < N; i++) cin >> places[i];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                precomp[i][j] = 0.0; dp[i][j] = -1.0;
                for(int k = i+1; k < j; k++){
                    double predicted = places[i]+(places[j]-places[i])*(double)(k-i)/(double)(j-i);
                    precomp[i][j] += abs(places[k]-predicted);
                }
            }
        cout << solveIt(0, C-1)/(double)N << '\n';
    }
    return 0;
}
