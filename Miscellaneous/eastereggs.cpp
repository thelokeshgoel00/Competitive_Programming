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

struct Edge{
    int from, to, cap, flow, backIndex;
    Edge(int a, int b, int c, int d): from(a), to(b), cap(c), flow(d) {}
};

struct Dinic{
    int n, source, sink, dist [1000];
    queue<int> q;
    vector<Edge> adjacency [1000];
    bool blocked [1000];
    Dinic(int x): n(x), source(n++), sink(n++) { }
    void add(int v1, int v2, int c, int f){
        Edge e(v1, v2, c, f); Edge r(v2, v1, 0, 0);
        e.backIndex = adjacency[v2].size(); r.backIndex = adjacency[v1].size();
        adjacency[v1].push_back(e); adjacency[v2].push_back(r);
    }
    bool bfs(){
        q = queue<int>(); fill_n(dist, 1000, -1); dist[sink] = 0; q.push(sink);
        while(q.size() > 0){
            int node = q.front(); q.pop();
            if(node == source) return true;
            for(int i = 0; i < adjacency[node].size(); i++){
                if(adjacency[adjacency[node][i].to][adjacency[node][i].backIndex].cap >
                   adjacency[adjacency[node][i].to][adjacency[node][i].backIndex].flow && dist[adjacency[node][i].to] == -1){
                    dist[adjacency[node][i].to] = dist[node]+1;
                    q.push(adjacency[node][i].to);
                }
            }
        }
        return dist[source] != -1;
    }
    int dfs(int pos, int mini){
        if(pos == sink) return mini;
        int flowy = 0;
        for(int i = 0; i < adjacency[pos].size(); i++){
            int curr = 0;
            if(!blocked[adjacency[pos][i].to] && dist[adjacency[pos][i].to] == dist[pos]-1 && adjacency[pos][i].cap > adjacency[pos][i].flow){
                curr = dfs(adjacency[pos][i].to, min(mini-flowy, adjacency[pos][i].cap-adjacency[pos][i].flow));
                adjacency[pos][i].flow += curr; adjacency[adjacency[pos][i].to][adjacency[pos][i].backIndex].flow -= adjacency[pos][i].flow;
                flowy += curr;
            }
            if(flowy == mini) return flowy;
        }
        blocked[pos] = flowy != mini;
        return flowy;
    }
    int flow(){
        int ret = 0; fill_n(blocked, 1000, false);
        while(bfs()){
            fill_n(blocked, 1000, false);
            ret += dfs(source, MOD);
        }
        return ret;
    }
};

int N, B, R;
pair<double, double> blue [300], red [300];
double lo = 0, hi = MOD;
Dinic solver(600);

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> B >> R;
    for(int i = 0; i < B; i++) cin >> blue[i].f >> blue[i].s;
    for(int i = 0; i < R; i++) cin >> red[i].f >> red[i].s;
    while(hi-lo > epsilon){
        double mid = (lo+hi)/2;
        solver = Dinic(B+R);
        for(int i = 0; i < B; i++) solver.add(solver.source, i, 1, 0);
        for(int i = 0; i < R; i++) solver.add(B+i, solver.sink, 1, 0);
        for(int i = 0; i < B; i++)
            for(int j = 0; j < R; j++)
                if(pow(blue[i].f-red[j].f, 2)+pow(blue[i].s-red[j].s, 2) <= mid*mid)
                    solver.add(i, B+j, 1, 0);
        if(B+R-solver.flow() >= N) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
    return 0;
}
