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

int N, M, Q, tiempo, compID, blockID, parents [100010], disc [100010], low [100010], compNum [100010], depths [200010], table [20][200010];
vector<int> oriAdjacency [100010], blockcut [200010];
stack<pair<int, int>> stk;
vector<pair<int, int>> bccs [100010];
bool isArticulationPoint [100010];

void resetIt(){
    for(int i = 1; i <= N; i++){
        oriAdjacency[i] = vector<int>();
        disc[i] = low[i] = parents[i] = -1;
        isArticulationPoint[i] = false;
    }
    for(int i = 0; i < compID; i++) bccs[i] = vector<pair<int, int>>();
    for(int i = 0; i < blockID; i++) blockcut[i] = vector<int>();
    tiempo = compID = blockID = 0;
}

void findBCC(int curr, int root = 0){
    disc[curr] = low[curr] = tiempo++;
    int numChildren = 0;
    for(int nexty : oriAdjacency[curr]){
        if(disc[nexty] == -1){
            parents[nexty] = curr; stk.push(mp(curr, nexty)); findBCC(nexty);
            low[curr] = min(low[curr], low[nexty]); numChildren++;
            if((root && numChildren > 1) || (!root && low[nexty] >= disc[curr])){
                isArticulationPoint[curr] = true;
                while(stk.top() != mp(curr, nexty)){
                    bccs[compID].pb(stk.top());
                    stk.pop();
                }
                bccs[compID].pb(stk.top());
                stk.pop(); compID++;
            }
        }
        else if(nexty != parents[curr] && disc[nexty] < disc[curr]){
            low[curr] = min(low[curr], disc[nexty]);
            stk.push(mp(curr, nexty));
        }
    }
}

void dfs(int curr, int prevy, int d){
    depths[curr] = d; table[0][curr] = prevy;
    for(int i : blockcut[curr])
        if(i != prevy)
            dfs(i, curr, d+1);
}

void buildIt(){
    for(int i = 1; i < 20; i++)
        for(int j = 0; j < blockID; j++)
            table[i][j] = table[i-1][table[i-1][j]];
}

int findLCA(int p, int q){
    if(depths[p] < depths[q]) swap(p, q);
    for(int i = 19; i > -1; i--)
        if(depths[p]-(1<<i) >= depths[q])
            p = table[i][p];
    if(p == q) return p;
    for(int i = 19; i > -1; i--)
        if(table[i][p] != table[i][q]){
            p = table[i][p];
            q = table[i][q];
        }
    return table[0][p];
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M >> Q; resetIt();
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        oriAdjacency[a].pb(b); oriAdjacency[b].pb(a);
    }
    for(int i = 1; i <= N; i++){
        if(disc[i] != -1) continue;
        findBCC(i, 1); if(stk.size() == 0) continue;
        while(stk.size() > 0){
            bccs[compID].pb(stk.top());
            stk.pop();
        }
        compID++;
    }
    blockID = compID;
    for(int i = 1; i <= N; i++)
        if(isArticulationPoint[i])
            compNum[i] = blockID++;
    for(int k = 0; k < compID; k++)
        for(pair<int, int> edge : bccs[k]){
            int a = edge.f, b = edge.s;
            if(!isArticulationPoint[a]) compNum[a] = k;
            else{
                blockcut[k].pb(compNum[a]);
                blockcut[compNum[a]].pb(k);
            }
            if(!isArticulationPoint[b]) compNum[b] = k;
            else{
                blockcut[k].pb(compNum[b]);
                blockcut[compNum[b]].pb(k);
            }
        }
    for(int k = 0; k < blockID; k++){
        sort(blockcut[k].begin(), blockcut[k].end());
        blockcut[k].resize(unique(blockcut[k].begin(), blockcut[k].end())-blockcut[k].begin());
    }
    dfs(0, 0, 0); buildIt();
    for(int q = 0; q < Q; q++){
        int a, b, c; cin >> a >> b >> c;
        if(a == c || b == c) cout << "NO\n";
        else if(!isArticulationPoint[c]) cout << "YES\n";
        else{
            a = compNum[a]; b = compNum[b]; c = compNum[c];
            if((findLCA(a, c) == c || findLCA(b, c) == c) && depths[c] >= depths[findLCA(a, b)]) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
