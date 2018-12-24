/*
ID: vamaddu1
PROG: fence4
LANG: C++11
*/

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
    double x, y;
    Point(){ x = 0; y = 0; }
    Point(double a, double b){ x = a; y = b; }
    bool operator<(const Point &other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
    bool operator==(const Point &other) const{
        return fabs(x-other.x) < epsilon && fabs(y-other.y) < epsilon;
    }
};

int N, ret = 0;
Point observer, corners [210];
pair<Point, Point> fences [210];
bool seen [210];

double cross(Point a, Point b, Point c){ return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y); }

bool fenceIntersect(Point a, Point b, Point c, Point d){
    return cross(a, b, c)*cross(a, b, d) < -epsilon &&
            cross(c, d, a)*cross(c, d, b) < -epsilon;
}

bool normalIntersect(Point a, Point b, Point c, Point d){
    return cross(a, b, c)*cross(a, b, d) < epsilon &&
            cross(c, d, a)*cross(c, d, b) < epsilon;
}

int main(){
    freopen("fence4.in", "r", stdin); freopen("fence4.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N >> observer.x >> observer.y;
    for(int i = 0; i < N; i++) cin >> corners[i].x >> corners[i].y;
    for(int i = 0; i < N-2; i++) fences[i] = mp(corners[i], corners[i+1]);
    fences[N-2] = mp(corners[0], corners[N-1]); fences[N-1] = mp(corners[N-2], corners[N-1]);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < i; j++)
            if(fenceIntersect(fences[i].f, fences[i].s, fences[j].f, fences[j].s)){
                cout << "NOFENCE\n";
                return 0;
            }
    for(int i = 0; i < N; i++){
        Point temp = fences[i].f;
        double dx = (fences[i].s.x-fences[i].f.x)/500;
        double dy = (fences[i].s.y-fences[i].f.y)/500;
        for(int j = 0; j <= 500; j++){
            bool good = true;
            for(int k = 0; k < N; k++){
                if(i == k) continue;
                if(normalIntersect(observer, temp, fences[k].f, fences[k].s)){
                    good = false;
                    break;
                }
            }
            if(good){
                seen[i] = fabs(cross(observer, fences[i].f, fences[i].s)) > epsilon;
                ret += seen[i]; break;
            }
            temp.x += dx; temp.y += dy;
        }
    }
    cout << ret << '\n';
    for(int i = 0; i < N; i++)
        if(seen[i])
            cout << fences[i].f.x << ' ' << fences[i].f.y << ' ' <<
                fences[i].s.x << ' ' << fences[i].s.y << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
