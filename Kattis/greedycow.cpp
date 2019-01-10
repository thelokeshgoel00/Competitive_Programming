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

struct Point{
    double x, y;
    Point(){ x = 1000001.0; y = 1000001.0; }
    bool operator<(const Point &other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int N, numHull, lo = 0, hi = 100000, best;
long long M, combo [100010][5];
Point start, ori [110], hull [110];

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

int findHull(Point points [110], Point hull [110]){
    int top = 1, n = N;
    if(n <= 3){
        for(int i = 0; i < n; i++){ hull[i].x = points[i].x; hull[i].y = points[i].y; }
        hull[n].y = points[0].x; hull[n].y = points[0].y;
        return n;
    }
    start.x = points[0].x; start.y = points[0].y;
    sort(points+1, points+n, smallerAngle);
    hull[0].x = start.x; hull[0].y = start.y; hull[1].x = points[1].x; hull[1].y = points[1].y;
    points[n].x = start.x; points[n].y = start.y;
    for(int i = 2; i <= n; i++){
        while(top >= 1 && !ccw(hull[top-1], hull[top], points[i])) top--;
        top++; hull[top].x = points[i].x; hull[top].y = points[i].y;
    }
    return top;
}

bool checkIt(int x){
    int points1 = x/numHull, count1 = numHull-(x%numHull), points2 = points1+1, count2 = x%numHull;
    long long ret = combo[x][4]+combo[x][2]+1; // http://mathforum.org/library/drmath/view/55262.html
    ret -= (combo[points1][2]+combo[points1][3]*(long long)(x-points1)+combo[points1][4])*(long long)count1;
    ret -= (combo[points2][2]+combo[points2][3]*(long long)(x-points2)+combo[points2][4])*(long long)count2;
    return ret >= M;
}

int main(){
    //freopen("first.in", "r", stdin); freopen("first.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    memset(combo, 0, sizeof(combo)); combo[0][0] = 1;
    for(int i = 1; i < 100010; i++){
        combo[i][0] = 1;
        for(int j = 1; j < 5; j++) combo[i][j] = combo[i-1][j]+combo[i-1][j-1];
    }
    cin >> M >> N;
    for(int i = 0; i < N; i++) cin >> ori[i].x >> ori[i].y;
    numHull = findHull(ori, hull);
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(checkIt(mid)){ best = mid; hi = mid-1; }
        else lo = mid+1;
    }
    cout << best << '\n';
    return 0;
}
