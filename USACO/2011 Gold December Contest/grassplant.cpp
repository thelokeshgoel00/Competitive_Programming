#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> adjacency [100001];
int tree [100001], id [100001], mx [100001], parent [100001], curr = 1;
bool visited [100001];

int dfs(int x){
    id[x] = curr++; visited[x] = true; mx[x] = id[x];
    for(int i = 0; i < adjacency[x].size(); i++){
        int next = adjacency[x][i];
        if(visited[next]) continue;
        parent[next] = x;
        mx[x] = max(mx[x], dfs(next));
    }
    return mx[x];
}

int LCA(int a, int b){
    if(a == b) return a;
    vector<int> as, bs;
    while(a != 0){
        as.push_back(a);
        a = parent[a];
    }
    while(b != 0){
        bs.push_back(b);
        b = parent[b];
    }
    for(int i = 1; i <= min(as.size(), bs.size()); i++){
        if(as[as.size()-i] == bs[bs.size()-i]) continue;
        return as[as.size()-i+1];
    }
    if(as.size() < bs.size()) return as[0];
    else return bs[0];
}

int add(int pos, int num){
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
    dfs(1);
    //for(int i = 1; i <= N; i++) cout << id[i] << " hi " << mx[i] << endl;
    for(int i = 0; i < M; i++){
        char c; int a, b; cin >> c >> a >> b;
        if(c == 'P'){
            add(id[a], 1); add(id[b], 1);
            add(id[LCA(a, b)], -2);
        }
        else{
            if(id[a] > id[b]) cout << query(mx[a])-query(id[a]-1) << endl;
            else cout << query(mx[b])-query(id[b]-1) << endl;
        }
    }
    return 0;
}
