//http://www.problemvault.com/#problem130

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

struct Line{
    pair<double, double> p, q;
    double slope;
    Line(){}
    bool operator<(const Line &other) const{
        if(p.first == other.p.first) return q.first < other.q.first;
        return p.first < other.p.first;
    }
    double evalAt(double x) const{ return (x-p.first)*slope+p.second; }
};

struct vertComp {
    double use;
    vertComp(double kek){ use = kek; }
    bool operator()(const Line &a, const Line &b) const{
        return a.evalAt(use) < b.evalAt(use);
    }
};

int N, numLines, pos, ret;
pair<double, double> points [110];
Line lines [110];
vector<Line> active;

int gentleFloor(double value){
    int floored = (int)floor(value);
    if(value-floored > 1.0-epsilon) return (int)round(value);
    return floored;
}

int gentleCeil(double value){
    int ceiling = (int)ceil(value);
    if(ceiling-value > 1.0-epsilon) return (int)round(value);
    return ceiling;
}

int main(){
    //freopen("tied.in", "r", stdin); freopen("tied.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(true){
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;
        numLines = 0;
        for(int i = 0; i < N; i++){
            int j = (i+1)%N;
            if(points[i].first == points[j].first) continue;
            pair<double, double> a = points[i], b = points[j];
            if(a.first < b.first){
                lines[numLines].p = make_pair(a.first, a.second); 
                lines[numLines].q = make_pair(b.first, b.second);
            }
            else{
                lines[numLines].q = make_pair(a.first, a.second); 
                lines[numLines].p = make_pair(b.first, b.second);
            }
            lines[numLines].slope = (lines[numLines].q.second-lines[numLines].p.second)/
                (lines[numLines].q.first-lines[numLines].p.first);
            numLines++;
        }
        sort(lines, lines+numLines); active.clear();
        pos = 0; ret = 0;
        for(double x = -99.5; x <= 99.5; x++){
            while(pos < numLines && lines[pos].p.first < x){
                active.push_back(lines[pos]);
                pos++;
            }
            for(int i = active.size()-1; i > -1; i--)
                if(active[i].q.first < x)
                    active.erase(active.begin()+i);
            sort(active.begin(), active.end(), vertComp(x));
            auto it = active.begin();
            double li = x-0.5, ri = x+0.5;
            while(it != active.end()){
                Line v = *it; it++;
                if(it == active.end()) break;
                Line u = *it; it++;
                double mu = u.slope, mv = v.slope;
                int upper = gentleFloor(min(u.evalAt(li), u.evalAt(ri)));
                int lower = gentleCeil(max(v.evalAt(li), v.evalAt(ri)));
                ret += max(0, upper-lower);
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
