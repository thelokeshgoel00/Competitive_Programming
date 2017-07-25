#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct Node{
    long long pp, pb, bp, bb;
    Node(){ pp = 0; pb = 0; bp = 0; bb = 0; }
};

int N, D;
Node tree [200000];
long long ret = 0ll, arr [200000];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        tree[p].bb = arr[L];
        return;
    }
    int li = left(p); int ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].pp = max(tree[li].pb+tree[ri].pp, tree[li].pp+tree[ri].bp);
    tree[p].pb = max(tree[li].pb+tree[ri].pb, tree[li].pp+tree[ri].bb);
    tree[p].bp = max(tree[li].bb+tree[ri].pp, tree[li].bp+tree[ri].bp);
    tree[p].bb = max(tree[li].bb+tree[ri].pb, tree[li].bp+tree[ri].bb);
}

void update(int p, int L, int R, int place, long long val){
    if(L > R || L > place || R < place) return;
    if(L == R){
        tree[p].bb = val;
        return;
    }
    int li = left(p); int ri = right(p);
    update(li, L, (L+R)/2, place, val); update(ri, (L+R)/2+1, R, place, val);
    tree[p].pp = max(tree[li].pb+tree[ri].pp, tree[li].pp+tree[ri].bp);
    tree[p].pb = max(tree[li].pb+tree[ri].pb, tree[li].pp+tree[ri].bb);
    tree[p].bp = max(tree[li].bb+tree[ri].pp, tree[li].bp+tree[ri].bp);
    tree[p].bb = max(tree[li].bb+tree[ri].pb, tree[li].bp+tree[ri].bb);
}

int main(){
    freopen("optmilk.in","r",stdin); freopen("optmilk.out","w",stdout);
    scanf("%d %d", &N, &D);
    for(int i = 0; i < N; i++) scanf("%lld", &arr[i]);
    build(1, 0, N-1);
    for(int i = 0; i < D; i++){
        int a; long long b; scanf("%d %lld", &a, &b);
        update(1, 0, N-1, a-1, b);
        ret += tree[1].bb;
    }
    cout << ret << '\n';
    return 0;
}
