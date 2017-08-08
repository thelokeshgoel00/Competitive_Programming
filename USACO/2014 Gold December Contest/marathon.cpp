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

int N, Q, skipTree [400010], distTree [400010];
pair<int, int> checkpoints [100010];

int getDist(int a, int b){
    return abs(checkpoints[a].first-checkpoints[b].first)+abs(checkpoints[a].second-checkpoints[b].second);
}

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        if(L < N-2) skipTree[p] = getDist(L, L+1)+getDist(L+1, L+2)-getDist(L, L+2);
        else skipTree[p] = 0;
        if(L < N-1) distTree[p] = getDist(L, L+1);
        else distTree[p] = 0;
        return;
    }
    int li = left(p); int ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    skipTree[p] = max(skipTree[li], skipTree[ri]);
    distTree[p] = distTree[li]+distTree[ri];
}

void updateDist(int p, int L, int R, int place){
    if(L > R || L > place || R < place) return;
    if(L == R){
        if(L < N-1) distTree[p] = getDist(L, L+1);
        else distTree[p] = 0;
        return;
    }
    int li = left(p); int ri = right(p);
    updateDist(li, L, (L+R)/2, place); updateDist(ri, (L+R)/2+1, R, place);
    distTree[p] = distTree[li]+distTree[ri];
}

void skipUpdate(int p, int L, int R, int place){
    if(L > R || L > place || R < place) return;
    if(L == R){
        if(L < N-2) skipTree[p] = getDist(L, L+1)+getDist(L+1, L+2)-getDist(L, L+2);
        else skipTree[p] = 0;
        return;
    }
    int li = left(p); int ri = right(p);
    skipUpdate(li, L, (L+R)/2, place); skipUpdate(ri, (L+R)/2+1, R, place);
    skipTree[p] = max(skipTree[li], skipTree[ri]);
}

int queryDist(int p, int L, int R, int i, int j){
    if(L > R || j < L || i > R) return 0;
    if(L >= i && R <= j) return distTree[p];
    int li = left(p); int ri = right(p);
    return queryDist(li, L, (L+R)/2, i, j)+queryDist(ri, (L+R)/2+1, R, i, j);
}

int querySkip(int p, int L, int R, int i, int j){
    if(L > R || j < L || i > R) return 0;
    if(L >= i && R <= j) return skipTree[p];
    int li = left(p); int ri = right(p);
    return max(querySkip(li, L, (L+R)/2, i, j), querySkip(ri, (L+R)/2+1, R, i, j));
}

int main(){
    freopen("marathon.in", "r", stdin); freopen("marathon.out", "w", stdout);
    scanf("%d %d", &N, &Q);
    for(int i = 0; i < N; i++) scanf("%d %d", &checkpoints[i].first, &checkpoints[i].second);
    build(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        int x, a, b;
        char oper [1]; scanf("%s", &oper);
        if(oper[0] == 'Q'){
            scanf("%d %d", &a, &b); a--; b--;
            printf("%d\n", queryDist(1, 0, N-1, a, b-1)-querySkip(1, 0, N-1, a, b-2));
        }
        else{
            scanf("%d %d %d", &x, &a, &b); x--;
            checkpoints[x] = make_pair(a, b);
            updateDist(1, 0, N-1, x-1); updateDist(1, 0, N-1, x);
            skipUpdate(1, 0, N-1, x-2); skipUpdate(1, 0, N-1, x-1); skipUpdate(1, 0, N-1, x);
        }
    }
    return 0;
}
