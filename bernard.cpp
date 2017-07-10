#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, dist;
long long dp [100001], arr [100000];

long long solve(int curr){
    if(curr >= n) return 0;
    if(dp[curr] > -1) return dp[curr];
    return dp[curr] = max(solve(curr+1), solve(curr+dist+1)+arr[curr]);
}

int main(){
    cin >> n >> dist;
    for(int i = 0; i < n; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0) << '\n';
    return 0;
}
