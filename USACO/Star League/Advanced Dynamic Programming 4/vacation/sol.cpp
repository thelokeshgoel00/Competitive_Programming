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

int N, dp [2][50010];
vector<int> adjacency [50010];

int recurse(int curr, int prevy, int takeIt){
    if(dp[takeIt][curr] != -1) return dp[takeIt][curr];
    dp[takeIt][curr] = takeIt;
    for(int i : adjacency[curr]){
        if(i == prevy) continue;
        int add = recurse(i, curr, 0);
        if(takeIt == 0) add = max(add, recurse(i, curr, 1));
        dp[takeIt][curr] += add;
    }
    return dp[takeIt][curr];
}

int main(){
    //freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(dp, -1, sizeof(dp));
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    cout << max(recurse(1, 0, 0), recurse(1, 0, 1)) << '\n';
    return 0;
}
