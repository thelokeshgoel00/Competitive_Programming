/*
ID: vamaddu1
PROG: fence3
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
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int F;
pair<pair<double, double>, pair<double, double>> fences [160];
pair<double, double> curr = make_pair(50.0, 50.0);

double getDist(pair<double, double> a, pair<double, double> b){
    return sqrt(pow(a.first-b.first, 2.0)+pow(a.second-b.second, 2.0));
}

double testAll(pair<double, double> pt){
    double sum = 0.0;
    for(int i = 0; i < F; i++){
        if(fences[i].first.first == fences[i].second.first){
            if(pt.second >= fences[i].first.second && pt.second <= fences[i].second.second){
                sum += abs(pt.first-fences[i].first.first);
                continue;
            }
        }
        else{
            if(pt.first >= fences[i].first.first && pt.first <= fences[i].second.first){
                sum += abs(pt.second-fences[i].first.second);
                continue;
            }
        }
        sum += min(getDist(pt, fences[i].first), getDist(pt, fences[i].second));
    }
    return sum;
}

double testX(double y){
    double lo = 0.0, hi = 100.0;
    while(hi-lo > epsilon){
        double t1 = (2.0*lo+hi)/3.0, t2 = (lo+2.0*hi)/3.0;
        if(testAll(make_pair(t1, y)) > testAll(make_pair(t2, y))) lo = t1;
        else hi = t2;
    }
    return lo;
}

double testY(double x){
    double lo = 0.0, hi = 100.0;
    while(hi-lo > epsilon){
        double t1 = (2.0*lo+hi)/3.0, t2 = (lo+2.0*hi)/3.0;
        if(testAll(make_pair(x, t1)) > testAll(make_pair(x, t2))) lo = t1;
        else hi = t2;
    }
    return lo;
}

int main(){
    freopen("fence3.in", "r", stdin); freopen("fence3.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(1);
    cin >> F;
    for(int i = 0; i < F; i++){
        cin >> fences[i].first.first >> fences[i].first.second >> fences[i].second.first >> fences[i].second.second;
        if(fences[i].first > fences[i].second) swap(fences[i].first, fences[i].second);
    }
    for(int i = 0; i < 100; i++){
        pair<double, double> nexty;
        nexty.first = testX(curr.second);
        nexty.second = testY(curr.first);
        curr = nexty;
    }
    cout << curr.first << ' ' << curr.second << ' ' << testAll(curr) << '\n';
    return 0;
}
