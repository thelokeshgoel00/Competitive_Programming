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
#include <bitset>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

struct Mat {
    double **d;
    int a, b;

    Mat(){ a = b = 0; }
    Mat(int x, int y){
        a = x, b = y;
        d = new double *[a];
        for(int i = 0; i < a; i++){
            d[i] = new double [b];
            for(int j = 0; j < b; j++) d[i][j] = 0.0;
        }
    }
    Mat operator+(const Mat &m) {
        Mat r(a, b);
        for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                r.d[i][j] = (d[i][j]+m.d[i][j]);
        return r;
    }
    vector<double> operator*(const vector<double> &v) {
        vector<double> r(a, 0.0);
        for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                r[i] += d[i][j]*v[j];
        return r;
    }
    Mat operator*(const Mat& m) {
        Mat r(a, m.b);
        for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                for(int k = 0; k < m.b; k++)
                    r.d[i][k] = (r.d[i][k]+d[i][j]*m.d[j][k]);
        return r;
    }
    Mat operator^(long long p) {
        Mat r(a, a), base(*this);
        for(int i = 0; i < a; i++) r.d[i][i] = 1.0;
        while(p > 0){
            if(p%2 == 1) r = r*base;
            base = base*base;
            p /= 2;
        }
        return r;
    }
};

int N, Q;
pair<int, int> points [210];
bool seen [210][210];
vector<vector<int>> groups;
vector<int> locs [210];
Mat prob [14];
double ret;

int cross(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    return (a.first-b.first)*(a.second-c.second)-(a.second-b.second)*(a.first-c.first);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(seen, false, sizeof(seen));
    for(int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++){
            if(seen[i][j]) continue;
            vector<int> lel; lel.push_back(i); lel.push_back(j);
            for(int k = j+1; k < N; k++)
                if(cross(points[i], points[j], points[k]) == 0)
                    lel.push_back(k);
            for(int x : lel){
                locs[x].push_back(groups.size());
                for(int y : lel) seen[x][y] = true;
            }
            groups.push_back(lel);
        }
    prob[0] = Mat(N, N);
    for(int i = 0; i < N; i++)
        for(int j : locs[i])
            for(int k : groups[j])
                prob[0].d[i][k] += 1.0/(double)(locs[i].size())/(double)(groups[j].size());
    for(int i = 1; i < 14; i++) prob[i] = prob[i-1]*prob[i-1];
    cin >> Q;
    for(int q = 0; q < Q; q++){
        int t, m; cin >> t >> m; t--; m--; ret = 0.0;
        vector<double> v(N, 0.0); v[t] = 1.0;
        for(int i = 0; i < 14; i++)
            if((m&(1<<i)) > 0)
                v = prob[i]*v;
        for(vector<int> g : groups){
            double sum = 0.0;
            for(int j : g) sum += v[j];
            ret = max(ret, sum/(double)(g.size()));
        }
        cout << ret << '\n';
    }
    return 0;
}
