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
#include <sstream>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

template<int sz>
class HeavyLight{
public:
    struct Node{
        int mini, lazy;
        Node(){ mini = 2e9; lazy = 0; }
    };
    
    int N, M, parents [sz+10], depths [sz+10], subtreeSizes [sz+10];
    int heavy [sz+10], root [sz+10], segPos [sz+10];
    Node tree [4*sz+10];
    pair<int, int> originals [sz+10];
    vector<pair<int, int>> adjacency [sz+10];
    HeavyLight(){ memset(heavy, -1, sizeof(heavy)); }
    void dfs(int curr, int prevy, int d){
        depths[curr] = d; parents[curr] = prevy; subtreeSizes[curr] = 1;
        int maxSubtree = 0;
        for(pair<int, int> edge : adjacency[curr]){
            if(edge.first == prevy) continue;
            dfs(edge.first, curr, d+1);
            if(subtreeSizes[edge.first] > maxSubtree) heavy[curr] = edge.first, maxSubtree = subtreeSizes[edge.first];
            subtreeSizes[curr] += subtreeSizes[edge.first];
        }
    }

    int left(int p){ return p<<1; }
    int right(int p){ return (p<<1)+1; }

    void pushDown(int p, int L, int R){
        if(tree[p].lazy == 0) return;
        tree[p].mini = min(tree[p].mini, tree[p].lazy);
        int li = left(p), ri = right(p);
        if(L != R){
            tree[li].lazy = tree[p].lazy;
            tree[ri].lazy = tree[p].lazy;
        }
        tree[p].lazy = 0;
    }

    long long evalMini(int p){ return tree[p].lazy == 0 ? tree[p].mini : min(tree[p].mini, tree[p].lazy); }

    void pullUp(int p, int L, int R){
        int li = left(p), ri = right(p);
        tree[p].mini = min(evalMini(li), evalMini(ri));
    }

    void update(int p, int L, int R, int i, int j, int val){
        if(L > R || i > R || j < L) return;
        if(L >= i && R <= j){ tree[p].lazy = val; return; }
        pushDown(p, L, R);
        int li = left(p), ri = right(p);
        update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
        pullUp(p, L, R);
    }

    int minQuery(int p, int L, int R, int i, int j){
        if(L > R || i > R || j < L) return 2e9;
        if(L >= i && R <= j) return evalMini(p);
        pushDown(p, L, R);
        int li = left(p), ri = right(p);
        int ret = min(minQuery(li, L, (L+R)/2, i, j), minQuery(ri, (L+R)/2+1, R, i, j));
        pullUp(p, L, R);
        return ret;
    }

    void HLD(){
        for(int i = 0, currentPos = 0; i < N; i++)
            if(parents[i] == -1 || heavy[parents[i]] != i)
                for(int j = i; j != -1; j = heavy[j]){
                    root[j] = i;
                    segPos[j] = currentPos++;
                }
    }

    template<class BinaryOperation>
    void processPath(int u, int v, BinaryOperation op){
        for( ; root[u] != root[v]; v = parents[root[v]]){
            if(depths[root[u]] > depths[root[v]]) swap(u, v);
            op(segPos[root[v]], segPos[v]);
        }
        if(depths[u] > depths[v]) swap(u, v);
        op(segPos[u]+1, segPos[v]);
    }

    void modifyPath(int u, int v, int value){
        processPath(u, v, [this, &value](int l, int r) { update(1, 0, N-1, l, r, value); });
    }

    int queryPath(int u, int v) {
        int ret = 2e9;
        processPath(u, v, [this, &ret](int l, int r) { ret = min(ret, minQuery(1, 0, N-1, l, r)); });
        return ret;
    }

};


int main(){
    freopen("disrupt.in", "r", stdin); freopen("disrupt.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    HeavyLight<1<<17> hld;
    cin >> hld.N >> hld.M;
    for(int i = 0; i < hld.N-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        hld.originals[i] = make_pair(a, b);
        hld.adjacency[a].push_back(make_pair(b, 2e9)); hld.adjacency[b].push_back(make_pair(a, 2e9));
    }
    hld.dfs(0, -1, 0); hld.HLD();
    vector<pair<int, pair<int, int>>> queries;
    for(int i = 0; i < hld.M; i++){
        int a, b, c; cin >> a >> b >> c; a--; b--;
        queries.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(queries.begin(), queries.end());
    for(int i = hld.M-1; i > -1; i--){
        int a = queries[i].second.first, b = queries[i].second.second, c = queries[i].first;
        hld.modifyPath(a, b, c);
    }
    for(int i = 0; i < hld.N-1; i++){
        int ret = hld.queryPath(hld.originals[i].first, hld.originals[i].second);
        if(ret == 2e9) cout << "-1\n";
        else cout << ret << '\n';
    }
    return 0;
}
