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

int N, W, weights [20], prevs [1<<20];
pair<int, int> dp [1<<20];
vector<vector<int>> groups;

void findGroups(int mask){
    vector<int> curCows; int remainingWeight = dp[mask].second;
    while(mask > 0){
        curCows.push_back(prevs[mask]+1);
        remainingWeight -= weights[prevs[mask]];
        mask ^= (1<<prevs[mask]);
        if(remainingWeight == 0){
            groups.push_back(curCows);
            curCows.clear();
            remainingWeight = dp[mask].second;
        }
    }
}

int main(){
    freopen("skyscraper.in", "r", stdin); freopen("skyscraper.out", "w", stdout);
    scanf("%d %d", &N, &W);
    for(int i = 0; i < N; i++) scanf("%d", &weights[i]);
    dp[0] = make_pair(1, 0);
    for(int mask = 1; mask < (1<<N); mask++){
        dp[mask].first = dp[mask].second = 100;
        for(int i = 0; i < N; i++){
            if((mask&(1<<i)) == 0) continue;
            pair<int, int> next = dp[mask^(1<<i)];
            if(next.second+weights[i] > W){
                next.first++;
                next.second = weights[i];
            }
            else next.second += weights[i];
            if(dp[mask] > next){ dp[mask] = next; prevs[mask] = i; }
        }
    }
    printf("%d\n", dp[(1<<N)-1].first);
    findGroups((1<<N)-1);
    for(int i = 0; i < groups.size(); i++){
        cout << groups[i].size();
        for(int j = 0; j < groups[i].size(); j++) cout << " " << groups[i][j]; 
        cout << '\n';
    }
    return 0;
}
