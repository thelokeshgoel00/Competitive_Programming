#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define epsilon 0.000000001

struct Point{
    double x, y;
    Point(){ x = 1000001.0; y = 1000001.0; }
    bool operator<(const Point &other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int N, numHullA, numHullB;
Point start, oriA [50010], oriB [50010], dupeA [50010], dupeB [50010], hullA [50010], hullB [50010], centroidA, centroidB;

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
        hull[n].y = points[0].x; hull[n].y = points[0].y;
        return n;
    }
    n -= removeDupe(points);
    start.x = points[0].x; start.y = points[0].y;
    sort(points+1, points+n, smallerAngle);
    hull[0].x = start.x; hull[0].y = start.y; hull[1].x = points[1].x; hull[1].y = points[1].y;
    points[n].x = start.x; points[n].y = start.y;
    for(int i = 2; i < n; i++){
        while(top >= 1 && !ccw(hull[top-1], hull[top], points[i])) top--;
        top++; hull[top].x = points[i].x; hull[top].y = points[i].y;
    }
    return top;
}

double area(Point a, Point b, Point c){ return fabs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2.0; }
double signedArea(Point a, Point b, Point c){ return (a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2.0; }

int solveIt(Point inside [50010], Point hull [50010], int hullSize){
    start.x = hull[0].x; start.y = hull[0].y;
    int ret = 0;
    //for(int i = 0; i < hullSize; i++) cout << hull[i].x << " " << hull[i].y << endl;
    for(int aindex = 0; aindex < N; aindex++){
        int hindex = hullSize-1, lo = 0, hi = hullSize-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(signedArea(start, hull[mid], inside[aindex]) > -epsilon){
                hindex = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        //double check = area(start, hull[hindex], hull[hindex+1])-area(inside[aindex], hull[hindex], hull[hindex+1])-
        //                area(inside[aindex], hull[hindex], start)-area(inside[aindex], start, hull[hindex+1]);
        double check = area(start, hull[hindex], hull[hindex+1])-area(inside[aindex], hull[hindex], hull[hindex+1])-
                        area(inside[aindex], hull[hindex], start)-area(inside[aindex], hull[hindex+1], start);
        if(fabs(check) < epsilon) ret++;
        //else cout << inside[aindex].x << " " << inside[aindex].y << endl;
    }
    return ret;
}

int main(){
    freopen("curling.in", "r", stdin); freopen("curling.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lf %lf", &oriA[i].x, &oriA[i].y);
        dupeA[i].x = oriA[i].x; dupeA[i].y = oriA[i].y;
    }
    for(int i = 0; i < N; i++){
        scanf("%lf %lf", &oriB[i].x, &oriB[i].y);
        dupeB[i].x = oriB[i].x; dupeB[i].y = oriB[i].y;
    }
    numHullA = findHull(dupeA, hullA); numHullB = findHull(dupeB, hullB);
    cout << solveIt(oriB, hullA, numHullA) << " " << solveIt(oriA, hullB, numHullB) << '\n';
    return 0;
}
