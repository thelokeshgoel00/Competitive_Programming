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

int N, M;
vector<int> adjacency [100001];
int tree [100001], id [100001], mx [100001], parent [100001], curr = 1;
int tiempo = 0, dfsOrder [200010], firstSeen [100010], depth [100010];
pair<int, int> segTree [800010];
bool visited [100001];

int dfs(int x, int dist){
    id[x] = curr++; visited[x] = true; mx[x] = id[x];
    dfsOrder[tiempo] = id[x]; firstSeen[id[x]] = tiempo; tiempo++;
    depth[id[x]] = dist;
    for(int i = 0; i < adjacency[x].size(); i++){
        int next = adjacency[x][i];
        if(visited[next]) continue;
        parent[next] = x;
        mx[x] = max(mx[x], dfs(next, dist+1));
        dfsOrder[tiempo] = id[x]; tiempo++;
    }
    return mx[x];
}

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        segTree[p] = make_pair(dfsOrder[L], depth[dfsOrder[L]]);
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    if(segTree[li].second < segTree[ri].second) segTree[p] = segTree[li];
    else segTree[p] = segTree[ri];
}

pair<int, int> query(int p, int L, int R, int i, int j){
    if(L > R || L > j || R < i) return make_pair(1000000, 1000000);
    if(L >= i && R <= j) return segTree[p];
    int li = left(p), ri = right(p);
    pair<int, int> q1 = query(li, L, (L+R)/2, i, j), q2 = query(ri, (L+R)/2+1, R, i, j);
    if(q1.second < q2.second) return q1;
    else return q2;
}

int LCA(int a, int b){
    a = id[a]; b = id[b];
    if(firstSeen[a] > firstSeen[b]) swap(a, b);
    return query(1, 0, tiempo-1, firstSeen[a], firstSeen[b]).first;
}

void add(int pos, int num){
    while(pos < 100001){
        tree[pos] += num;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int ret = 0;
    while(pos > 0){
        ret += tree[pos];
        pos -= (pos&-pos);
    }
    return ret;
}

int main(){
    freopen("grassplant.in", "r", stdin); freopen("grassplant.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N-1; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    dfs(1, 1); build(1, 0, tiempo-1);
    //for(int i = 1; i <= N; i++) cout << id[i] << " hi " << mx[i] << endl;
    for(int i = 0; i < M; i++){
        char c; int a, b; cin >> c >> a >> b;
        if(c == 'P'){
            add(id[a], 1); add(id[b], 1);
            add(LCA(a, b), -2);
        }
        else{
            if(id[a] > id[b]) cout << query(mx[a])-query(id[a]-1) << endl;
            else cout << query(mx[b])-query(id[b]-1) << endl;
        }
    }
    return 0;
}
