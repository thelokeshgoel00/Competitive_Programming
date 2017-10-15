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

struct Node{
    int n4, n7, n47, n74;
    Node(){ n4 = 0; n7 = 0; n47 = 0; n74 = 0; }
};

int N, Q;
char stuff [1000005];
Node tree [4000001];
bool lazy [4000001];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        if(stuff[L] == '4') tree[p].n4 = 1;
        else tree[p].n7 = 1;
        tree[p].n47 = 1; tree[p].n74 = 1;
        return;
    }
    int li = left(p); int ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].n4 = tree[li].n4+tree[ri].n4; tree[p].n7 = tree[li].n7+tree[ri].n7;
    tree[p].n47 = max(tree[li].n4+tree[ri].n7, max(tree[li].n4+tree[ri].n47, tree[li].n47+tree[ri].n7));
    tree[p].n74 = max(tree[li].n7+tree[ri].n4, max(tree[li].n7+tree[ri].n74, tree[li].n74+tree[ri].n4));
}

void update(int p, int L, int R, int i, int j){
    int li = left(p); int ri = right(p);
    if(lazy[p]){
        lazy[p] = false;
        if(L != R){
            lazy[li] = !lazy[li];
            lazy[ri] = !lazy[ri];
        }
        swap(tree[p].n4, tree[p].n7);
        swap(tree[p].n47, tree[p].n74);
    }
    if(L > R || L > j || R < i) return;
    if(i <= L && j >= R){
        if(L != R){
            lazy[li] = !lazy[li];
            lazy[ri] = !lazy[ri];
        }
        if(!lazy[p]){
            swap(tree[p].n4, tree[p].n7);
            swap(tree[p].n47, tree[p].n74);
        }
        return;
    }
    update(li, L, (L+R)/2, i, j); update(ri, (L+R)/2+1, R, i, j);
    tree[p].n4 = tree[li].n4+tree[ri].n4; tree[p].n7 = tree[li].n7+tree[ri].n7;
    tree[p].n47 = max(tree[li].n4+tree[ri].n7, max(tree[li].n4+tree[ri].n47, tree[li].n47+tree[ri].n7));
    tree[p].n74 = max(tree[li].n7+tree[ri].n4, max(tree[li].n7+tree[ri].n74, tree[li].n74+tree[ri].n4));
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> Q >> stuff;
    build(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        string gg; int x, y;
        cin >> gg;
        if(gg.compare("count") == 0) cout << tree[1].n47 << endl;
        else{
            cin >> x >> y;
            update(1, 0, N-1, x-1, y-1);
        }
    }
    return 0;
}
