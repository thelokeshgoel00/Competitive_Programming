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
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

struct Node{
    vector<int>* arr;
    int maxi;
    Node(){ arr = new vector<int>(); maxi = 0; }
    int sz(){ return arr->size(); }
    void add(int i, int val){
        (*arr)[i] += val;
        if(mp((*arr)[i], i) > mp((*arr)[maxi], maxi)) maxi = i;
    }
};

Node pull(Node x){
    Node a;
    if(x.sz() == 0){
        a.arr = new vector<int>(1, 1);
        return a;
    }
    a.arr = x.arr; a.maxi = x.maxi;
    a.arr->pb(0); a.add(a.sz()-1, 1);
    return a;
}

Node mergey(Node a, Node b){
    if(a.sz() < b.sz()) swap(a, b);
    Node c; c.arr = a.arr; c.maxi = a.maxi;
    for(int i = 0; i < b.sz(); i++) c.add(a.sz()-1-i, (*b.arr)[b.sz()-1-i]);
    return c;
}

int N, ret [1000010];
vector<int> adjacency [1000010];
Node nodes [1000010];

void dfs(int curr, int prevy){
    for(int nexty : adjacency[curr]){
        if(nexty == prevy) continue;
        dfs(nexty, curr); nodes[curr] = mergey(nodes[curr], nodes[nexty]);
    }
    nodes[curr] = pull(nodes[curr]);
    ret[curr] = nodes[curr].sz()-1-nodes[curr].maxi;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 1; i < N; i++){
        int x, y; cin >> x >> y;
        adjacency[x].pb(y); adjacency[y].pb(x);
    }
    dfs(1, 0);
    for(int i = 1; i <= N; i++) cout << ret[i] << '\n';
    return 0;
}
