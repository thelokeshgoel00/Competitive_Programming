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

int N, M;
vector<int> adjacency [50001];
int freq [50001], id [50001], parentID [50001], curr = 1;
int tiempo = 0, dfsOrder [100010], firstSeen [50010], depth [50010];
pair<int, int> segTree [400010];
bool visited [50001];
vector<pair<int, int>> depthOrder;

void dfs(int x, int dist){
    id[x] = curr++; visited[x] = true;
    dfsOrder[tiempo] = id[x]; firstSeen[id[x]] = tiempo; tiempo++;
    depth[id[x]] = dist;
    for(int i = 0; i < adjacency[x].size(); i++){
        int next = adjacency[x][i];
        if(visited[next]) continue;
        dfs(next, dist+1);
        parentID[id[next]] = id[x];
        dfsOrder[tiempo] = id[x]; tiempo++;
    }
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

int main(){
    freopen("maxflow.in", "r", stdin); freopen("maxflow.out", "w", stdout);
    scanf("%d %d", &N, &M); memset(parentID, -1, sizeof(parentID));
    for(int i = 0; i < N-1; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    dfs(1, 1); build(1, 0, tiempo-1); memset(freq, 0, sizeof(freq));
    //for(int i = 1; i <= N; i++) cout << id[i] << " hi " << mx[i] << endl;
    for(int i = 0; i < M; i++){
        int a, b; scanf("%d %d", &a, &b);
        int x = LCA(a, b);
        freq[id[a]]++; freq[id[b]]++; freq[x]--;
        if(parentID[x] != -1) freq[parentID[x]]--;
    }
    for(int i = 1; i < curr; i++) depthOrder.push_back(make_pair(depth[i], i));
    sort(depthOrder.begin(), depthOrder.end());
    for(int i = N-1; i > -1; i--)
        if(parentID[depthOrder[i].second] != -1)
            freq[parentID[depthOrder[i].second]] += freq[depthOrder[i].second];
    cout << *max_element(freq, freq+50001) << '\n';
    return 0;
}
