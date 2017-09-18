#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int T, S, N, slopeIndex = 0, minTimeAtLevel [110], dp [10010][110];
vector<pair<int, int>> classes [10010];
pair<int, int> slopes [10010];

int solveIt(int tiempo, int skillz){
    if(tiempo > T) return 0;
    if(dp[tiempo][skillz] != -1) return dp[tiempo][skillz];
    dp[tiempo][skillz] = solveIt(tiempo+1, skillz);
    if(tiempo+minTimeAtLevel[skillz] <= T) 
        dp[tiempo][skillz] = max(dp[tiempo][skillz], 1+solveIt(tiempo+minTimeAtLevel[skillz], skillz));
    for(pair<int, int> c : classes[tiempo]){
        if(c.second <= skillz) continue;
        dp[tiempo][skillz] = max(dp[tiempo][skillz], solveIt(tiempo+c.first, c.second));
    }
    return dp[tiempo][skillz];
}

int main(){
    //freopen("subrev.in", "r", stdin); freopen("subrev.out", "w", stdout);
    scanf("%d %d %d", &T, &S, &N); memset(dp, -1, sizeof(dp));
    for(int i = 0; i < S; i++){
        int M, L, A; scanf("%d %d %d", &M, &L, &A);
        classes[M].push_back(make_pair(L, A));
    }
    for(int i = 0; i < N; i++) scanf("%d %d", &slopes[i].first, &slopes[i].second);
    sort(slopes, slopes+N);
    minTimeAtLevel[0] = 10010;
    for(int i = 1; i <= 100; i++){
        minTimeAtLevel[i] = minTimeAtLevel[i-1];
        while(slopeIndex < N && slopes[slopeIndex].first == i){
            minTimeAtLevel[i] = min(minTimeAtLevel[i], slopes[slopeIndex].second);
            slopeIndex++;
        }
    }
    cout << solveIt(0, 1) << '\n';
    return 0;
}
