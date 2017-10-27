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

struct Mouse{
    double x, y, s;
    Mouse(){ }
};

int N, bitsInMask [1<<18];
Mouse mice [18];
double fatPow [18], lo = epsilon*1000.0, hi = INF, mid, dp [18][1<<18];

double dist(Mouse a, Mouse b){ return sqrt(pow(a.x-b.x, 2.0)+pow(a.y-b.y, 2.0)); }

bool solveTSP(){
    bool ok = false;
    for(int tmask = 0; tmask < (1<<(N-1)); tmask++)
        for(int i = 0; i < N; i++)
            dp[i][tmask*2+1] = INF;
    dp[0][1] = 0.0;
    for(int tmask = 0; tmask < (1<<(N-1)); tmask++)
        for(int i = 0; i < N; i++){
            int mask = tmask*2+1;
            if(dp[i][mask] == INF) continue;
            if(mask == ((1<<N)-1)){ ok = true; continue; }
            for(int j = 0; j < N; j++)
                if((mask&(1<<j)) == 0){
                    double nextTime = dp[i][mask]+dist(mice[i], mice[j])/(mid*fatPow[bitsInMask[mask]-1]);
                    if(nextTime <= mice[j].s) dp[j][mask|(1<<j)] = min(dp[j][mask|(1<<j)], nextTime);
                }
        }
    return ok;
}

int main(){
    //freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    bitsInMask[0] = 0;
    for(int i = 1; i < (1<<18); i++) bitsInMask[i] = bitsInMask[i-(i&-i)]+1;
    cin >> N; mice[0].x = 0, mice[0].y = 0, mice[0].s = INF; N++;
    for(int i = 1; i < N; i++) cin >> mice[i].x >> mice[i].y >> mice[i].s;
    fatPow[0] = 1.0; cin >> fatPow[1];
    for(int i = 2; i < 18; i++) fatPow[i] = fatPow[i-1]*fatPow[1];
    for(int rep = 0; rep < 1000; rep++){
        if(fabs(lo-hi) < 0.0001) break;
        mid = (lo+hi)/2.0;
        if(solveTSP()) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
    return 0;
}
