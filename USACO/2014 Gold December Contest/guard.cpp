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

int N;
long long H, heightSum [1<<20], weightSum [1<<20], dp [1<<20], ret = -1;
pair<long long, pair<long long, long long>> cows [20]; //height, weight, strength

int main(){
    freopen("guard.in", "r", stdin); freopen("guard.out", "w", stdout);
    cin >> N >> H;
    for(int i = 0; i < N; i++) cin >> cows[i].first >> cows[i].second.first >> cows[i].second.second;
    for(int mask = 0; mask < (1<<N); mask++){
        heightSum[mask] = 0; weightSum[mask] = 0;
        dp[mask] = -1;
        for(int i = 0; i < N; i++)
            if((mask&(1<<i)) > 0){
                heightSum[mask] += cows[i].first;
                weightSum[mask] += cows[i].second.first;
            }
    }
    for(int i = 0; i < N; i++){
        if(heightSum[1<<i] >= H) ret = max(ret, cows[i].second.second);
        dp[1<<i] = cows[i].second.second;
    }
    for(int mask = 3; mask < (1<<N); mask++){
        if(dp[mask] > -1) continue;
        for(int i = 0; i < N; i++){
            if((mask&(1<<i)) == 0) continue;
            dp[mask] = max(dp[mask], min(dp[mask^(1<<i)], cows[i].second.second-weightSum[mask^(1<<i)]));
        }
        if(heightSum[mask] >= H) ret = max(ret, dp[mask]);
        //cout << dp[mask] << endl;
    }
    if(ret == -1) cout << "Mark is too tall\n";
    else cout << ret << '\n';
    return 0;
}
