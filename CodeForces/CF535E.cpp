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
#define epsilon 1e-22
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

struct Point{
    int ox, oy;
    double x, y;
    Point(){ ox = oy = 0; x = y = 0; }
    Point(int a, int b){ ox = a; oy = b; x = 1.0/a; y = 1.0/b; }
    double dist(Point other){ return pow(x-other.x, 2.0)+pow(y-other.y, 2.0); }
};

int N;
map<pair<int, int>, vector<int>> mappy;
vector<Point> points, hull;
Point lowest, leftmost;
vector<int> ret;

bool lowComp(Point a, Point b){ return mp(a.y, a.x) < mp(b.y, b.x); }
bool leftComp(Point a, Point b){ return mp(a.x, a.y) < mp(b.x, b.y); }

double getCross(Point a, Point b, Point c){ return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x); }
bool normalComp(Point a, Point b){
    double cross = getCross(a, b, lowest);
    if(fabs(cross) < epsilon) return lowest.dist(a) < lowest.dist(b);
    return cross < epsilon;
}

int main(){
    //freopen("cowfood.in", "r", stdin); freopen("cowfood.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        mappy[mp(a, b)].pb(i+1);
    }
    if(mappy.size() == 1){
        for(int i = 1; i <= N; i++) cout << i << ' ';
        cout << '\n';
        return 0;
    }
    for(auto lol : mappy){
        pair<int, int> now = lol.f;
        points.pb(Point(now.f, now.s));
    }
    lowest = *min_element(points.begin(), points.end(), lowComp);
    leftmost = *min_element(points.begin(), points.end(), leftComp);
    if(mp(lowest.ox, lowest.oy) == mp(leftmost.ox, leftmost.oy)){
        for(int i : mappy[mp(lowest.ox, lowest.oy)]) cout << i << ' ';
        cout << '\n';
        return 0;
    }
    sort(points.begin(), points.end(), normalComp);
    for(int i = 0; i < 2; i++) hull.pb(points[i]);
    for(int i = 2; i < points.size(); i++){
        if(mp(hull.back().ox, hull.back().oy) == mp(leftmost.ox, leftmost.oy)) break;
        while(hull.size() > 1 && getCross(hull[hull.size()-1], points[i], hull[hull.size()-2]) > epsilon) hull.pop_back();
        hull.pb(points[i]);
    }
    for(Point p : hull)
        for(int i : mappy[mp(p.ox, p.oy)])
            ret.pb(i);
    sort(ret.begin(), ret.end());
    for(int i : ret) cout << i << ' ';
    cout << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
