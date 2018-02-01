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
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, K, maxEnd = 0, dp [100010][110][2], leftIndex = 0;
pair<int, int> ori [100010];
set<int> useless;
vector<pair<int, int>> shifts;

int main(){
    freopen("lifeguards.in", "r", stdin); freopen("lifeguards.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K;
    if(N == K){ cout << "0" << '\n'; return 0; }
    for(int i = 0; i < N; i++) cin >> ori[i].first >> ori[i].second;
    sort(ori, ori+N); memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++){
        if(maxEnd > ori[i].second) K--;
        else shifts.push_back(ori[i]);
        maxEnd = max(maxEnd, ori[i].second);
    }
    N = shifts.size(); K = max(K, 0);
    dp[0][0][1] = shifts[0].second-shifts[0].first;
    for(int i = 1; i < N; i++){
        while(shifts[leftIndex].second < shifts[i].first) leftIndex++;
        for(int j = 0; j <= min(i, K); j++){
            dp[i][j][0] = max(dp[i-1][j-1][0], dp[i-1][j-1][1]);
            if(leftIndex == i) dp[i][j][1] = max(dp[i-1][j][0], dp[i-1][j][1])+shifts[i].second-shifts[i].first;
            else dp[i][j][1] = max(dp[leftIndex][max(j-(i-leftIndex-1), 0)][0]+shifts[i].second-shifts[i].first, 
                                  dp[leftIndex][max(j-(i-leftIndex-1), 0)][1]+shifts[i].second-shifts[leftIndex].second);
        }
    }
    cout << max(dp[N-1][K][0], dp[N-1][K][1]) << '\n';
    return 0;
}
