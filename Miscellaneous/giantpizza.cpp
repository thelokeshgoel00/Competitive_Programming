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
#define epsilon 1e-12
#define INF 5e18
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

struct SCC{
    int N, sccID, tiempo;
    int disc [200010], low [200010], sccNum [200010];
    vector<int> oriAdjacency [200010], sccNodes [200010], sccAdjacency [200010];
    bool inStack [200010];
    stack<int> componente;

    void resetIt(){
        sccID = tiempo = 0;
        for(int i = 0; i < N; i++){
            disc[i] = low[i] = sccNum[i] = -1;
            oriAdjacency[i] = vector<int>();
            sccNodes[i] = vector<int>();
            sccAdjacency[i] = vector<int>();
        }
    }

    void addEdge(int a, int b){ oriAdjacency[a].pb(b); }

    void findSCC(int curr){
        disc[curr] = tiempo; low[curr] = tiempo; tiempo++;
        componente.push(curr); inStack[curr] = true;
        for(int i = 0; i < oriAdjacency[curr].size(); i++){
            int next = oriAdjacency[curr][i];
            if(disc[next] == -1){
                findSCC(next);
                low[curr] = min(low[curr], low[next]);
            }
            else if(inStack[next]) low[curr] = min(low[curr], disc[next]);
        }
        if(low[curr] == disc[curr]){
            int now = -1;
            while(componente.top() != curr){
                now = componente.top(); componente.pop();
                sccNodes[sccID].pb(now);
                inStack[now] = false; sccNum[now] = sccID;
            }
            now = componente.top(); componente.pop();
            sccNodes[sccID].pb(now);
            inStack[now] = false; sccNum[now] = sccID;
            sccID++;
        }
    }

    void findSCC(){
        for(int i = 0; i < N; i++)
            if(disc[i] == -1)
                findSCC(i);
    }
};

struct TwoSat{
    int N;
    SCC scc;
    bool ret [100010];

    void resetIt(){
        scc.N = 2*N; scc.resetIt();
        for(int i = 0; i < N; i++) ret[i] = false;
    }

    int addVar(){ return N++; }

    void either(int x, int y){
        x = max(2*x,-1-2*x), y = max(2*y,-1-2*y);
        scc.addEdge(x^1, y); scc.addEdge(y^1,x);
    }
    void implies(int x, int y) { either(~x, y); }
    void setVal(int x) { either(x, x); }
    void atMostOne(const vector<int> &group){
        if(group.size() <= 1) return;
        int curr = ~group[0];
        for(int i = 2; i < group.size(); i++){
            int nexty = addVar();
            either(curr, ~group[i]);
            either(curr, nexty);
            either(~group[i], nexty);
            curr = ~nexty;
        }
        either(curr, ~group[1]);
    }

    bool solveIt(){
        scc.findSCC();
        for(int i = 0; i < 2*N; i += 2)
            if(scc.sccNum[i] == scc.sccNum[i^1])
                return 0;
        vector<int> temp(scc.sccID);
        for(int i = 0; i < scc.sccID; i++)
            if(temp[i] == 0)
            temp[i] = 1, temp[scc.sccNum[scc.sccNodes[i].front()^1]] = -1;
        for(int i = 0; i < N; i++)
            if(temp[scc.sccNum[2*i]] == 1)
                ret[i] = true;
        return true;
    }
};

int numConditions;
TwoSat solver;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> numConditions >> solver.N; solver.resetIt();
    for(int i = 0; i < numConditions; i++){
        char c1, c2; int v1, v2; cin >> c1 >> v1 >> c2 >> v2; v1--; v2--;
        if(c1 == '-') v1 = ~v1;
        if(c2 == '-') v2 = ~v2;
        solver.either(v1, v2);
    }
    if(!solver.solveIt()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i = 0; i < solver.N; i++) cout << (solver.ret[i] ? '+' : '-') << (i == solver.N-1 ? '\n' : ' ');
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
