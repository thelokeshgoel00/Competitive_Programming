#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct Node{
    long long sum, lmax, rmax, cmax;
    Node(){ sum = 0; lmax = 0; rmax = 0; cmax = 0; }
};

int N, Q;
long long arr [100000];
Node tree [400001];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        tree[p].sum = arr[L]; tree[p].lmax = arr[L];
        tree[p].rmax = arr[L]; tree[p].cmax = arr[L];
        return;
    }
    int li = left(p); int ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].sum = tree[li].sum+tree[ri].sum;
    tree[p].cmax = max(tree[p].sum, max(tree[li].cmax, tree[ri].cmax));
    tree[p].lmax = max(tree[li].lmax, tree[li].sum + tree[ri].lmax);
    tree[p].rmax = max(tree[ri].rmax, tree[ri].sum + tree[li].rmax);
    tree[p].cmax = max(max(tree[p].cmax, tree[li].rmax+tree[ri].lmax), max(tree[p].lmax, tree[p].rmax));
}

void update(int p, int L, int R, int place, long long val){
    if(L > R || L > place || R < place) return;
    if(L == R){
        tree[p].sum = tree[p].lmax = tree[p].rmax = tree[p].cmax = val;
        return;
    }
    int li = left(p); int ri = right(p);
    update(li, L, (L+R)/2, place, val); update(ri, (L+R)/2+1, R, place, val);
    tree[p].sum = tree[li].sum+tree[ri].sum;
    tree[p].cmax = max(tree[p].sum, max(tree[li].cmax, tree[ri].cmax));
    tree[p].lmax = max(tree[li].lmax, tree[li].sum + tree[ri].lmax);
    tree[p].rmax = max(tree[ri].rmax, tree[ri].sum + tree[li].rmax);
    tree[p].cmax = max(max(tree[p].cmax, tree[li].rmax+tree[ri].lmax), max(tree[p].lmax, tree[p].rmax));
}

Node query(int p, int L, int R, int i, int j){
    Node ans, a1, a2;
    if(j < L || i > R){
        ans.sum = ans.lmax = ans.rmax = ans.cmax = -1000000001;
        return ans;
    }
    if(L >= i && R <= j) return tree[p];
    int li = left(p); int ri = right(p);
    a1 = query(li, L, (L+R)/2, i, j);
    a2 = query(ri, (L+R)/2+1, R, i, j);
    ans.sum = a1.sum + a2.sum;
    ans.cmax = max(ans.sum, max(a1.cmax, a2.cmax));
    ans.lmax = max(a1.lmax, a1.sum + a2.lmax);
    ans.rmax = max(a2.rmax, a2.sum + a1.rmax);
    ans.cmax = max(max(ans.cmax, a1.rmax + a2.lmax), max(ans.lmax, ans.rmax));
    return ans;
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 0; i < N; i++){
        long long x; scanf("%lld", &x);
        arr[i] = x;
    }
    build(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        char c; int a; int b;
        cin >> c >> a >> b;
        if(c == 'S') update(1, 0, N-1, a-1, (long long)b);
        else cout << query(1, 0, N-1, a-1, b-1).cmax << endl;
    }
    return 0;
}
