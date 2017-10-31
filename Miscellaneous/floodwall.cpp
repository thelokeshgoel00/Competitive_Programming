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

int N, idx;
vector<pair<long long, long long>> intervals(200010);
long long maxVal [200010], dp [200010];

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; idx = N; intervals[N] = make_pair(INF, INF); maxVal[N] = 0ll; dp[N] = 0ll;
    for(int i = 0; i < N; i++) cin >> intervals[i].first >> intervals[i].second;
    sort(intervals.begin(), intervals.begin()+N+1);
    for(int i = N-1; i > -1; i--){
        dp[i] = max(dp[i+1], maxVal[lower_bound(intervals.begin()+i+1, intervals.begin()+N+1, make_pair(intervals[i].second, 0ll))-intervals.begin()]+
                    intervals[i].second-intervals[i].first);
        maxVal[i] = max(dp[i], maxVal[i+1]);
    }
    cout << dp[0] << '\n';
    return 0;
}
