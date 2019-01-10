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

int numAllergens, duration [25], dp [1<<21][10], ret = 200;

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> numAllergens;
    for(int i = 0; i < numAllergens; i++){ cin >> duration[i]; /*duration[i]--;*/ }
    for(int i = 0; i < 10; i++) dp[0][i] = i;
    for(int mask = 1; mask < (1<<numAllergens); mask++){
        fill(dp[mask], dp[mask]+10, 200);
        for(int i = 0; i < numAllergens; i++){
            if((mask&(1<<i)) == 0) continue;
            for(int elapsedTime = 0; elapsedTime < 10; elapsedTime++){
                int stubTime = max(duration[i]-elapsedTime-1, 0);
                dp[mask][stubTime] = min(dp[mask][stubTime], dp[mask^(1<<i)][elapsedTime]+stubTime+1);
            }
        }
    }
    for(int i = 0; i < 10; i++) ret = min(ret, dp[(1<<numAllergens)-1][i]);
    cout << ret << '\n';
    return 0;
}
