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

#define PI 3.14159265358979
#define epsilon 0.00000000000005
#define INF 1000000000000000000
#define MOD 1000000007

struct Point{
    long long x, y, denom;
    Point(){ x = 0; y = 0; denom = 1; }
    Point(long long aa, long long bb, long long dd){ x = aa; y = bb; denom = dd; }
    bool operator==(const Point &other) const{ return x == other.x && y == other.y && denom == other.denom; }
    bool operator<(const Point &other) const{
        if(x == other.x) return y < other.y;
        return x < other.x; 
    }
};

struct Line{
    Point a, b;
    Line(){ a = Point(); b = Point(); }
};

Point simplify(Point x) {
    if (x.denom < 0) x.x *= -1, x.y *= -1, x.denom *= -1;
    long long g = abs(__gcd(__gcd(x.x, x.y), x.denom));
    x.x /= g, x.y /= g, x.denom /= g;
    return x;
}

Point operator*(long long x, Point y) {
    y.x *= x, y.y *= x;
    return y;
}

Point operator/(Point y, long long x){
    y.denom *= x;
    return simplify(y);
}

Point operator+(Point l, Point r){ return Point(l.x+r.x, l.y+r.y, l.denom); }

long long signedArea(Point a, Point b, Point c){ return (b.y-a.y)*(c.x-a.x)-(b.x-a.x)*(c.y-a.y); }

Point getIntersection(Point a, Point b, Point c, Point d){ 
  return (abs(signedArea(a, b, c))*d+abs(signedArea(a, b, d))*c)/
  (abs(signedArea(a, b, c))+abs(signedArea(a, b, d)));
}

int N;
Line lines [1010];
set<pair<pair<long long, long long>, long long>> kek;

int main(){
    //freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> lines[i].a.x >> lines[i].a.y >> lines[i].b.x >> lines[i].b.y;
        if(lines[i].a < lines[i].b) swap(lines[i].a, lines[i].b);
        for(int j = 0; j < i; j++){
            long long aa = signedArea(lines[i].a, lines[i].b, lines[j].a);
            long long bb = signedArea(lines[i].a, lines[i].b, lines[j].b);
            long long cc = signedArea(lines[j].a, lines[j].b, lines[i].a);
            long long dd = signedArea(lines[j].a, lines[j].b, lines[i].b);
            if(aa > bb) swap(aa, bb);
            if(cc > dd) swap(cc, dd);
            if(!(aa <= 0 && bb >= 0) || !(cc <= 0 && dd >= 0)) continue;
            if(aa == 0 && bb == 0){
                Point ee = max(lines[i].a, lines[j].a), ff = min(lines[i].b, lines[j].b);
                if(ee == ff) kek.insert(make_pair(make_pair(ee.x, ee.y), ee.denom));
                continue;
            }
            Point p = getIntersection(lines[i].a, lines[i].b, lines[j].a, lines[j].b);
            kek.insert(make_pair(make_pair(p.x, p.y), p.denom));
        }
    }
    cout << kek.size() << '\n';
    return 0;
}
