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

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

struct Book{
    long long pos, len, wid;
    Book(){ pos = 0; len = 0; wid = 0; }
};

struct Node{
    long long maxi, lazy;
    Node(){ maxi = 0; lazy = 0; }
};

int N, totalX = 0;
Book books [500010];
set<long long> xs;
unordered_map<long long, int> xToIndex;
unordered_map<int, long long> indexToX;
Node tree [4000010];
long long ret = 0;

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void pushDown(int p, int L, int R){
    if(tree[p].lazy == 0) return;
    tree[p].maxi = tree[p].lazy;
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].lazy = tree[p].lazy;
        tree[ri].lazy = tree[p].lazy;
    }
    tree[p].lazy = 0;
}

long long evalMaxi(int p){ return max(tree[p].maxi, tree[p].lazy); }

void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p].maxi = max(evalMaxi(li), evalMaxi(ri));
}

void update(int p, int L, int R, int i, int j, long long val){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){ tree[p].lazy = val; return; }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
    pullUp(p, L, R);
}

long long maxQuery(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return -1;
    if(L >= i && R <= j) return evalMaxi(p);
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    long long ret = max(maxQuery(li, L, (L+R)/2, i, j), maxQuery(ri, (L+R)/2+1, R, i, j));
    pullUp(p, L, R);
    return ret;
}

int main(){
    //freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> books[i].pos >> books[i].len >> books[i].wid;
        xs.insert(books[i].pos); xs.insert(books[i].pos+books[i].len);
    }
    for(long long xx : xs){
        xToIndex[xx] = totalX; indexToX[totalX] = xx;
        totalX++;
    }
    for(int i = 0; i < N; i++){
        int st = xToIndex[books[i].pos], en = xToIndex[books[i].pos+books[i].len]-1;
        long long mx = maxQuery(1, 0, totalX-1, st, en);
        ret = (ret+MOD-(books[i].len*books[i].wid)%MOD)%MOD;
        update(1, 0, totalX-1, st, en, mx+books[i].wid);
    }
    for(int i = 0; i < totalX-1; i++){
        long long h = maxQuery(1, 0, totalX-1, i, i);
        ret = (ret+(h*(indexToX[i+1]-indexToX[i]))%MOD)%MOD;
    }
    cout << ret << '\n';
    return 0;
}
