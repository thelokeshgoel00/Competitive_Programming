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
#include <cstring>
#include <sstream>
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, heights [510];
bool seen [60], dp [2][25010], firstPrint = true;

int main(){
    //freopen("first.in", "r", stdin); freopen("first.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(seen, false, sizeof(seen)); memset(dp, false, sizeof(dp));
    for(int i = 0; i < N; i++) cin >> heights[i];
    sort(heights, heights+N); reverse(heights, heights+N);
    dp[1][0] = true; seen[heights[1]] = true;
    for(int i = 2; i < N; i++){
        int prevy = (i-1)%2, curr = i%2;
        seen[heights[i]] = true;
        for(int j = 0; j < 25010; j++) dp[curr][j] = dp[prevy][j];
        for(int j = 50; j > heights[i]; j--){
            if(!seen[j]) continue;
            for(int k = j-heights[i]; k < 25010; k++) dp[curr][k] |= dp[prevy][k-(j-heights[i])];
        }
    }
    for(int i = 0; i < 25010; i++)
        if(dp[(N-1)%2][i]){
            if(!firstPrint) cout << ' ';
            else firstPrint = false;
            cout << i;
        }
    cout << '\n';
    return 0;
}
