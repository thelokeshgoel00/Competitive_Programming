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
#define epsilon 1e-9
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

struct Circle{
    double x, y, r;
    Circle(){ x = y = r = 0; }
    double dist(Circle other){ return sqrt(pow(x-other.x, 2)+pow(y-other.y, 2)); }
    pair<double, double> fixIt(pair<double, double> range){
		if(range.f < 0) range.f += 2*PI;
		if(range.s < 0) range.s += 2*PI;
		double start = min(range.f, range.s);
		double endy = max(range.f, range.s);
		if(endy-start > PI) swap(start, endy);
		if(endy < start) endy += 2*PI;
		range.f = start; range.s = endy;
		return range;
	}
    vector<pair<double, double>> getRange(Circle other){
        double D = dist(other);
		double offset1 = asin(abs(r-other.r)/D);
		double offset2 = asin((r+other.r)/D);
		double baseAngle = atan2(other.y-y, other.x-x);
		if(baseAngle < 0) baseAngle += 2*PI;
		pair<double, double> angle1, angle2;
		if(r <= other.r){
			angle1.f = baseAngle - offset1 - PI/2;
			angle2.f = baseAngle + offset1 + PI/2;
		}
		else{
			angle1.f = baseAngle - PI/2 + offset1;
			angle2.f = baseAngle + PI/2 - offset1;
		}
		angle1.s = baseAngle - PI/2 + offset2;
		angle2.s = baseAngle + PI/2 - offset2;
		angle1 = fixIt(angle1); angle2 = fixIt(angle2);
        vector<pair<double, double>> ret(2);
        ret[0] = angle1; ret[1] = angle2;
        return ret;
    }
};

int N, ret = 1;
Circle circles [2010];

int maxHit(vector<pair<double, double>> ranges){
    double maxAngle = 0;
    for(int i = 0; i < ranges.size(); i++) maxAngle = max(maxAngle, ranges[i].s);
    vector<pair<double, int>> events;
    for(int i = 0; i < ranges.size(); i++) {
        events.pb(mp(ranges[i].f, -1));
        events.pb(mp(ranges[i].s, 1));
        if(ranges[i/4].f+2*PI < maxAngle){
            events.pb(mp(ranges[i].f+2*PI, -1));
            events.pb(mp(ranges[i].s+2*PI, 1));
        }
    }
    sort(events.begin(), events.end());
    int curr = 0, maxi = 0;
    for(int i = 0; i < events.size(); i++) {
        curr -= events[i].s;
        maxi = max(maxi, curr);
    }
    return maxi;
}

int main(){
    //freopen("training.in", "r", stdin); freopen("training.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> circles[i].x >> circles[i].y >> circles[i].r;
    for(int i = 0; i < N; i++){
        vector<pair<double, double>> ranges;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            vector<pair<double, double>> temp = circles[i].getRange(circles[j]);
            ranges.pb(temp[0]); ranges.pb(temp[1]);
        }
        ret = max(ret, maxHit(ranges)+1);
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
