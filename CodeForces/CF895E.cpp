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
#include <cstring>
#include <sstream>
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

struct Node{
    double sum, lazyMult, lazyAdd;
    Node(){ sum = 0.0; lazyMult = 1.0; lazyAdd = 0.0; }
};

int N, Q;
double original [100010];
Node tree [400010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void pushDown(int p, int L, int R){
    tree[p].sum = tree[p].sum*tree[p].lazyMult+tree[p].lazyAdd*(double)(R-L+1);
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].lazyMult *= tree[p].lazyMult; tree[li].lazyAdd *= tree[p].lazyMult;
        tree[ri].lazyMult *= tree[p].lazyMult; tree[ri].lazyAdd *= tree[p].lazyMult;
        tree[li].lazyAdd += tree[p].lazyAdd; tree[ri].lazyAdd += tree[p].lazyAdd;
    }
    tree[p].lazyMult = 1.0; tree[p].lazyAdd = 0.0;
}

double evalSum(int p, int L, int R){ return tree[p].sum*tree[p].lazyMult+tree[p].lazyAdd*(double)(R-L+1); }

void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p].sum = evalSum(li, L, (L+R)/2)+evalSum(ri, (L+R)/2+1, R);
}

void build(int p, int L, int R){
    if(L == R){
        tree[p].sum = original[L];
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].sum = tree[li].sum+tree[ri].sum;
}

double query(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return 0.0;
    if(L >= i && R <= j) return evalSum(p, L, R);
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    double ret = query(li, L, (L+R)/2, i, j)+query(ri, (L+R)/2+1, R, i, j);
    pullUp(p, L, R);
    return ret;
}

void updateMult(int p, int L, int R, int i, int j, double mult){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){
        tree[p].lazyMult *= mult; tree[p].lazyAdd *= mult;
        return;
    }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    updateMult(li, L, (L+R)/2, i, j, mult); updateMult(ri, (L+R)/2+1, R, i, j, mult);
    pullUp(p, L, R);
}

void updateAdd(int p, int L, int R, int i, int j, double add){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){
        tree[p].lazyAdd += add;
        return;
    }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    updateAdd(li, L, (L+R)/2, i, j, add); updateAdd(ri, (L+R)/2+1, R, i, j, add);
    pullUp(p, L, R);
}

int main(){
    //freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> original[i];
    build(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        int x, a, b, c, d; cin >> x;
        if(x == 1){
            cin >> a >> b >> c >> d; a--; b--; c--; d--;
            double xx = query(1, 0, N-1, a, b)/(double)(b-a+1), yy = query(1, 0, N-1, c, d)/(double)(d-c+1);
            updateMult(1, 0, N-1, a, b, (double)(b-a)/(double)(b-a+1));
            updateAdd(1, 0, N-1, a, b, yy/(double)(b-a+1));
            updateMult(1, 0, N-1, c, d, (double)(d-c)/(double)(d-c+1));
            updateAdd(1, 0, N-1, c, d, xx/(double)(d-c+1));
        }
        else{
            cin >> a >> b; a--; b--;
            cout << query(1, 0, N-1, a, b) << '\n';
        }
    }
    return 0;
}
