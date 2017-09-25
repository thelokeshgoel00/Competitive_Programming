#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, M, nexty [1010][30], dp [2][1010];
string stuff, pattern;

int main(){
    freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    cin >> stuff >> pattern; memset(nexty, 0, sizeof(nexty));
    N = stuff.length(); M = pattern.length();
    for(int i = 1; i < M; i++){
        int prevy = nexty[i-1][pattern[i-1]-'a'];
        nexty[i-1][pattern[i-1]-'a'] = i;
        for(int j = 0; j < 26; j++) nexty[i][j] = nexty[prevy][j];
    }
    nexty[M-1][pattern[M-1]-'a'] = M; memset(dp[0], -1, sizeof(dp[0]));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        memcpy(dp[i%2], dp[(i-1)%2], sizeof(dp[i%2]));
        for(int j = 0; j < M; j++){
            int curr = nexty[j][stuff[i-1]-'a'];
            if(curr != M && dp[(i-1)%2][j] != -1) dp[i%2][curr] = max(dp[i%2][curr], dp[(i-1)%2][j]+1);
        }
    }
    cout << N-*max_element(dp[N%2], dp[N%2]+1010) << '\n';
    return 0;
}
