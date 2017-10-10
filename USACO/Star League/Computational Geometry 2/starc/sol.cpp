#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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

int N, M;
pair<pair<double, double>, double> lines [350];
vector<pair<double, double>> vertices;

pair<double, double> solve(pair<pair<double, double>, double> a, pair<pair<double, double>, double> b){
    double det = a.first.first*b.first.second-a.first.second*b.first.first;
    if(fabs(det) < epsilon) return make_pair(INF, INF);
    return make_pair((a.first.second*b.second-a.second*b.first.second)/det, (a.second*b.first.first-a.first.first*b.second)/det);
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        char winnie; double a1, a2, a3, b1, b2, b3;
		    cin >> winnie >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
		    if(winnie == 'J') lines[i] = {{a1-b1, a2-b2}, a3-b3};
		    else lines[i] = {{b1-a1, b2-a2}, b3-a3};
    }
    lines[N++] = {{100.0, 0.0}, -1.0}; lines[N++] = {{0.0, 100.0}, -1.0};
    lines[N++] = {{-1.0, 0.0}, 100.0};  lines[N++] = {{0.0, -1.0}, 100.0};
	  lines[N++] = {{-1.0, 100.0}, 0.0}; lines[N++] = {{100.0, -1.0}, 0.0};
	  for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++){
            pair<double, double> now = solve(lines[i], lines[j]);
            if(now.first == INF) continue;
            bool ok = true;
            for(int k = 0; k < N; k++)
                if(now.first*lines[k].first.first+now.second*lines[k].first.second+lines[k].second < -epsilon){
                    ok = false;
                    break;
                }
            if(ok) vertices.push_back(now);
        }
    for(int i = 0; i < M; i++){
        double a1, a2, a3, b1, b2, b3;
        cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
		    bool johnWin = false, bessieWin = false;
		    for(int j = 0; j < vertices.size(); j++){
            double comp = vertices[j].first*(a1-b1)+vertices[j].second*(a2-b2)+(a3-b3);
            if(comp <= epsilon) bessieWin = true;
            if(comp >= -epsilon) johnWin = true;
        }
        if(bessieWin && johnWin) cout << "U\n";
        else if(bessieWin) cout << "B\n";
        else if(johnWin) cout << "J\n";
        else cerr << "Oops!...I Did It Again\n";
    }
    return 0;
}
