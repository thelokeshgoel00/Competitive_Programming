#define __USE_MINGW+_ANSI_STDIO 0
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
    int leftS, rightS, leftP, rightP, maxS, maxP;
    bool allS, allP;
    Node(){ leftS = rightS = leftP = rightP = maxS = maxP = 0; allS = allP = false; }
};

int kase, len, queries;
Node tree [400001];
bool lazy [400001];
string stuff;

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        if(stuff[L] == 'S'){ tree[p].leftS = tree[p].rightS = tree[p].maxS = 1; tree[p].allS = true; }
        else{ tree[p].leftP = tree[p].rightP = tree[p].maxP = 1; tree[p].allP = true; }
        return;
    }
    int li = left(p); int ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].maxS = max(tree[li].maxS, tree[ri].maxS); tree[p].maxP = max(tree[li].maxP, tree[ri].maxP);
    tree[p].maxS = max(tree[p].maxS, tree[li].rightS+tree[ri].leftS); tree[p].maxP = max(tree[p].maxP, tree[li].rightP+tree[ri].leftP);
    tree[p].leftS = tree[li].leftS; tree[p].rightS = tree[ri].rightS; tree[p].leftP = tree[li].leftP; tree[p].rightP = tree[ri].rightP;
    if(tree[li].allS) tree[p].leftS += tree[ri].leftS;
    if(tree[ri].allS) tree[p].rightS += tree[li].rightS;
    if(tree[li].allP) tree[p].leftP += tree[ri].leftP;
    if(tree[ri].allP) tree[p].rightP += tree[li].rightP;
    tree[p].allS = tree[li].allS && tree[ri].allS; tree[p].allP = tree[li].allP && tree[ri].allP;
}

void update(int p, int L, int R, int i, int j){
    int li = left(p); int ri = right(p);
    if(lazy[p]){
        lazy[p] = false;
        if(L != R){
            lazy[li] = !lazy[li];
            lazy[ri] = !lazy[ri];
        }
        swap(tree[p].maxS, tree[p].maxP); swap(tree[p].leftS, tree[p].leftP);
        swap(tree[p].rightS, tree[p].rightP); swap(tree[p].allS, tree[p].allP);
    }
    if(L > R || L > j || R < i) return;
    if(i <= L && j >= R){
        if(L != R){
            lazy[li] = !lazy[li];
            lazy[ri] = !lazy[ri];
        }
        if(!lazy[p]){
            swap(tree[p].maxS, tree[p].maxP); swap(tree[p].leftS, tree[p].leftP);
            swap(tree[p].rightS, tree[p].rightP); swap(tree[p].allS, tree[p].allP);
        }
        return;
    }
    update(li, L, (L+R)/2, i, j); update(ri, (L+R)/2+1, R, i, j);
    tree[p].maxS = max(tree[li].maxS, tree[ri].maxS); tree[p].maxP = max(tree[li].maxP, tree[ri].maxP);
    tree[p].maxS = max(tree[p].maxS, tree[li].rightS+tree[ri].leftS); tree[p].maxP = max(tree[p].maxP, tree[li].rightP+tree[ri].leftP);
    tree[p].leftS = tree[li].leftS; tree[p].rightS = tree[ri].rightS; tree[p].leftP = tree[li].leftP; tree[p].rightP = tree[ri].rightP;
    if(tree[li].allS) tree[p].leftS += tree[ri].leftS;
    if(tree[ri].allS) tree[p].rightS += tree[li].rightS;
    if(tree[li].allP) tree[p].leftP += tree[ri].leftP;
    if(tree[ri].allP) tree[p].rightP += tree[li].rightP;
    tree[p].allS = tree[li].allS && tree[ri].allS; tree[p].allP = tree[li].allP && tree[ri].allP;
}

int main(){
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> len >> queries >> stuff;
        for(int i = 0; i < 400001; i++){ tree[i] = Node(); lazy[i] = false; }
        build(1, 0, len-1);
        for(int i = 0; i < queries; i++){
            int x, y; cin >> x >> y;
            update(1, 0, len-1, x-1, y-1);
            cout << tree[1].maxS << " " << tree[1].maxP << '\n';
        }
    }
    return 0;
}
