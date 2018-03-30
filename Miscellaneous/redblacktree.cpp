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
#define INF 5000000000000000000
#define MOD 1000000007

int N, M, maxCount [200010];
vector<int> adjacency [200010];
bool isRed [200010];
queue<int> helper;
stack<int> processOrder;
int dp [200010][1010];

int main(){
    //freopen("disrupt.in", "r", stdin); freopen("disrupt.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; memset(isRed, false, sizeof(isRed));
    memset(maxCount, 0, sizeof(maxCount)); memset(dp, 0, sizeof(dp));
    for(int i = 2; i <= N; i++){
        int par; cin >> par;
        adjacency[par].push_back(i);
    }
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        isRed[x] = true;
    }
    helper.push(1);
    while(helper.size() > 0){
        int curr = helper.front(); helper.pop();
        processOrder.push(curr);
        for(int child : adjacency[curr]) helper.push(child);
    }
    for(int a = 0; a < N; a++){
        int curr = processOrder.top(); processOrder.pop();
        if(adjacency[curr].size() == 0){
            if(isRed[curr]){
                maxCount[curr] = 1;
                dp[curr][0] = 0; dp[curr][1] = 1;
            }
            else{
                maxCount[curr] = 0;
                dp[curr][0] = 1;
            }
            continue;
        }
        for(int child : adjacency[curr]) maxCount[curr] += maxCount[child];
        long long smalldp [2][maxCount[curr]+1]; memset(smalldp[1], 0, sizeof(smalldp[1]));
        int sofar = 0;
        for(int child : adjacency[curr]){
            copy(smalldp[1], smalldp[1]+(maxCount[curr]+1), smalldp[0]);
            for(int i = 0; i <= maxCount[child]; i++){
                for(int j = 0; j <= sofar; j++){
                    smalldp[1][i+j] += (smalldp[0][j]*dp[child][i])%MOD;
                    smalldp[1][i+j] %= MOD;
                }
                smalldp[1][i] += dp[child][i];
                smalldp[1][i] %= MOD;
            }
            sofar += maxCount[child];
        }
        if(isRed[curr]){
            if(maxCount[curr] == 0){
                maxCount[curr] = 1;
                dp[curr][0] = smalldp[1][0]; dp[curr][1] = 1;
            }
            else{
                smalldp[1][1]++; smalldp[1][1] %= MOD;
                copy(smalldp[1], smalldp[1]+(maxCount[curr]+1), dp[curr]);
            }
        }
        else{
            smalldp[1][0]++; smalldp[1][0] %= MOD;
            copy(smalldp[1], smalldp[1]+(maxCount[curr]+1), dp[curr]);
        }
    }
    dp[1][0]++; dp[1][0] %= MOD;
    for(int i = 0; i <= M; i++) cout << dp[1][i] << '\n';
    return 0;
}
