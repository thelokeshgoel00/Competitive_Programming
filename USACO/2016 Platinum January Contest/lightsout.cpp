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

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, cumSum [210], optimal [210], canon [420][420], dp[210][210][210][2], ret = 0;
pair<long long, long long> vertices [210];
vector<int> barnMap, liparents [210][210], riparents [210][210];

int main(){
    freopen("lightsout.in", "r", stdin); freopen("lightsout.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> vertices[i].first >> vertices[i].second;
    barnMap.push_back(0); // marks exit
    for(int i = 0; i < N; i++){
        int j = (i+1)%N, k = (i+2)%N;
        // marks side lengths
        barnMap.push_back((int)(abs(vertices[i].first-vertices[j].first)+abs(vertices[i].second-vertices[j].second)));
        // marks turns
        if((vertices[i].first-vertices[j].first)*(vertices[k].second-vertices[j].second)-
           (vertices[k].first-vertices[j].first)*(vertices[i].second-vertices[j].second) > 0)
           barnMap.push_back(-1);
        else barnMap.push_back(-2);
    }
    barnMap.back() = 0; // marks exit
    cumSum[0] = 0;
    for(int i = 1; i <= N; i++) cumSum[i] = optimal[i] = cumSum[i-1]+barnMap[2*i-1];
    optimal[N] = 0; // computes best lights-on cost for each corner
    for(int i = N-1; i > -1; i--) optimal[i] = min(optimal[i], optimal[i+1]+barnMap[2*i+1]);
    // finds first instance of string from i to i+ln-1
    for(int ln = 1; ln <= barnMap.size(); ln++)
        for(int i = 0; i+ln <= barnMap.size(); i++)
            for(int &j = canon[i][ln]; j < i; j++)
                if(canon[j][ln-1] == canon[i][ln-1] && barnMap[j+ln-1] == barnMap[i+ln-1])
                    break;
    // precomputation of state transitions to the left and to the right
    for(int i = 0; i < barnMap.size(); i += 2)
        for(int ln = 3; i + ln <= barnMap.size(); ln += 2){
            if(i != canon[i][ln]) continue;
            liparents[canon[i+2][ln-2]/2][ln/2].push_back(i/2);
            riparents[canon[i][ln-2]/2][ln/2].push_back(i/2);
        }
    for(int ln = N; ln > 0; ln--)
        for(int i = 0; i+ln-1 <= N; i++){
            if(canon[2*i][2*ln-1] != 2*i) continue; // no need to compute it again
            int dist = cumSum[i+ln-1]-cumSum[i];
            for(int st = 0; st < ln; st++)
                for(int side = 0; side < 2; side++){
                    if(i == 0 || i+ln-1 == N){ // we are at the exit
                        dp[i][ln][st][side] = -optimal[i+st];
                        continue;
                    }
                    // compute the worst case cost for left and right extensions
                    int liCost = -1000000000, riCost = -1000000000;
                    for (int j : liparents[i][ln]) liCost = max(liCost, barnMap[2*j+1]+dp[j][ln+1][st+1][0]);
                    for (int j : riparents[i][ln]) riCost = max(riCost, barnMap[2*(j+ln)-1]+dp[j][ln+1][st][1]);
                    (side == 1 ? liCost : riCost) += dist; // if we decide to cross over the visited string
                    dp[i][ln][st][side] = min(liCost, riCost);
                    if(ln == 1) ret = max(ret, dp[i][ln][st][side]); // this is a single corner
                }
        }
    cout << ret << '\n';
    return 0;
}
