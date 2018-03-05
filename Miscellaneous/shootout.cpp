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

int kase, N;
double probs [13], dp [13][1<<13][13];
vector<int> targets [13][1<<13];

void resetIt(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < (1<<N); j++)
            fill(dp[i][j], dp[i][j]+N, -1.0);
}

double solveIt(int curr, int mask, int winner);

void findTargets(int curr, int mask){
    if(targets[curr][mask].size() > 0) return;
    double best = 0.0;
    for(int i = 0; i < N; i++){
        if((mask&(1<<i)) == 0 || i == curr) continue;
        double p = solveIt((curr+1)%N, mask^(1<<i), curr);
        if(p > best+epsilon) targets[curr][mask].clear();
        if(p > best-epsilon) targets[curr][mask].push_back(i);
        best = max(best, p);
    }
}

double solveIt(int curr, int mask, int winner){
    if(dp[curr][mask][winner] > -epsilon) return dp[curr][mask][winner];
    if((mask&(1<<winner)) == 0) return dp[curr][mask][winner] = 0.0;
    if(mask == (1<<winner)) return dp[curr][mask][winner] = 1.0;
    double maskProd = 1.0; dp[curr][mask][winner] = 0.0;
    for(int i = 0; i < N; i++){
        int shooter = (curr+i)%N;
        if((mask&(1<<shooter)) == 0) continue;
        findTargets(shooter, mask);
        for(int target : targets[shooter][mask])
            dp[curr][mask][winner] += maskProd*probs[shooter]*
            solveIt((shooter+1)%N, mask^(1<<target), winner)/(double)targets[shooter][mask].size();
        maskProd *= (1-probs[shooter]);
    }
    dp[curr][mask][winner] /= (1-maskProd);
    return dp[curr][mask][winner];
}

int main(){
    //freopen("vans.in", "r", stdin); freopen("vans.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N;
        for(int i = 0; i < N; i++){ 
            cin >> probs[i]; probs[i] /= 100.0; 
            for(int j = 0; j < (1<<N); j++) targets[i][j] = vector<int>();
        }
        for(int i = 0; i < N; i++){
            resetIt();
            cout << 100.0*solveIt(0, (1<<N)-1, i) << (i < N-1 ? ' ' : '\n');
        }
    }
    return 0;
}
