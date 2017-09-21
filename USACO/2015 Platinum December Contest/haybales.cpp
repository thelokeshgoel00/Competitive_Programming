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
#define INF 1000000000000000000
#define MOD 1000000007

struct Node{
    long long sum, mini, lazy;
    Node(){ sum = -1; mini = -1; lazy = 0; }
};

int N, Q;
long long original [200010];
Node tree [800010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void pushDown(int p, int L, int R){
    tree[p].mini += tree[p].lazy;
    tree[p].sum += (long long)(R-L+1)*tree[p].lazy;
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].lazy += tree[p].lazy;
        tree[ri].lazy += tree[p].lazy;
    }
    tree[p].lazy = 0;
}

long long evalSum(int p, int L, int R) { return tree[p].sum+(long long)(R-L+1)*tree[p].lazy; }
long long evalMin(int p){ return tree[p].mini+tree[p].lazy; }

void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p].sum = evalSum(li, L, (L+R)/2)+evalSum(ri, (L+R)/2+1, R);
    tree[p].mini = min(evalMin(li), evalMin(ri));
}

void build(int p, int L, int R){
    if(L == R){
        tree[p].sum = original[L];
        tree[p].mini = original[L];
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].sum = tree[li].sum+tree[ri].sum;
    tree[p].mini = min(tree[li].mini, tree[ri].mini);
}

void update(int p, int L, int R, int i, int j, long long val){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){ tree[p].lazy += val; return; }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
    pullUp(p, L, R);
}

long long minQuery(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return INF;
    if(L >= i && R <= j) return evalMin(p);
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    long long ret = INF;
    ret = min(ret, min(minQuery(li, L, (L+R)/2, i, j), minQuery(ri, (L+R)/2+1, R, i, j)));
    pullUp(p, L, R);
    return ret;
}

long long sumQuery(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return 0;
    if(L >= i && R <= j) return evalSum(p, L, R);
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    long long ret = sumQuery(li, L, (L+R)/2, i, j)+sumQuery(ri, (L+R)/2+1, R, i, j);
    pullUp(p, L, R);
    return ret;
}

int main(){
    freopen("haybales.in", "r", stdin); freopen("haybales.out", "w", stdout);
    scanf("%d %d", &N, &Q);
    for(int i = 0; i < N; i++) scanf("%lld", &original[i]);
    build(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        char ch [2]; scanf("%s", &ch);
        int a, b, c;
        if(ch[0] == 'P'){
            scanf("%d %d %d", &a, &b, &c); a--; b--;
            update(1, 0, N-1, a, b, c);
        }
        else if(ch[0] == 'M'){
            scanf("%d %d", &a, &b); a--; b--;
            printf("%lld\n", minQuery(1, 0, N-1, a, b));
        }
        else{
            scanf("%d %d", &a, &b); a--; b--;
            printf("%lld\n", sumQuery(1, 0, N-1, a, b));
        }
    }
    return 0;
}
