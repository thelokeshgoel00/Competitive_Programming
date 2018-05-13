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

struct Point{
    double x, y;
    bool isCannon;
    Point(){ x = y = 0; isCannon = false; }
    Point(double a, double b, bool c){ x = a; y = b; isCannon = c; }
    double dist(Point other){
        double d = sqrt(pow(x-other.x, 2)+pow(y-other.y, 2));
        double tiempo = d/5;
        if(isCannon){
            if(d > 30 && d < 50) tiempo = 2 + (50-d)/5;
            else if(d >= 50) tiempo -= 8;
        }
        return tiempo;
    }
};

int numCannons;
Point st, en, cannons [110];
double floyd [110][110], ret;

int main(){
    //freopen("nocow.in", "r", stdin); freopen("nocow.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> st.x >> st.y >> en.x >> en.y >> numCannons; ret = st.dist(en);
    for(int i = 0; i < numCannons; i++){
        cin >> cannons[i].x >> cannons[i].y;
        cannons[i].isCannon = true;
    }
    for(int i = 0; i < numCannons; i++){
        floyd[i][i] = 0;
        for(int j = i+1; j < numCannons; j++){
            double temp = cannons[j].dist(cannons[i]);
            floyd[i][j] = temp; floyd[j][i] = temp;
        }
    }
    for(int k = 0; k < numCannons; k++)     
        for(int i = 0; i < numCannons; i++)     
            for(int j = 0; j < numCannons; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k]+floyd[k][j]);
    for(int i = 0; i < numCannons; i++)
        for(int j = 0; j < numCannons; j++)
            ret = min(ret, floyd[i][j]+st.dist(cannons[i])+cannons[j].dist(en));
    cout << ret << '\n';
}
