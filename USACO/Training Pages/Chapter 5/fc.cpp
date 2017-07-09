/*
ID: vamaddu1
PROG: fc
LANG: C++11
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

#define PI 3.14159265
#define epsilon 0.000000001

struct Point{
    double x, y;
    Point(){ x = 1000001.0; y = 1000001.0; }
    bool operator<(const Point &other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int numCows, numInHull;
double ret = 0.0;
Point start, points [20000], hull [20000];

double dist(Point a, Point b){ return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2)); }

bool ccw(Point a, Point b, Point c){ return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x) > epsilon; }

bool collinear(Point a, Point b, Point c){
    return fabs(a.x*b.y+b.x*c.y+c.x*a.y-(a.y*b.x+b.y*c.x+c.y*a.x)) < epsilon;
}

bool smallerAngle(Point a, Point b){
    double anga = atan2(a.y-start.y, a.x-start.x), angb = atan2(b.y-start.y, b.x-start.x);
    if(collinear(start, a, b) && fabs(angb-anga) < epsilon)
        return dist(start, a) <= dist(start, b) ? 0 : 1;
    return anga > angb ? 0 : 1;
}

int removeDupe(){
    sort(points, points+numCows);
    int oldn = numCows, hole = 1, sub = 0;
    for(int i = 1; i < oldn-1; i++){
        if(points[hole-1].x == points[i].x && points[hole-1].y == points[i].y){ sub++;  continue; }
        points[hole].x = points[i].x; points[hole].y = points[i].y; hole++;
    }
    points[hole].x = points[oldn-1].x; points[hole].y = points[oldn-1].y;
    return sub;
}

int findHull(){
    int i = 2, top = 1, n = numCows;
    if(n <= 3){
        for(i = 0; i < n; i++){ hull[i].x = points[i].x; hull[i].y = points[i].y; }
        hull[n].y = points[0].x; hull[n].y = points[0].y;
        return n;
    }
    n -= removeDupe();
    start.x = points[0].x; start.y = points[0].y;
    sort(points+1, points+n, smallerAngle);
    hull[0].x = start.x; hull[0].y = start.y; hull[1].x = points[1].x; hull[1].y = points[1].y;
    points[n].x = start.x; points[n].y = start.y;
    while(i <= n){
        if(!ccw(hull[top-1], hull[top], points[i])) top--;
        else{
            top++;
            hull[top].x = points[i].x; hull[top].y = points[i].y;
            i++;

        }
    }
    return top;
}

int main(){
    freopen("fc.in", "r", stdin); freopen("fc.out", "w", stdout);
    scanf("%d", &numCows);
    for(int i = 0; i < numCows; i++){
        Point temp; scanf("%lf %lf", &temp.x, &temp.y);
        points[i] = temp;
    }
    numInHull = findHull();
    for(int i = 0; i < numInHull; i++) ret += dist(hull[i], hull[i+1]);
    printf("%.2lf\n", ret);
    return 0;
}
