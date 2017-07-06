#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct Node{
    int len, open, close;
    Node(){ len = 0; open = 0; close = 0; }
};

int N, Q;
string stuff;
Node tree [4000001];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        if(stuff[L] == '(') tree[p].open = 1;
        else tree[p].close = 1;
        return;
    }
    int li = left(p); int ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    int t = min(tree[li].open, tree[ri].close);
    tree[p].len = tree[li].len+tree[ri].len+2*t;
    tree[p].open = tree[li].open+tree[ri].open-t;
    tree[p].close = tree[li].close+tree[ri].close-t;
}

Node query(int p, int L, int R, int i, int j){
    Node ans, a1, a2;
    if(j < L || i > R) return ans;
    if(i <= L && j >= R) return tree[p];
    int li = left(p); int ri = right(p);
    a1 = query(li, L, (L+R)/2, i, j);
    a2 = query(ri, (L+R)/2+1, R, i, j);
    int t = min(a1.open, a2.close);
    ans.len = a1.len+a2.len+2*t;
    ans.open = a1.open+a2.open-t;
    ans.close = a1.close+a2.close-t;
    return ans;
}

int main(){
    cin >> stuff; N = stuff.length(); scanf("%d", &Q);
    build(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        int a, b; scanf("%d %d", &a, &b);
        cout << query(1, 0, N-1, a-1, b-1).len << endl;
    }
    return 0;
}
