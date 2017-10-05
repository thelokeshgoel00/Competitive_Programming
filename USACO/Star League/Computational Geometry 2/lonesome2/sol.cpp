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

int N, numHull;
Point start, ori [50010], hull [50010];
pair<int, int> ret;
double maxDist;

double dist(Point a, Point b){ return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2)); }

double distSquared(Point a, Point b){ return pow(a.x-b.x, 2)+pow(a.y-b.y, 2); }

double cross(Point a, Point b, Point c){ return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x); }

bool ccw(Point a, Point b, Point c){ return cross(a, b, c) > epsilon; }

bool collinear(Point a, Point b, Point c){ return fabs(a.x*b.y+b.x*c.y+c.x*a.y-(a.y*b.x+b.y*c.x+c.y*a.x)) < epsilon; }

bool smallerAngle(Point a, Point b){
    double anga = atan2(a.y-start.y, a.x-start.x), angb = atan2(b.y-start.y, b.x-start.x);
    if(collinear(start, a, b) && fabs(angb-anga) < epsilon)
        return dist(start, a) > dist(start, b) ? 0 : 1;
    return anga > angb ? 0 : 1;
}

int removeDupe(Point points [50010]){
    sort(points, points+N);
    int oldn = N, hole = 1, sub = 0;
    for(int i = 1; i < oldn-1; i++){
        if(points[hole-1].x == points[i].x && points[hole-1].y == points[i].y){ sub++;  continue; }
        points[hole].x = points[i].x; points[hole].y = points[i].y; points[hole].id = points[i].id; hole++;
    }
    points[hole].x = points[oldn-1].x; points[hole].y = points[oldn-1].y; points[hole].id = points[oldn-1].id;
    return sub;
}

int findHull(Point points [50010], Point hull [50010]){
    int top = 1, n = N;
    if(n <= 3){
        for(int i = 0; i < n; i++){ hull[i].x = points[i].x; hull[i].y = points[i].y; hull[i].id = points[i].id; }
        hull[n].y = points[0].x; hull[n].y = points[0].y; hull[n].id = points[0].id;
        return n;
    }
    n -= removeDupe(points);
    start.x = points[0].x; start.y = points[0].y; start.id = points[0].id;
    sort(points+1, points+n, smallerAngle);
    hull[0].x = start.x; hull[0].y = start.y; hull[0].id = start.id;
    hull[1].x = points[1].x; hull[1].y = points[1].y; hull[1].id = points[1].id;
    points[n].x = start.x; points[n].y = start.y; points[n].id = start.id;
    for(int i = 2; i <= n; i++){
        while(top >= 1 && !ccw(hull[top-1], hull[top], points[i])) top--;
        top++; hull[top].x = points[i].x; hull[top].y = points[i].y; hull[top].id = points[i].id;
    }
    return top;
}

void update(Point a, Point b){
    if(a.id > b.id) update(b, a);
    if(distSquared(a, b) < maxDist) return;
    if(distSquared(a, b) > maxDist){
        ret = make_pair(a.id, b.id);
        maxDist = distSquared(a, b);
        return;
    }
    if(a.id < ret.first || (a.id == ret.first && b.id < ret.second)){
        ret = make_pair(a.id, b.id);
        return;
    }
}

void calculateIt(){
    vector<Point> L, U; int j = 0, k = 0; L.resize(numHull+10); U.resize(numHull+10);
    sort(hull, hull+numHull);
    for(int i = 0; i < numHull; i++){
        while(j > 1 && cross(L[j-2], L[j-1], hull[i]) <= 0) j--;
        while(k > 1 && cross(U[k-2], U[k-1], hull[i]) >= 0) k--;
        L[j] = hull[i]; U[k] = hull[i]; j++; k++;
    }
    L.resize(j); U.resize(k);
    int i = 0, m = U.size()-1; j = L.size()-1;
    while(i < m || j > 0){
        update(U[i], L[j]);
        if(i == m) j--;
        else if(j == 0) i++;
        else{
            if((U[i+1].y-U[i].y)*(L[j].x-L[j-1].x) > (L[j].y-L[j-1].y)*(U[i+1].x-U[i].x)) i++;
            else j--;
        }
    }
    /*for(int i = 0; i < numHull; i++)
        for(int j = i+1; j < numHull; j++)
            update(hull[i], hull[j]);*/
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){ scanf("%lf %lf", &ori[i].x, &ori[i].y); ori[i].id = i+1; }
    numHull = findHull(ori, hull);
    maxDist = distSquared(hull[0], hull[1]); ret = make_pair(hull[0].id, hull[1].id);
    if(ret.first > ret.second) swap(ret.first, ret.second);
    calculateIt();
    cout << ret.first << " " << ret.second << '\n';
    return 0;
}
