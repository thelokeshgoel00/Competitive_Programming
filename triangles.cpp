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

int N, underSeg [310][310], ret [310];
Point points [310];

double cross(Point a, Point b, Point c){ return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x); }

bool checkUnder(Point a, Point b, Point c){
    if(b < a) return checkUnder(b, a, c);
    Point other; other.x = a.x; other.y = a.y-1;
    return a.x < c.x && c.x < b.x &&
        ((cross(b, a, c) < 0 && cross(b, a, other) < 0) || (cross(b, a, c) > 0 && cross(b, a, other) > 0));
}

int main(){
    freopen("triangles.in", "r", stdin); freopen("triangles.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(underSeg, 0, sizeof(underSeg)); memset(ret, 0, sizeof(ret));
    for(int i = 0; i < N; i++) cin >> points[i].x >> points[i].y;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(points[i].x >= points[j].x) continue; // Case == : Vertical Cancels Out, Case > : Rule Out Counterclockwise
            for(int k = 0; k < N; k++){
                if(k == i || k == j) continue;
                if(points[i].x > points[k].x || points[j].x < points[k].x) continue;
                if(points[i].x == points[k].x && points[i].y > points[k].y) underSeg[i][j]++;
                else if(points[j].x == points[k].x && points[j].y > points[k].y) underSeg[i][j]++;
                else if(checkUnder(points[i], points[j], points[k])) underSeg[i][j] += 2;
            }
            underSeg[j][i] = -underSeg[i][j];
        }
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            for(int k = j+1; k < N; k++){
                int temp = abs(underSeg[i][j]+underSeg[j][k]+underSeg[k][i])/2;
                if(checkUnder(points[i], points[j], points[k])) temp--;
                if(checkUnder(points[j], points[k], points[i])) temp--;
                if(checkUnder(points[k], points[i], points[j])) temp--;
                ret[temp]++;
            }
    for(int i = 0; i < N-2; i++) cout << ret[i] << '\n';
    return 0;
}
