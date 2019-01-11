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

int kase, N;
double x [1010], y [1010], z [1010], p [1010], lo, hi, checks [8];

int main(){
    //freopen("dirtraverse.in", "r", stdin); freopen("dirtraverse.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; lo = 0.0; hi = 1.0e9;
        for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> z[i] >> p[i];
        while(lo+epsilon < hi){
            double mid = (lo+hi)/2.0; fill(checks, checks+8, INF);
            for(int i = 0; i < N; i++)
                for(int mask = 0; mask < 8; mask++){
                    double sum = mid*p[i];
                    sum += ((mask&1) == 0) ? x[i] : -x[i];
                    sum += ((mask&2) == 0) ? y[i] : -y[i];
                    sum += ((mask&4) == 0) ? z[i] : -z[i];
                    checks[mask] = min(checks[mask], sum);
                }
            bool ok = true;
            for(int mask = 0; mask < 8; mask++)
                if(checks[mask] < -checks[mask^7]){
                    ok = false;
                    break;
                }
            if(ok) hi = mid;
            else lo = mid;
        }
        cout << "Case #" << kk << ": " << hi << '\n';
    }
    return 0;
}
