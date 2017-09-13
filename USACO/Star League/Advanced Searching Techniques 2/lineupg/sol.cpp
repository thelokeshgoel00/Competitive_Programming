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
#define INF 1000000000000
#define MOD 1000000007

int N, M, vals [2][50010], trees [2][200010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R, int num){
    if(L == R){
        trees[num][p] = vals[num][L];
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2, num); build(ri, (L+R)/2+1, R, num);
    trees[num][p] = max(trees[num][li], trees[num][ri]);
}

long long query(int p, int L, int R, int i, int j, int num){
    if(L > R || j < L || i > R) return -1000001;
    if(L >= i && R <= j) return trees[num][p];
    int li = left(p), ri = right(p);
    return max(query(li, L, (L+R)/2, i, j, num), query(ri, (L+R)/2+1, R, i, j, num));
}

int main(){
    //freopen("grass.in", "r", stdin); freopen("grass.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){ scanf("%d", &vals[0][i]); vals[1][i] = -vals[0][i]; }
    build(1, 0, N-1, 0); build(1, 0, N-1, 1);
    for(int i = 0; i < M; i++){
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        printf("%d\n", query(1, 0, N-1, a, b, 0)+query(1, 0, N-1, a, b, 1));
        //cout << query(1, 0, N-1, a, b, 0) << " " << query(1, 0, N-1, a, b, 1) << endl;
    }
    return 0;
}
