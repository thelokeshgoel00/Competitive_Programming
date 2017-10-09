#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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

struct Point{
    double x, y;
    int id;
    Point(){ x = 1000001.0; y = 1000001.0; id = -1; }
    bool operator<(const Point &other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int N, idx = 0;
Point points [50010];
pair<double, pair<int, int>> master = make_pair(INF, make_pair(-1, -1));
set<pair<pair<double, double>, int>> sweep;

double distSquared(Point a, Point b){ return pow(a.x-b.x, 2.0)+pow(a.y-b.y, 2.0); }

pair<double, pair<int, int>> update(Point a, Point b, pair<double, pair<int, int>> ret){
    if(a.id > b.id) return update(b, a, ret);
    if(distSquared(a, b) > ret.first) return ret;
    if(distSquared(a, b) < ret.first){
        ret.first = distSquared(a, b); ret.second = make_pair(a.id, b.id);
        return ret;
    }
    if(a.id < ret.second.first || (a.id == ret.second.first && b.id < ret.second.second)){
        ret.second.first = a.id; ret.second.second = b.id;
        return ret;
    }
    return ret;
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lf %lf", &points[i].x, &points[i].y);
        points[i].id = i+1;
    }
    sort(points, points+N); sweep.insert(make_pair(make_pair(points[0].y, points[0].x), points[0].id));
    for(int i = 1; i < N; i++) master = update(points[0], points[i], master);
    for(int i = 1; i < N; i++){
        while(idx < i && pow(points[i].x-points[idx].x, 2.0) > master.first){
            sweep.erase(make_pair(make_pair(points[idx].y, points[idx].x), points[idx].id));
            idx++; 
        }
        pair<pair<double, double>, int> bot = make_pair(make_pair(points[i].y-sqrt(master.first), 0), 0), 
            top = make_pair(make_pair(points[i].y+sqrt(master.first), INF), 100010);
        auto bi = sweep.lower_bound(bot), ti = sweep.lower_bound(top);
        while(bi != ti){
            Point temp; temp.x = bi->first.second; temp.y = bi->first.first; temp.id = bi->second;
            master = update(points[i], temp, master);
            bi++;
        }
        sweep.insert(make_pair(make_pair(points[i].y, points[i].x), points[i].id));
    }
    cout << master.second.first << " " << master.second.second << endl;
    return 0;
}
