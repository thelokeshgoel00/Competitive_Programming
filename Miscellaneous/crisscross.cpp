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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

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

Point operator-(Point l, Point r){ return Point(l.x-r.x, l.y-r.y, l.denom); }

long long signedArea(Point a, Point b, Point c){ return (b.y-a.y)*(c.x-a.x)-(b.x-a.x)*(c.y-a.y); }

int N;
Line lines [1010];
set<pair<pair<long long, long long>, long long>> lol;

Point getIntersection(Point a, Point b, Point c, Point d){
  return (abs(signedArea(a, b, c))*d+abs(signedArea(a, b, d))*c)/
  (abs(signedArea(a, b, c))+abs(signedArea(a, b, d)));
}

pair<long long, long long> getSlope(int i){
    long long dy = lines[i].a.y-lines[i].b.y;
    long long dx = lines[i].a.x-lines[i].b.x;
    if(dx < 0){ dy *= -1; dx *= -1; }
    long long g = __gcd(abs(dx), abs(dy));
    dy /= g; dx /= g;
    return mp(dy, dx);
}

bool infiniteIntersect(int i, int j){
    pair<long long, long long> islope = getSlope(i), jslope = getSlope(j);
    if(islope != jslope || signedArea(lines[i].a, lines[i].b, lines[j].a) != 0 || signedArea(lines[i].a, lines[i].b, lines[j].b) != 0) return false;
    if(islope.s == 0 && jslope.s == 0){
        vector<pair<long long, int>> quad;
        quad.pb(mp(lines[i].a.y, 0)); quad.pb(mp(lines[i].b.y, 0));
        quad.pb(mp(lines[j].a.y, 1)); quad.pb(mp(lines[j].b.y, 1));
        sort(quad.begin(), quad.end());
        if(quad[0].s == quad[2].s && quad[1].f == quad[2].f) swap(quad[1], quad[2]);
        if(quad[0].s == quad[1].s && quad[2].f >= quad[1].f) return false;
        return true;
    }
    else{
        vector<pair<long long, int>> quad;
        quad.pb(mp(lines[i].a.x, 0)); quad.pb(mp(lines[i].b.x, 0));
        quad.pb(mp(lines[j].a.x, 1)); quad.pb(mp(lines[j].b.x, 1));
        sort(quad.begin(), quad.end());
        if(quad[0].s == quad[2].s && quad[1].f == quad[2].f) swap(quad[1], quad[2]);
        if(quad[0].s == quad[1].s && quad[2].f >= quad[1].f) return false;
        return true;
    }
}

bool checkEndpoint(int i, int j){
    set<Point> quad;
    quad.insert(lines[i].a); quad.insert(lines[i].b);
    quad.insert(lines[j].a); quad.insert(lines[j].b);
    return quad.size() == 3;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> lines[i].a.x >> lines[i].a.y >> lines[i].b.x >> lines[i].b.y;
        if(lines[i].a < lines[i].b) swap(lines[i].a, lines[i].b);
        for(int j = 0; j < i; j++){
            if(infiniteIntersect(i, j)){
                cout << "-1\n";
                return 0;
            }
            if(checkEndpoint(i, j)){
                if(lines[i].a == lines[j].a) lol.insert(mp(mp(lines[i].a.x, lines[i].a.y), lines[i].a.denom));
                if(lines[i].a == lines[j].b) lol.insert(mp(mp(lines[i].a.x, lines[i].a.y), lines[i].a.denom));
                if(lines[i].b == lines[j].a) lol.insert(mp(mp(lines[i].b.x, lines[i].b.y), lines[i].b.denom));
                if(lines[i].b == lines[j].b) lol.insert(mp(mp(lines[i].b.x, lines[i].b.y), lines[i].b.denom));
                continue;
            }
            long long aa = signedArea(lines[i].a, lines[i].b, lines[j].a);
            long long bb = signedArea(lines[i].a, lines[i].b, lines[j].b);
            long long cc = signedArea(lines[j].a, lines[j].b, lines[i].a);
            long long dd = signedArea(lines[j].a, lines[j].b, lines[i].b);
            if(aa > bb) swap(aa, bb);
            if(cc > dd) swap(cc, dd);
            if(!(aa <= 0 && bb >= 0) || !(cc <= 0 && dd >= 0)) continue;
            if(aa == 0 && bb == 0){
                Point ee = max(lines[i].a, lines[j].a), ff = min(lines[i].b, lines[j].b);
                if(ee == ff) lol.insert(make_pair(make_pair(ee.x, ee.y), ee.denom));
                continue;
            }
            Point p = getIntersection(lines[i].a, lines[i].b, lines[j].a, lines[j].b);
            lol.insert(make_pair(make_pair(p.x, p.y), p.denom));
        }
    }
    cout << lol.size() << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
