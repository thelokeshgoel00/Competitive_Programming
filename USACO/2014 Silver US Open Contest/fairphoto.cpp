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

int N, sum = 0, ret = 0;
pair<int, char> cows [100010];
vector<pair<int, int>> cumSums [2];

int main(){
    freopen("fairphoto.in", "r", stdin); freopen("fairphoto.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> cows[i].first >> cows[i].second;
    sort(cows, cows+N);
    for(int i = 0; i < N; i++){
        if(i < 2 || cumSums[sum&1].back().first < sum)
            cumSums[sum&1].push_back(make_pair(sum, cows[i].first));
        sum += cows[i].second == 'W' ? -1 : 1;
        if(i > 0 && sum <= cumSums[sum&1].back().first)
            ret = max(ret, cows[i].first-lower_bound(cumSums[sum&1].begin(),
                        cumSums[sum&1].end(), make_pair(sum, -1))->second);
    }
    cout << ret << '\n';
    return 0;
}
