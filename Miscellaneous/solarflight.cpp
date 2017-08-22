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

#define PI 3.141592653589793
#define epsilon 0.000000001

struct Plane{
    double a, b;
    long long interference;
    int id;
    Plane(){ a = -1; b = -1; interference = -1ll; id = -1; }
    bool operator<(const Plane &other) const{ return a > other.a; }
};

struct Intersection{
    double x;
    int otherID;
    long long interference;
    Intersection(){ x = -1; otherID = -1; interference = -1ll; }
    Intersection(double a, int b, long long c){ x = a; otherID = b; interference = c; }
    Intersection(double a){ x = a; }
    bool operator<(const Intersection &other) const{
        if(fabs(x-other.x) < epsilon) return interference < other.interference;
        return x < other.x;
    }
};

int numFlights, numQueries, flightIndex [2050];
double maxX, distRange;
long long trees [2050][8050], cumulativeInterference = 0ll;
vector<Plane> planes;
vector<Intersection> intersections [2010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R, int num){
    if(L == R){
        trees[num][p] = intersections[num][L].interference;
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2, num); build(ri, (L+R)/2+1, R, num);
    trees[num][p] = max(trees[num][li], trees[num][ri]);
}

long long query(int p, int L, int R, int i, int j, int num){
    if(L > R || j < L || i > R) return 0;
    if(L >= i && R <= j) return trees[num][p];
    int li = left(p), ri = right(p);
    return max(query(li, L, (L+R)/2, i, j, num), query(ri, (L+R)/2+1, R, i, j, num));
}

int main() {
    scanf("%lf %lf %d %d", &maxX, &distRange, &numFlights, &numQueries);
    for(int i = 0; i < numFlights; i++){
        planes.push_back(Plane()); planes[i].id = i;
        scanf("%lf %lf %lld", &planes[i].a, &planes[i].b, &planes[i].interference);
    }
    sort(planes.begin(), planes.end());
    for(int i = 0; i < numFlights; i++){
        flightIndex[planes[i].id] = i;
        for(int j = i+1; j < numFlights; j++){
            if((planes[i].a > planes[j].a && planes[i].b > planes[j].b) || (planes[i].a < planes[j].a && planes[i].b < planes[j].b)) continue;
            double where = maxX*(planes[j].a-planes[i].a)/(planes[i].b-planes[i].a-planes[j].b+planes[j].a);
            long long interfere1 = planes[j].interference, interfere2 = planes[i].interference;
            if(planes[j].b < planes[i].b){ interfere1 *= -1; interfere2 *= -1; }
            intersections[i].push_back(Intersection(where, j, interfere1));
            intersections[j].push_back(Intersection(where, i, -interfere2));
        }
        intersections[i].push_back(Intersection(0, -1, cumulativeInterference));
        sort(intersections[i].begin(), intersections[i].end());
        for(int j = 1; j < (int)intersections[i].size(); j++)
            intersections[i][j].interference += intersections[i][j-1].interference;
        //intersections[i].push_back(Intersection(maxX, -1, intersections[i].back().interference));
        build(1, 0, intersections[i].size()-1, i);
        cumulativeInterference += planes[i].interference;
    }
    /*cout << endl;
    for(int i = 0; i < numFlights; i++){
        for(int j = 0; j < intersections[i].size(); j++){
            cout << intersections[i][j].interference << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    for(int i = 0; i < numQueries; i++){
        int flightNum; double startRange; scanf("%d %lf", &flightNum, &startRange);
        flightNum = flightIndex[flightNum-1];
        /*int lolo = 0, lohi = intersections[flightNum].size()-1, lindex = 0;
        while(lolo <= lohi){
            int mid = (lolo+lohi)/2;
            if(intersections[flightNum][mid].x < startRange){
                lindex = mid;
                lolo = mid+1;
            }
            else lohi = mid-1;
        }
        int hilo = 0, hihi = intersections[flightNum].size()-1, hindex = hihi;
        while(hilo <= hihi){
            int mid = (hilo+hihi)/2;
            if(intersections[flightNum][mid].x < startRange+distRange){
                hindex = mid;
                hilo = mid+1;
            }
            else hihi = mid-1;
        }*/
        int lindex = max(0, int(upper_bound(intersections[flightNum].begin(), intersections[flightNum].end(), Intersection(startRange))-
                         intersections[flightNum].begin()-1));
        int hindex = max(0, int(upper_bound(intersections[flightNum].begin(), intersections[flightNum].end(), Intersection(startRange+distRange))-intersections[flightNum].begin()-1));
        printf("%lld\n", query(1, 0, intersections[flightNum].size()-1, lindex, hindex, flightNum));
    }
    return 0;
}
