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

int numMovies, tiempo, lengths [23], numShowings [23], dp [1<<23], ret = 23;
vector<int> startTimes [23];

int main(){
    freopen("movie.in", "r", stdin); freopen("movie.out", "w", stdout);
    scanf("%d %d", &numMovies, &tiempo);
    for(int i = 0; i < numMovies; i++){
        cin >> lengths[i] >> numShowings[i];
        for(int j = 0; j < numShowings[i]; j++){
            int x; cin >> x;
            startTimes[i].push_back(x);
        }
    }
    memset(dp, -1, sizeof(dp)); dp[0] = 0;
    for(int mask = 0; mask < (1<<numMovies); mask++){
        if(dp[mask] == -1) continue;
        if(dp[mask] >= tiempo){ ret = min(ret, __builtin_popcount(mask)); continue; }
        for(int i = 0; i < numMovies; i++){
            if((mask&(1<<i)) > 0) continue;
            auto it = upper_bound(startTimes[i].begin(), startTimes[i].end(), dp[mask]);
            if(it != startTimes[i].begin()) it--;
            else continue;
            dp[mask|(1<<i)] = max(dp[mask|(1<<i)], *it+lengths[i]);
        }
    }
    if(ret == 23) ret = -1;
    cout << ret << '\n';
    return 0;
}
