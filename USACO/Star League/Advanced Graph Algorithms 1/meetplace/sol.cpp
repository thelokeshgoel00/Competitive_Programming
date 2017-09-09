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
#define INF 1000000000000
#define MOD 1000000007

int N, Q, tiempo = 0, dfsOrder [2010], firstSeen [1010], depth [1010];
vector<int> adjacency [1010];
pair<int, int> tree [8010];

void dfs(int curr, int dist){
    dfsOrder[tiempo] = curr; firstSeen[curr] = tiempo; tiempo++;
    depth[curr] = dist;
    for(int i : adjacency[curr]){
        dfs(i, dist+1);
        dfsOrder[tiempo] = curr; tiempo++;
    }
}

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        tree[p] = make_pair(dfsOrder[L], depth[dfsOrder[L]]);
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    if(tree[li].second < tree[ri].second) tree[p] = tree[li];
    else tree[p] = tree[ri];
}

pair<int, int> query(int p, int L, int R, int i, int j){
    if(L > R || L > j || R < i) return make_pair(10000, 10000);
    if(L >= i && R <= j) return tree[p];
    int li = left(p), ri = right(p);
    pair<int, int> q1 = query(li, L, (L+R)/2, i, j), q2 = query(ri, (L+R)/2+1, R, i, j);
    if(q1.second < q2.second) return q1;
    else return q2;
}

int main(){
    //freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);
    scanf("%d %d", &N, &Q);
    for(int i = 2; i <= N; i++){
        int parent; scanf("%d", &parent);
        adjacency[parent].push_back(i);
    }
    dfs(1, 1); build(1, 0, tiempo-1);
    //for(int i = 0; i < tiempo; i++) cout << dfsOrder[i] << " ";
    //cout << endl;
    for(int i = 0; i < Q; i++){
        int a, b; scanf("%d %d", &a, &b);
        if(firstSeen[a] > firstSeen[b]) swap(a, b);
        cout << query(1, 0, tiempo-1, firstSeen[a], firstSeen[b]).first << '\n';
    }
    return 0;
}
