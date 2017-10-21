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

int N, K;
long long cumSum [100010], dp [100010];
set<pair<long long, int>> inRange;

int main(){
    //freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K; cumSum[0] = dp[0] =  0ll;
    for(int i = 1; i <= N; i++){ cin >> cumSum[i]; cumSum[i] += cumSum[i-1]; }
    for(int i = 1; i <= K; i++){ dp[i] = cumSum[i]; inRange.insert(make_pair(dp[i-1]-cumSum[i], i)); }
    for(int i = K+1; i <= N; i++){
        dp[i] = cumSum[i]+(*inRange.rbegin()).first;
        inRange.erase(make_pair(dp[i-K-1]-cumSum[i-K], i-K));
        inRange.insert(make_pair(dp[i-1]-cumSum[i], i));
    }
    cout << dp[N] << '\n';
    return 0;
}
