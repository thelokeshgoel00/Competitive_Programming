/*
ID: vamaddu1
PROG: rect1
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
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

struct Rectangle{
    int colorID, lx, ly, rx, ry;
    Rectangle(){ lx = ly = rx = ry = colorID = 0; }
    Rectangle(int a, int b, int c, int d, int e){
        lx = a; ly = b; rx = c; ry = d;
        colorID = e;
    }
};

int N, A, B, colorArea [2510];
Rectangle rectangles [1010];

bool isOutside(int lx, int ly, int rx, int ry, int pos){
    return pos <= N && (lx >= rectangles[pos].rx || rx <= rectangles[pos].lx ||
                        ly >= rectangles[pos].ry || ry <= rectangles[pos].ly);
}

void update(int lx, int ly, int rx, int ry, int id, int pos){
    while(isOutside(lx, ly, rx, ry, pos)) pos++;
    if(pos == N+1){
        colorArea[id] += (rx-lx)*(ry-ly);
        return;
    }
    if(lx < rectangles[pos].lx){
        update(lx, ly, rectangles[pos].lx, ry, id, pos+1);
        lx = rectangles[pos].lx;
    }
    if(rx > rectangles[pos].rx){
        update(rectangles[pos].rx, ly, rx, ry, id, pos+1);
        rx = rectangles[pos].rx;
    }
    if(ly < rectangles[pos].ly){
        update(lx, ly, rx, rectangles[pos].ly, id, pos+1);
        ly = rectangles[pos].ly;
    }
    if(ry > rectangles[pos].ry){
        update(lx, rectangles[pos].ry, rx, ry, id, pos+1);
        ry = rectangles[pos].ry;
    }
}


int main(){
    freopen("rect1.in", "r", stdin); freopen("rect1.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> A >> B >> N; memset(colorArea, 0, sizeof(colorArea));
    rectangles[0] = Rectangle(0, 0, A, B, 1);
    for(int i = 1; i <= N; i++){
        cin >> rectangles[i].lx >> rectangles[i].ly;
        cin >> rectangles[i].rx >> rectangles[i].ry;
        cin >> rectangles[i].colorID;
    }
    for(int i = N; i > -1; i--)
        update(rectangles[i].lx, rectangles[i].ly, rectangles[i].rx,
               rectangles[i].ry, rectangles[i].colorID, i+1);
    for(int i = 1; i < 2510; i++)
        if(colorArea[i] > 0)
            cout << i << " " << colorArea[i] << '\n';
    return 0;
}
