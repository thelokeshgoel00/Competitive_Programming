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

struct Line{
    int a, b, c;
    Line(){ a = 1; b = 0; c = 0; }
    Line(int x, int y, int z){ a = x; b = y; c = z; }
    bool operator<(const Line &other) const{
        return make_pair(make_pair(a, b), c) < make_pair(make_pair(other.a, other.b), other.c);
    }
    bool operator==(const Line &other) const{
        return make_pair(make_pair(a, b), c) == make_pair(make_pair(other.a, other.b), other.c);
    }
    int GCF(int a, int b){
        a = abs(a); b = abs(b);
        if(b == 0) return a;
        return GCF(b, a%b);
    }
    void reduce(){
        int gcf = GCF(a, GCF(b, c));
        if(make_pair(make_pair(a, b), c) < make_pair(make_pair(0, 0), 0)) gcf *= -1;
        a /= gcf; b /= gcf; c /= gcf;
    }
};

int N, ret = 0;
pair<int, int> points [1010];
set<pair<int, int>> possible;
set<Line> lines;

pair<int, int> intersect(Line LA, Line LB){
    int det = LA.a*LB.b-LA.b*LB.a;
    if(abs(det) == 0) return make_pair(-100001, -100001);
    int x = LB.b*LA.c-LA.b*LB.c;
    int y = -LB.a*LA.c+LA.a*LB.c;
    if(x%det != 0 || y%det != 0) return make_pair(-100001, -100001);
    return make_pair(x/det, y/det);
}

int main() {
    freopen("symmetry.in", "r", stdin); freopen("symmetry.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &points[i].first, &points[i].second);
        possible.insert(points[i]);
    }
    for(int i = 0; i < 2; i++)
        for(int j = i+1; j < N; j++){
            Line L1(points[j].second-points[i].second, points[i].first-points[j].first,
                    (points[j].second-points[i].second)*points[i].first+(points[i].first-points[j].first)*points[i].second);
            Line L2((points[j].first-points[i].first)*2, (points[j].second-points[i].second)*2,
                    points[j].first*points[j].first-points[i].first*points[i].first+
                    points[j].second*points[j].second-points[i].second*points[i].second);
            L1.reduce(); L2.reduce();
            lines.insert(L1); lines.insert(L2);
        }
    for(Line L : lines){
        bool flag = true;
        for(int j = 0; j < N; j++){
            Line LA(L.a, L.b, 2*L.c-L.a*points[j].first-L.b*points[j].second);
            Line LB(-L.b, L.a, -L.b*points[j].first+L.a*points[j].second);
            if(possible.find(intersect(LA, LB)) == possible.end()){
                flag = false;
                break;
            }
        }
        if(flag) ret++;
    }
    cout << ret << '\n';
    return 0;
}
