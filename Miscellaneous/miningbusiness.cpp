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

int N = 100000, M, tiempo = 0, compID = 0, parents [100010], disc [100010], low [100010];
vector<int> oriAdjacency [100010];
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
    tiempo = 0; compID = 0;
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


int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    for(int kk = 1; ; kk++){
        cin >> M; if(M == 0) break;
        resetIt(); N = 0;
        for(int i = 0; i < M; i++){
            int a, b; cin >> a >> b; N = max(N, max(a, b));
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
        cout << "Case " << kk << ": ";
        if(compID == 1){ cout << "2 " << ((long long)N*(long long)(N-1))/2 << '\n'; continue; }
        long long leaves = 0, ways = 1;
        for(int k = 0; k < compID; k++){
            set<int> verts, arts;
            for(pair<int, int> lol : bccs[k]){
                if(!isArticulationPoint[lol.f]) verts.insert(lol.f);
                else arts.insert(lol.f);
                if(!isArticulationPoint[lol.s]) verts.insert(lol.s);
                else arts.insert(lol.s);
            }
            if(arts.size() == 1){
                leaves++;
                ways *= (long long)verts.size();
            }
        }
        cout << leaves << ' ' << ways << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
