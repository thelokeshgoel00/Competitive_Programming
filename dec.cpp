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
#define INF 1000000000000

int N, B, skills [30][30], dp [1<<22];
vector<pair<int, int>> bonuses [30];

int main(){
    freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);
    scanf("%d %d", &N, &B); memset(dp, 0, sizeof(dp));
    for(int i = 0; i < B; i++){
        int k, p, a; scanf("%d %d %d", &k, &p, &a); k--;
        bonuses[k].push_back(make_pair(p, a));
    }
    for(int i = 0; i < 30; i++) sort(bonuses[i].begin(), bonuses[i].end());
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &skills[i][j]);
    for(int mask = 1; mask < (1<<N); mask++){
        int numBits = __builtin_popcount(mask);
        for(int j = 0; j < N; j++){
            if((mask&(1<<j)) == 0) continue;
            dp[mask] = max(dp[mask], dp[mask^(1<<j)]+skills[j][numBits-1]);
        }
        for(int i = 0; i < bonuses[numBits-1].size(); i++){
            if(bonuses[numBits-1][i].first > dp[mask]) break;
            dp[mask] += bonuses[numBits-1][i].second;
        }
    }
    cout << dp[(1<<N)-1] << '\n';
    return 0;
}
