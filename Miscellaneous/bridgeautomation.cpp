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

int N, tiempos [4010], dp [4010];

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; dp[0] = 0;
    for(int i = 1; i <= N; i++){
        cin >> tiempos[i]; dp[i] = 200000;
        for(int j = 1; j <= i; j++)
            dp[i] = min(dp[i], dp[i-j]+max(20*j, tiempos[i]-tiempos[i-j+1]-1780)+120);
    }
    cout << dp[N] << '\n';
    return 0;
}
