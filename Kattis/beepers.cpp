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

int kase, numBeepers, dp [12][1<<12];
pair<int, int> points [12];

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> points[0].first >> points[0].second >> points[0].first >> points[0].second >> numBeepers; numBeepers++;
        for(int mask = 0; mask < (1<<numBeepers); mask++)
            for(int i = 0; i < numBeepers; i++)
              dp[i][mask] = 500;
        for(int i = 1; i < numBeepers; i++){
            cin >> points[i].first >> points[i].second;
            dp[i][1<<i] = abs(points[i].first-points[0].first)+abs(points[i].second-points[0].second);
        }
        for(int mask = 1; mask < (1<<numBeepers); mask++)
            for(int i = 0; i < numBeepers; i++){
                if(dp[i][mask] == 500) continue;
                for(int j = 0; j < numBeepers; j++)
                    if((mask&(1<<j)) == 0)
                        dp[j][mask|(1<<j)] = min(dp[j][mask|(1<<j)], dp[i][mask]+abs(points[i].first-points[j].first)+abs(points[i].second-points[j].second));
            }
        cout << dp[0][(1<<numBeepers)-1] << '\n';
    }
    return 0;
}
