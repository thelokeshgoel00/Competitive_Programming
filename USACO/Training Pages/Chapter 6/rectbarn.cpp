/*
ID: vamaddu1
PROG: rectbarn
LANG: C++11
*/

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

int R, C, P, height [3010], li [3010], ri [3010], ret = 0;
bool bad [3010][3010];

int main(){
    freopen("rectbarn.in", "r", stdin); freopen("rectbarn.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> R >> C >> P; memset(bad, false, sizeof(bad));
    for(int i = 0; i < P; i++){
        int a, b; cin >> a >> b;
        bad[a][b] = true;
    }
    for(int i = 1; i <= R; i++){
        int streak = 0;
        for(int j = 1; j <= C; j++){
            streak++;
            if(!bad[i][j]){
                li[j] = li[j] == 0 ? streak : min(li[j], streak);
                height[j]++;
            }
            else height[j] = li[j] = streak = 0;
        }
        streak = 0;
        for(int j = C; j >= 1; j--){
            streak++;
            if(!bad[i][j]){
                ri[j] = ri[j] == 0 ? streak : min(ri[j], streak);
                ret = max(ret, height[j]*(li[j]+ri[j]-1));
            }
            else ri[j] = streak = 0;
        }
    }
    cout << ret << '\n';
    return 0;
}
