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

int kase, N, heights [100010], lo, hi;
long long ret;

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; lo = 0; hi = N-1; ret = 0;
        for(int i = 0; i < N; i++) cin >> heights[i];
        while(lo < hi){
            if(heights[lo] > heights[hi]){
                ret = max(ret, (long long)heights[hi]*(long long)(hi-lo));
                hi--;
            }
            else{
                ret = max(ret, (long long)heights[lo]*(long long)(hi-lo));
                lo++;
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
