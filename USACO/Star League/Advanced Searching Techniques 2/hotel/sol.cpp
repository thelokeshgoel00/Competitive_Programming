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

struct Node{
    int lft, rht, maxi;
    Node(){ lft = rht = maxi = 0; }
};

int N, M, ret = 0;
Node tree [200010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        tree[p].lft = tree[p].rht = tree[p].maxi = 1;
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].lft = tree[p].rht = tree[p].maxi = R-L+1;
}

int query(int p, int L, int R, int k){
    if(tree[p].maxi < k) return -1;
    if(tree[p].lft >= k) return L;
    int li = left(p), ri = right(p), temp = query(li, L, (L+R)/2, k);
    if(temp > 0) return temp;
    if(tree[li].rht+tree[ri].lft >= k) return (L+R)/2-tree[li].rht+1;
    return query(ri, (L+R)/2+1, R, k);
}

void update(int p, int L, int R, int i, int j, int oriState, int curState){
    if(curState < 0){
        if(tree[p].maxi == 0) curState = 0;
        else if(tree[p].maxi == R-L+1) curState = 1;
    }
    if(L > R || i > R || j < L){
        if(curState > -1) tree[p].lft = tree[p].rht = tree[p].maxi = curState*(R-L+1);
        return;
    }
    if(L >= i && R <= j){
        tree[p].lft = tree[p].rht = tree[p].maxi = oriState*(R-L+1);
        return;
    }
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, oriState, curState); update(ri, (L+R)/2+1, R, i, j, oriState, curState);
    tree[p].lft = tree[li].lft; if(tree[li].lft == (L+R)/2-L+1) tree[p].lft += tree[ri].lft;
    tree[p].rht = tree[ri].rht; if(tree[ri].rht == R-(L+R)/2) tree[p].rht += tree[li].rht;
    tree[p].maxi = max(tree[li].rht+tree[ri].lft, max(tree[li].maxi, tree[ri].maxi));
}

int main(){
    //freopen("seating.in", "r", stdin); freopen("seating.out", "w", stdout);
    scanf("%d %d", &N, &M);
    build(1, 0, N-1);
    for(int qq = 0; qq < M; qq++){
        int x, y, index, c; scanf("%d", &c);
        if(c == 2){
            scanf("%d %d", &x, &y);
            update(1, 0, N-1, x-1, x+y-2, 1, -1);
        }
        else{
            scanf("%d", &x);
            index = query(1, 0, N-1, x);
            cout << index+1 << '\n';
            if(index < 0) continue;
            update(1, 0, N-1, index, index+x-1, 0, -1);
        }
    }
    return 0;
}
