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

int N;
double machines [100010], total = 0.0, lo = 0.0, hi = 10000.0;

bool checkIt(double avg){
    double curr = machines[1]-avg, best = machines[1]-avg;
    for(int i = 2; i < N-1; i++){
        curr = max(curr, 0.0);
        curr += machines[i]-avg;
        best = max(best, curr);
    }
    return total-avg*N-best <= 0.0;
}

int main(){
    freopen("sabotage.in", "r", stdin); freopen("sabotage.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(3);
    cin >> N;
    for(int i = 0; i < N; i++){ cin >> machines[i]; total += machines[i]; }
    while(hi-lo > 0.00001){
        double mid = (lo+hi)/2.0;
        if(checkIt(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
    return 0;
}
