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
double newArea, oldArea = 0.0, minX = INF, minY = INF;
pair<double, double> ori [60];

int main(){
    //freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ori[i].first >> ori[i].second;
        minX = min(minX, ori[i].first); minY = min(minY, ori[i].second);
    }
    for(int i = 0; i < N; i++){
        oldArea += ori[i].first*ori[(i+1)%N].second;
        oldArea -= ori[i].second*ori[(i+1)%N].first;
    }
    cin >> newArea; oldArea = fabs(oldArea)/2.0;
    for(int i = 0; i < N; i++){
        cout << sqrt(newArea/oldArea)*(ori[i].first-minX) << " ";
        cout << sqrt(newArea/oldArea)*(ori[i].second-minY) << '\n';
    }
    return 0;
}
