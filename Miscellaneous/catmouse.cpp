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

int kase;
double R, tom, jerry, r;

int main(){
    //freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> R >> tom >> jerry;
        r = tom*R/jerry;
        if(r > R || sqrt(R*R-r*r)/tom <= R*(PI+(0.5*PI-asin(r/R)))/jerry) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

// https://math.stackexchange.com/questions/31097/a-lady-and-a-monster
// http://datagenetics.com/blog/october12013/index.html
