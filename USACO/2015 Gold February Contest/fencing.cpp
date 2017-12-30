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

struct DynamicHullSegment{
    vector<pair<long long, long long>> lower, upper, points;
    void clearIt(){
        lower = vector<pair<long long, long long>>();
        upper = vector<pair<long long, long long>>();
        points = vector<pair<long long, long long>>();
    }
    DynamicHullSegment(){ clearIt(); }
    long long cross(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c){
        return (b.first-a.first)*(c.second-b.second)-(b.second-a.second)*(c.first-b.first);
    }
    long long evalIt(long long a, long long b, long long c, pair<long long, long long> lol){
        return a*lol.first+b*lol.second-c;
    }
    void mergeIt(vector<pair<long long, long long>> &add){
        vector<pair<long long, long long>> temp = points; points.resize(temp.size()+add.size());
        merge(temp.begin(), temp.end(), add.begin(), add.end(), points.begin());
        lower.clear(); upper.clear();
        for(int i = 0; i < points.size(); i++){
            while(lower.size() > 1 && cross(lower[lower.size()-2], lower.back(), points[i]) <= 0) lower.pop_back();
            while(upper.size() > 1 && cross(upper[upper.size()-2], upper.back(), points[i]) >= 0) upper.pop_back();
            lower.push_back(points[i]); upper.push_back(points[i]);
        }
    }
    pair<long long, long long> queryIt(long long a, long long b, long long c){
        if(points.size() == 0) return make_pair(INF, -INF);
        long long mini = INF, maxi = -INF;
        int lo = 0, hi = lower.size()-1;
        while(lo < hi){
            int mid = (lo+hi)/2;
            bool goLo = evalIt(a, b, c, lower[mid]) <= evalIt(a, b, c, lower[mid+1]);
            if(goLo) hi = mid;
            else lo = mid+1;
        }
        mini = evalIt(a, b, c, lower[lo]);
        lo = 0, hi = upper.size()-1;
        while(lo < hi){
            int mid = (lo+hi)/2;
            bool goLo = evalIt(a, b, c, upper[mid]) >= evalIt(a, b, c, upper[mid+1]);
            if(goLo) hi = mid;
            else lo = mid+1;
        }
        maxi = evalIt(a, b, c, upper[lo]);
        return make_pair(mini, maxi);
    }
};

int N, Q;
DynamicHullSegment hull [25];

void update(pair<long long, long long> now){
    vector<pair<long long, long long>> add; add.push_back(now);
    hull[0].mergeIt(add);
    for(int i = 0; i < 25; i++){
        if(hull[i].points.size() <= (1<<i)) break;
        hull[i+1].mergeIt(hull[i].points);
        hull[i].clearIt();
    }
}

bool query(long long a, long long b, long long c){
    if(b < 0){ a*= -1; b *= -1; c *= -1; }
    long long mini = INF, maxi = -INF;
    for(int i = 0; i < 25; i++){
        pair<long long, long long> mm = hull[i].queryIt(a, b, c);
        mini = min(mini, mm.first); maxi = max(maxi, mm.second);
    }
    return mini > 0 || maxi < 0;
}

int main(){
    freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        pair<long long, long long> now; cin >> now.first >> now.second;
        update(now);
    }
    for(int i = 0; i < Q; i++){
        int q; long long a, b, c; cin >> q;
        if(q == 1){
            cin >> a >> b;
            update(make_pair(a, b));
        }
        else{
            cin >> a >> b >> c;
            if(query(a, b, c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
