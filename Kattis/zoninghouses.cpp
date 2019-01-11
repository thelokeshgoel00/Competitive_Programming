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

int N, Q, vals [4][100010];
pair<int, int> trees [4][400010];
//minX, maxX, minY, maxY

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R, int num){
    if(L == R){
        trees[num][p] = make_pair(vals[num][L], L);
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2, num); build(ri, (L+R)/2+1, R, num);
    trees[num][p] = max(trees[num][li], trees[num][ri]);
}

void update(int p, int L, int R, int place, int val, int num){
    if(L > R || L > place || R < place) return;
    if(L == R){
        trees[num][p] = make_pair(val, L);
        return;
    }
    int li = left(p); int ri = right(p);
    update(li, L, (L+R)/2, place, val, num); update(ri, (L+R)/2+1, R, place, val, num);
    trees[num][p] = max(trees[num][li], trees[num][ri]);
}

pair<int, int> query(int p, int L, int R, int i, int j, int num){
    if(L > R || j < L || i > R) return make_pair(-1e9, -1);
    if(L >= i && R <= j) return trees[num][p];
    int li = left(p), ri = right(p);
    return max(query(li, L, (L+R)/2, i, j, num), query(ri, (L+R)/2+1, R, i, j, num));
}

int main(){
    //freopen("dirtraverse.in", "r", stdin); freopen("dirtraverse.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        vals[0][i] = -x; vals[1][i] = x;
        vals[2][i] = -y; vals[3][i] = y;
    }
    for(int i = 0; i < 4; i++) build(1, 0, N-1, i);
    for(int qq = 0; qq < Q; qq++){
        int a, b; cin >> a >> b; a--; b--;
        long long sideLen = INF;
        pair<int, int> trueLeftX = query(1, 0, N-1, a, b, 0), trueRightX = query(1, 0, N-1, a, b, 1);
        pair<int, int> trueLeftY = query(1, 0, N-1, a, b, 2), trueRightY = query(1, 0, N-1, a, b, 3);
        pair<int, int> nextLeftX, nextRightX, nextLeftY, nextRightY;

        for(int i = 0; i < 4; i++) update(1, 0, N-1, trueLeftX.second, -1e9, i);
        nextLeftX = query(1, 0, N-1, a, b, 0), nextRightX = query(1, 0, N-1, a, b, 1);
        nextLeftY = query(1, 0, N-1, a, b, 2), nextRightY = query(1, 0, N-1, a, b, 3);
        sideLen = min(sideLen, (long long)max(nextLeftX.first+nextRightX.first, nextLeftY.first+nextRightY.first));
        for(int i = 0; i < 4; i++) update(1, 0, N-1, trueLeftX.second, vals[i][trueLeftX.second], i);

        for(int i = 0; i < 4; i++) update(1, 0, N-1, trueRightX.second, -1e9, i);
        nextLeftX = query(1, 0, N-1, a, b, 0), nextRightX = query(1, 0, N-1, a, b, 1);
        nextLeftY = query(1, 0, N-1, a, b, 2), nextRightY = query(1, 0, N-1, a, b, 3);
        sideLen = min(sideLen, (long long)max(nextLeftX.first+nextRightX.first, nextLeftY.first+nextRightY.first));
        for(int i = 0; i < 4; i++) update(1, 0, N-1, trueRightX.second, vals[i][trueRightX.second], i);

        for(int i = 0; i < 4; i++) update(1, 0, N-1, trueLeftY.second, -1e9, i);
        nextLeftX = query(1, 0, N-1, a, b, 0), nextRightX = query(1, 0, N-1, a, b, 1);
        nextLeftY = query(1, 0, N-1, a, b, 2), nextRightY = query(1, 0, N-1, a, b, 3);
        sideLen = min(sideLen, (long long)max(nextLeftX.first+nextRightX.first, nextLeftY.first+nextRightY.first));
        for(int i = 0; i < 4; i++) update(1, 0, N-1, trueLeftY.second, vals[i][trueLeftY.second], i);

        for(int i = 0; i < 4; i++) update(1, 0, N-1, trueRightY.second, -1e9, i);
        nextLeftX = query(1, 0, N-1, a, b, 0), nextRightX = query(1, 0, N-1, a, b, 1);
        nextLeftY = query(1, 0, N-1, a, b, 2), nextRightY = query(1, 0, N-1, a, b, 3);
        sideLen = min(sideLen, (long long)max(nextLeftX.first+nextRightX.first, nextLeftY.first+nextRightY.first));
        for(int i = 0; i < 4; i++) update(1, 0, N-1, trueRightY.second, vals[i][trueRightY.second], i);
        cout << sideLen << '\n';
    }
    return 0;
}
