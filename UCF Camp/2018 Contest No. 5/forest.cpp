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
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

struct Point{
    double x, y;
    Point(){ x = 1000001.0; y = 1000001.0; }
    bool operator<(const Point &other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int N, numHull;
Point start, ori [50010], hull [50010];
double C, perimeter = 0.0, area = 0.0;

double dist(Point a, Point b){ return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2)); }

bool ccw(Point a, Point b, Point c){ return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x) > epsilon; }

bool collinear(Point a, Point b, Point c){
    return fabs(a.x*b.y+b.x*c.y+c.x*a.y-(a.y*b.x+b.y*c.x+c.y*a.x)) < epsilon;
}

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
        points[hole].x = points[i].x; points[hole].y = points[i].y; hole++;
    }
    points[hole].x = points[oldn-1].x; points[hole].y = points[oldn-1].y;
    return sub;
}

int findHull(Point points [50010], Point hull [50010]){
    int top = 1, n = N;
    if(n <= 3){
        for(int i = 0; i < n; i++){ hull[i].x = points[i].x; hull[i].y = points[i].y; }
        hull[n].x = points[0].x; hull[n].y = points[0].y;
        return n;
    }
    n -= removeDupe(points);
    start.x = points[0].x; start.y = points[0].y;
    sort(points+1, points+n, smallerAngle);
    hull[0].x = start.x; hull[0].y = start.y; hull[1].x = points[1].x; hull[1].y = points[1].y;
    points[n].x = start.x; points[n].y = start.y;
    for(int i = 2; i <= n; i++){
        while(top >= 1 && !ccw(hull[top-1], hull[top], points[i])) top--;
        top++; hull[top].x = points[i].x; hull[top].y = points[i].y;
    }
    if(top == 1){
        hull[1].x = points[n-1].x; hull[1].y = points[n-1].y;
        hull[2].x = points[0].x; hull[2].y = points[0].y;
        top = 2;
    }
    return top;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> N >> C;
    for(int i = 0; i < N; i++) cin >> ori[i].x >> ori[i].y;
    numHull = findHull(ori, hull);
    for(int i = 0; i < numHull; i++){
        perimeter += dist(hull[i], hull[i+1]);
        area += (hull[i].x*hull[i+1].y)-(hull[i].y*hull[i+1].x);
    }
    area = abs(area)/2.0; area += perimeter*C+PI*pow(C, 2.0);
    perimeter += 2.0*PI*C;
    cout << perimeter << ' ' << area << '\n';
    return 0;
}
