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
#define epsilon 0.000000001a
#define INF 1000000000000000000
#define MOD 1000000007

struct Node{
    int sum, lazy;
    Node(){ sum = 0; lazy = 0; }
};

int N, M;
Node tree [400010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void pushDown(int p, int L, int R){
    if(tree[p].lazy == 0) return;
    tree[p].sum = R-L+1-tree[p].sum;
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].lazy ^= 1;
        tree[ri].lazy ^= 1;
    }
    tree[p].lazy = 0;
}

int evalSum(int p, int L, int R){
    if(tree[p].lazy) return R-L+1-tree[p].sum;
    else return tree[p].sum;
}

void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p].sum = evalSum(li, L, (L+R)/2)+evalSum(ri, (L+R)/2+1, R);
}

void update(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){ tree[p].lazy ^= 1; return; }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j); update(ri, (L+R)/2+1, R, i, j);
    pullUp(p, L, R);
}

int query(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return 0;
    if(L >= i && R <= j) return evalSum(p, L, R);
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    long long ret = query(li, L, (L+R)/2, i, j)+query(ri, (L+R)/2+1, R, i, j);
    pullUp(p, L, R);
    return ret;
}

int main(){
    //freopen("fcount.in", "r", stdin); freopen("fcount.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int x, y, z; cin >> z >> x >> y; x--; y--;
        if(z == 0) update(1, 0, N-1, x, y);
        else cout << query(1, 0, N-1, x, y) << '\n';
    }
    return 0;
}
