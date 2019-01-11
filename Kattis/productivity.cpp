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
#include <cstring>
#include <sstream>
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, P, dp [210][210][210];
pair<int, int> workers [210];

int solveIt(int i, int p, int firstToLeave){
    if(i == N || p == 0){
        if(i == N && p == 0 && firstToLeave == 205) return 0;
        else return -2000000000;
    }
    if(firstToLeave == 205) firstToLeave = i;
    if(workers[firstToLeave].second <= workers[i].first) return -2000000000;
    if(dp[i][p][firstToLeave] != -1) return dp[i][p][firstToLeave];
    int nexty = workers[i].second < workers[firstToLeave].second ? i : firstToLeave;
    dp[i][p][firstToLeave] = max(solveIt(i+1, p-1, 205)+workers[nexty].second-workers[i].first,
                                 solveIt(i+1, p-1, firstToLeave)+workers[i].second-workers[i].first);
    dp[i][p][firstToLeave] = max(dp[i][p][firstToLeave], solveIt(i+1, p, nexty));
    return dp[i][p][firstToLeave];
}

int main(){
    //freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> P; memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) cin >> workers[i].first >> workers[i].second;
    sort(workers, workers+N);
    cout << solveIt(0, P, 205) << '\n';
    return 0;
}
