#define __USE_MINGW_ANSI_STDIO 0

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

int N, M, preID = 0, ids [200010], maxi [200010], parents [20][200010], depths [200010], tree [200010];
vector<int> adjacency [200010];

void dfs(int curr, int prevy, int depth){
    ids[curr] = ++preID; parents[0][curr] = prevy; depths[curr] = depth;
    for(int nexty : adjacency[curr])
        if(nexty != prevy)
            dfs(nexty, curr, depth+1);
    maxi[curr] = preID;
}

void buildIt(){
    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= N; j++)
            parents[i][j] = parents[i-1][parents[i-1][j]];
}

int findLCA(int p, int q){
    if(depths[p] < depths[q]) swap(p, q);
    for(int i = 19; i > -1; i--)
        if(depths[p]-(1<<i) >= depths[q])
            p = parents[i][p];
    if(p == q) return p;
    for(int i = 19; i > -1; i--)
        if(parents[i][p] != parents[i][q]){
            p = parents[i][p];
            q = parents[i][q];
        }
    return parents[0][p];
}

void add(int pos, int num){
    while(pos <= N){
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
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        adjacency[a].pb(b); adjacency[b].pb(a);
    }
    dfs(1, 1, 0); buildIt();
    for(int i = 1; i <= M; i++){
        int a, b; cin >> a >> b;
        int lca = findLCA(a, b);
        add(ids[a], 1); add(ids[b], 1); add(ids[lca], -1);
        if(lca != 1) add(ids[parents[0][lca]], -1);
    }
    for(int i = 1; i <= N; i++) cout << query(maxi[i])-query(ids[i]-1) << (i == N ? '\n' : ' ');
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
