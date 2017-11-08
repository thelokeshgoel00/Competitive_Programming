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

int N, Q, ori [200010], curID = 0, id [200010], mx [200010], vals [200010], tree [800010], lazy [800010];
vector<int> children [200010];

int dfs(int curr){
    id[curr] = curID++; mx[curr] = id[curr]; vals[id[curr]] = ori[curr];
    for(int nexty : children[curr]) mx[curr] = max(mx[curr], dfs(nexty));
    return mx[curr];
}

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        tree[p] = vals[L];
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p] = tree[li]+tree[ri];
}

void pushDown(int p, int L, int R){
    if(lazy[p] == 0) return;
    tree[p] = R-L+1-tree[p];
    int li = left(p), ri = right(p);
    if(L != R){
        lazy[li] ^= 1;
        lazy[ri] ^= 1;
    }
    lazy[p] = 0;
}

int evalSum(int p, int L, int R){
    if(lazy[p]) return R-L+1-tree[p];
    else return tree[p];
}

void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p] = evalSum(li, L, (L+R)/2)+evalSum(ri, (L+R)/2+1, R);
}

void update(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){ lazy[p] ^= 1; return; }
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
    int ret = query(li, L, (L+R)/2, i, j)+query(ri, (L+R)/2+1, R, i, j);
    pullUp(p, L, R);
    return ret;
}

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 1; i < N; i++){
        int x; cin >> x; x--;
        children[x].push_back(i);
    }
    for(int i = 0; i < N; i++) cin >> ori[i];
    dfs(0); build(1, 0, N-1); memset(lazy, 0, sizeof(lazy));
    cin >> Q;
    for(int i = 0; i < Q; i++){
        string s; int x, a, b; cin >> s >> x; x--;
        a = id[x]; b = mx[x];
        if(s.compare("pow") == 0) update(1, 0, N-1, a, b);
        else cout << query(1, 0, N-1, a, b) << '\n';
    }
    return 0;
}
