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

int N, goodIntervals, idx, ret;
double L, W, upTo;
pair<double, double> intervals [10010];

int main(){
    //freopen("first.in", "r", stdin); freopen("first.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(cin >> N >> L >> W){
        goodIntervals = 0; idx = 0; upTo = 0.0; ret = 0;
        for(int i = 0; i < N; i++){
            double x, r; cin >> x >> r;
            if(r <= W/2.0) continue;
            double p = sqrt(r*r-W*W/4.0);
            intervals[goodIntervals].first = max(0.0, x-p); intervals[goodIntervals].second = min(L, x+p);
            goodIntervals++;
        }
        N = goodIntervals; sort(intervals, intervals+N);
        while(idx < N && upTo < L){
            double best = 0.0;
            while(idx < N && upTo-intervals[idx].first > -epsilon){
                best = max(best, intervals[idx].second);
                idx++;
            }
            if(best-upTo < epsilon){ ret = -1; break; }
            upTo = best; ret++;
        }
        if(upTo < L) ret = -1;
        cout << ret << '\n';
    }
    return 0;
}
