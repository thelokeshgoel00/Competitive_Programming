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

int N, arr [100010], dp [100010];
vector<pair<int, int>> consider;

int main(){
    //freopen("mowing.in", "r", stdin); freopen("mowing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; arr[N] = 0;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = N-1; i > -1; i--) arr[i] += arr[i+1];
    consider.push_back(make_pair(0, N));
    for(int i = N-1; i > -1; i--){
        auto it = lower_bound(consider.begin(), consider.end(), make_pair(arr[i], -1));
        if(it == consider.end() || (*it).first > arr[i]) it--;
        pair<int, int> prevy = *it; dp[i] = dp[prevy.second]+1;
        int width = arr[i]-arr[prevy.second];
        while(consider.back().first >= width+arr[i]) consider.pop_back();
        consider.push_back(make_pair(width+arr[i], i));
    }
    cout << dp[0] << '\n';
    return 0;
}
