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
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N;
long long cumSum [510], costs [510], dp [510][510];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> N;
    for(int i = 1; i <= N; i++){ cin >> cumSum[i]; cumSum[i] += cumSum[i-1]; }
    for(int i = 1; i <= N; i++){ cin >> costs[i]; dp[i][i] = 0; }
    for(int len = 2; len <= N; len++)
        for(int i = 1; i <= N-len+1; i++){
            int j = i+len-1; dp[i][j] = INF;
            long long totPeople = cumSum[j]-cumSum[i-1];
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+totPeople*min(costs[k], costs[k+1]));
        }
    cout << dp[1][N] << '\n';
    return 0;
}
