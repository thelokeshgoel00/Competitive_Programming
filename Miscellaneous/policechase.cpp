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

struct Edge{
    long long v, flow, C, rev;
};

struct Dinic {
    long long level [2050], start [2050], cache [2050];
    bool reachable [2050];
    vector<Edge> adj [2050];
    void addEdge(int u, int v, long long C){
        Edge a{v, 0, C, (long long)adj[v].size()};
        Edge b{u, 0, 0, (long long)adj[u].size()};
        adj[u].pb(a); adj[v].pb(b);
    }
    bool BFS(int s, int t){
        for(int i = 0; i < 2050; i++) level[i] = -1;
        queue<int> q; level[s] = 0; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto e : adj[u])
                if(level[e.v] < 0  && e.flow < e.C){
                    level[e.v] = level[u]+1;
                    q.push(e.v);
                }
        }
        return level[t] != -1;
    }
    long long sendFlow(int u, long long flow, int t){
        if(u == t) return flow;
        for(  ; start[u] < adj[u].size(); start[u] ++){
            Edge &e = adj[u][start[u]];
            if(level[e.v] == level[u]+1 && e.flow < e.C){
                long long curr_flow = min(flow, e.C-e.flow);
                long long temp_flow = sendFlow(e.v, curr_flow, t);
                if(temp_flow > 0){
                    e.flow += temp_flow;
                    adj[e.v][e.rev].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
        return 0;
    }
    long long DinicMaxflow(int s, int t){
        if(s == t) return -1;
        long long total = 0;
        while(BFS(s, t)){
            for(int i = 0; i < 2050; i++) start[i] = 0;
            while (long long flow = sendFlow(s, INF, t)) total += flow;
        }
        return total;
    }
    void finalBfs(int s){
        queue<int> q; reachable[s] = true; q.push(s);
        while(q.size() > 0){
            int curr = q.front(); q.pop();
            for(auto e : adj[curr])
                if(e.flow < e.C && !reachable[e.v]){
                    reachable[e.v] = true;
                    q.push(e.v);
                }
        }
    }
};

int N, M;
Dinic solve;
bool used [510][510];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        solve.addEdge(a, b, 1); solve.addEdge(b, a, 1);
    }
    cout << solve.DinicMaxflow(1, N) << '\n'; solve.finalBfs(1);
    for(int i = 1; i <= N; i++)
        for(auto e : solve.adj[i])
            if(solve.reachable[i]^solve.reachable[e.v] && !used[i][e.v]){
                cout << i << ' ' << e.v << '\n';
                used[i][e.v] = used[e.v][i] = true;
            }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
