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

int kase;

template<int sz>
class HeavyLight{
public:
    struct Node{
        int maxi, lazy;
        Node(){ maxi = 0; lazy = 0; }
    };

    int N, weights [sz+10], parents [sz+10], depths [sz+10], subtreeSizes [sz+10];
    int heavy [sz+10], root [sz+10], segPos [sz+10];
    Node tree [4*sz+10];
    pair<int, int> originals [sz+10];
    vector<pair<int, int>> adjacency [sz+10];
    unordered_map<int, pair<int, int>> edgeID;
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
        tree[p].maxi = tree[p].lazy;
        int li = left(p), ri = right(p);
        if(L != R){
            tree[li].lazy = tree[p].lazy;
            tree[ri].lazy = tree[p].lazy;
        }
        tree[p].lazy = 0;
    }

    long long evalMaxi(int p){ return tree[p].lazy == 0 ? tree[p].maxi : tree[p].lazy; }

    void pullUp(int p, int L, int R){
        int li = left(p), ri = right(p);
        tree[p].maxi = max(evalMaxi(li), evalMaxi(ri));
    }

    void update(int p, int L, int R, int i, int j, int val){
        if(L > R || i > R || j < L) return;
        if(L >= i && R <= j){ tree[p].lazy = val; return; }
        pushDown(p, L, R);
        int li = left(p), ri = right(p);
        update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
        pullUp(p, L, R);
    }

    int maxQuery(int p, int L, int R, int i, int j){
        if(L > R || i > R || j < L) return 0;
        if(L >= i && R <= j) return evalMaxi(p);
        pushDown(p, L, R);
        int li = left(p), ri = right(p);
        int ret = max(maxQuery(li, L, (L+R)/2, i, j), maxQuery(ri, (L+R)/2+1, R, i, j));
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
        int ret = 0;
        processPath(u, v, [this, &ret](int l, int r) { ret = max(ret, maxQuery(1, 0, N-1, l, r)); });
        return ret;
    }

};

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(9);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        HeavyLight<1<<17> hld;
        cin >> hld.N;
        for(int i = 0; i < hld.N-1; i++){
            int a, b, c; cin >> a >> b >> c; a--; b--;
            hld.adjacency[a].pb(mp(b, c)); hld.adjacency[b].pb(mp(a, c));
            hld.originals[i] = mp(a, b); hld.weights[i] = c;
        }
        hld.dfs(0, -1, 0); hld.HLD();
        for(int i = 0; i < hld.N-1; i++) hld.modifyPath(hld.originals[i].f, hld.originals[i].s, hld.weights[i]);
        while(true){
            string command; cin >> command;
            if(command[0] == 'D') break;
            int a, b; cin >> a >> b;
            if(command[0] == 'C') hld.modifyPath(hld.originals[a-1].f, hld.originals[a-1].s, b);
            else cout << hld.queryPath(a-1, b-1) << '\n';
        }
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
