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

int N, id = 0, lastSeen [50010], tree [100010];
double d;
vector<pair<double, int>> intersections;
long long ret = 0;

void add(int pos, int add){
    while(pos < 100010){
        tree[pos] += add;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long sum = 0;
    while(pos > 0){
        sum += (long long)tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> d; memset(lastSeen, -1, sizeof(lastSeen)); memset(tree, 0, sizeof(tree));
    for(int i = 0; i < N; i++){
        double a, b, c; cin >> a >> b >> c;
        if(c*c >= d*d*(a*a+b*b)) continue;
        double y1 = (-a*sqrt((a*a+b*b)*d*d-c*c)-b*c)/(a*a+b*b), y2 = (a*sqrt((a*a+b*b)*d*d-c*c)-b*c)/(a*a+b*b);
        double x1, x2;
        if(a > epsilon || a < -epsilon) x1 = -(b*y1+c)/a, x2 = -(b*y2+c)/a;
        else x1 = -sqrt(d*d-y1*y1), x2 = sqrt(d*d-y2*y2);
        intersections.push_back(make_pair(atan2(y1, x1), id)); intersections.push_back(make_pair(atan2(y2, x2), id));
        id++;
    }
    sort(intersections.begin(), intersections.end());
    for(int i = 0; i < intersections.size(); i++){
        if(lastSeen[intersections[i].second] == -1){
            lastSeen[intersections[i].second] = i+1;
            add(i+1, 1);
        }
        else{
            ret += query(i+1)-query(lastSeen[intersections[i].second]);
            add(lastSeen[intersections[i].second], -1);
        }
    }
    cout << ret << '\n';
    return 0;
}
