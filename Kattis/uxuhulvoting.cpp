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

int kase, N, prefs [110][10], dp [110][10];
string ret [] = {"NNN", "NNY", "NYN", "NYY", "YNN", "YNY", "YYN", "YYY"};

int solveIt(int curPerson, int mask){
    if(dp[curPerson][mask] != -1) return dp[curPerson][mask];
    if(curPerson == N) return dp[curPerson][mask] = mask;
    int best = -1;
    for(int i = 0; i < 3; i++){
        int nmask = (mask^(1<<i)), nexty = solveIt(curPerson+1, nmask);
        if(best == -1 || prefs[curPerson][best] > prefs[curPerson][nexty]) best = nexty;
    }
    return dp[curPerson][mask] = best;
}

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; memset(dp, -1, sizeof(dp));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 8; j++)
                cin >> prefs[i][j];
        cout << ret[solveIt(0, 0)] << '\n';
    }
    return 0;
}
