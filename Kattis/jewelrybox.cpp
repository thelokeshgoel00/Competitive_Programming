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

int kase;
double x, y, lo, hi;

double findVolume(double h){ return h*(x-2.0*h)*(y-2.0*h); }

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> x >> y; lo = 0.0; hi = min(x, y)/2.0;
        while(hi-lo > epsilon){
            double li = findVolume((2.0*lo+hi)/3.0), ri = findVolume((lo+2.0*hi)/3.0);
            if(ri > li) lo = (2.0*lo+hi)/3.0;
            else hi = (lo+2.0*hi)/3.0;
        }
        cout << findVolume((lo+hi)/2.0) << '\n';
    }
    return 0;
}
