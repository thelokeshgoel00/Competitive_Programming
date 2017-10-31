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

int N, pre = -1, dp [500010];
char s [500010];

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> (s+1); dp[0] = dp[1] = dp[2] = 0;
    for(int i = 3; i <= N; i++){
        dp[i] = dp[i-1];
        if(s[i] == '0'){ pre = -1; continue; }
        if(s[i-1] == '0' && s[i-2] == '1'){
            int j = i-2;
            while(j > 0 && s[j] == '1'){ dp[i] = max(dp[i], dp[j-1]+i-j-1); j--; }
            pre = i;
        }
        if(pre != -1) dp[i] = max(dp[i], dp[pre-3]+i-pre+1);
    }
    cout << dp[N] << '\n';
    return 0;
}
