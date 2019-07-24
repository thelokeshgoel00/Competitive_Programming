#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5e18
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

template<int sz, bool useEdge> struct HeavyLight{
    struct Node{
        int maxi, lazy;
        Node(){ maxi = 0; lazy = 0; }
    };

    int N, id = 0, parents [sz+10], depths [sz+10], subtreeSizes [sz+10];
    int root [sz+10], segPos [sz+10];
    Node tree [4*sz+10];
    vector<int> adjacency [sz+10];

    int left(int p){ return p<<1; }
    int right(int p){ return (p<<1)+1; }

    void pushDown(int p, int L, int R){
        if(tree[p].lazy == 0) return;
        tree[p].maxi = max(tree[p].maxi, tree[p].lazy);
        int li = left(p), ri = right(p);
        if(L != R){
            tree[li].lazy += tree[p].lazy;
            tree[ri].lazy += tree[p].lazy;
        }
        tree[p].lazy = 0;
    }

    long long evalMaxi(int p){ return tree[p].maxi+tree[p].lazy; }

    void pullUp(int p, int L, int R){
        int li = left(p), ri = right(p);
        tree[p].maxi = max(evalMaxi(li), evalMaxi(ri));
    }

    void update(int p, int L, int R, int i, int j, int val){
        if(L > R || i > R || j < L) return;
        if(L >= i && R <= j){ tree[p].lazy += val; return; }
        pushDown(p, L, R);
        int li = left(p), ri = right(p);
        update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
        pullUp(p, L, R);
    }

    int maxQuery(int p, int L, int R, int i, int j){
        if(L > R || i > R || j < L) return -MOD;
        if(L >= i && R <= j) return evalMaxi(p);
        pushDown(p, L, R);
        int li = left(p), ri = right(p);
        int ret = max(maxQuery(li, L, (L+R)/2, i, j), maxQuery(ri, (L+R)/2+1, R, i, j));
        pullUp(p, L, R);
        return ret;
    }

    void addEdge(int a, int b){ adjacency[a].pb(b); adjacency[b].pb(a); }

    void dfs(int curr = 1, int prevy = 0){
        subtreeSizes[curr] = 1;
        for(int i = 0; i < adjacency[curr].size(); i++){
            int nexty = adjacency[curr][i];
            if(nexty == prevy) continue;
            parents[nexty] = curr; depths[nexty] = depths[curr]+1;
            dfs(nexty, curr); subtreeSizes[curr] += subtreeSizes[nexty];
            if(subtreeSizes[nexty] > subtreeSizes[adjacency[curr][0]]) swap(adjacency[curr][i], adjacency[curr][0]);
        }
    }

    void HLD(int curr = 1, int prevy = 0){
        segPos[curr] = id++;
        for(int nexty : adjacency[curr]){
            if(nexty == prevy) continue;
            root[nexty] = (nexty == adjacency[curr][0] ? root[curr] : nexty);
            HLD(nexty, curr);
        }
    }

    void init(int X){
        N = X; parents[1] = depths[1] = 0; root[1] = 1;
        dfs(); HLD();
        assert(id == N);
    }

    template<class BinaryOperation>
    void processPath(int u, int v, BinaryOperation op){
        for( ; root[u] != root[v]; v = parents[root[v]]){
            if(depths[root[u]] > depths[root[v]]) swap(u, v);
            op(segPos[root[v]], segPos[v]);
        }
        if(depths[u] > depths[v]) swap(u, v);
        op(segPos[u]+useEdge, segPos[v]);
    }

    void modifyPath(int u, int v, int value){
        processPath(u, v, [this, &value](int l, int r){ update(1, 0, N-1, l, r, value); });
    }

    void modifySubtree(int v, int value){
        update(1, 0, N-1, segPos[v]+useEdge, segPos[v]+subtreeSizes[v]-1, value);
    }

    int queryPath(int u, int v){
        int ret = -MOD;
        processPath(u, v, [this, &ret](int l, int r){ ret = max(ret, maxQuery(1, 0, N-1, l, r)); });
        return ret;
    }

};

int N, Q;
HeavyLight<100000, false> hld;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        hld.addEdge(a, b);
    }
    hld.init(N);
    cin >> Q;
    for(int q = 0; q < Q; q++){
        char c; int a, b; cin >> c >> a >> b;
        if(c == 'I') hld.modifyPath(a, a, b);
        else cout << hld.queryPath(a, b) << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
