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

int kase, N, dp [210][210][2];
vector<pair<int, int>> cars [2];

int main(){
    //freopen("first.in", "r", stdin); freopen("first.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; cars[0].clear(); cars[1].clear();
        for(int i = 0; i < 210; i++)
            for(int j = 0; j < 210; j++)
                dp[i][j][0] = dp[i][j][1] = 1000000000;
        dp[0][0][0] = dp[0][0][1] = 0;
        for(int i = 0; i < N; i++){
            char c; int x, y; cin >> c >> x >> y;
            if(c == 'A') cars[0].push_back(make_pair(x, y));
            else cars[1].push_back(make_pair(x, y));
        }
        sort(cars[0].begin(), cars[0].end()); sort(cars[1].begin(), cars[1].end());
        for(int i = 0; i <= cars[0].size(); i++)
            for(int j = 0; j <= cars[1].size(); j++)
                for(int k = 0; k < 2; k++){
                    int lastStart = dp[i][j][k]-10, lastEnd = lastStart;
                    for(int x = k == 1 ? j : i; x < cars[k].size(); x++){
                        int nextStart = max(lastStart+10, cars[k][x].first), nextEnd = max(lastEnd+10, nextStart+cars[k][x].second);
                        if(k == 1) dp[i][x+1][0] = min(dp[i][x+1][0], nextEnd);
                        else dp[x+1][j][1] = min(dp[x+1][j][1], nextEnd);
                        lastStart = nextStart; lastEnd = nextEnd;
                    }
                }
        cout << min(dp[cars[0].size()][cars[1].size()][0], dp[cars[0].size()][cars[1].size()][1]) << '\n';
    }
    return 0;
}
