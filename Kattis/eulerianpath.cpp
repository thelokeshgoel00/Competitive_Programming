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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

struct Euler {
    vector<pair<int, int>> adjacency [100010], circuit;
    int N, M, nexty, out [100010], in [100010], deg [100010];
    bool used [100010], bad;
    void clearIt(){
        for(int i = 0; i < N; i++){
            adjacency[i] = vector<pair<int, int>>();
            out[i] = in[i] = deg[i] = 0;
        }
        circuit = vector<pair<int, int>>(); nexty = 0; bad = false;
        for(int i = 0; i < M; i++) used[i] = false;
    }
    void findCircuit(int prevy, int curr){
        while(adjacency[curr].size() > 0){
            pair<int, int> x = adjacency[curr].back(); adjacency[curr].pop_back();
            if(used[x.s]) continue;
            used[x.s] = true;
            findCircuit(curr, x.f);
        }
        if(circuit.size() > 0 && circuit.back().f != curr) bad = true;
        circuit.pb({prevy, curr});
    }
    void addEdge(int a, int b, bool directed){
        if(directed){
            adjacency[a].pb({b, nexty});
            out[a]++; in[b]++; nexty++;
        }
        else{
            adjacency[a].pb({b, nexty}), adjacency[b].pb({a, nexty});
            deg[a]++; deg[b]++; nexty++;
        }
    }
    vector<int> solve(bool directed){
        int start = 0;
        for(int i = 0; i < N; i++)
            if(deg[i] || in[i] || out[i])
                start = i;
        if(directed){
            for(int i = 0; i < N; i++)
                if(out[i]-in[i] == 1)
                    start = i;
        }
        else{
            for(int i = 0; i < N; i++)
                if(deg[i]%2)
                    start = i;
        }
        findCircuit(-1, start); vector<int> ans;
        if(circuit.size() != M+1 || bad) return ans;
        for(int i = circuit.size()-1; i > -1; i--) ans.pb(circuit[i].s);
        return ans;
    }
};

Euler euro;

int main(){
    //freopen("feed.in", "r", stdin); freopen("feed.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    while(true){
        cin >> euro.N >> euro.M;
        if(euro.N == 0 && euro.M == 0) break;
        else euro.clearIt();
        for(int i = 0; i < euro.M; i++){
            int a, b; cin >> a >> b;
            euro.addEdge(a, b, 1);
        }
        vector<int> ret = euro.solve(1);
        if(ret.size() == 0) cout << "Impossible";
        else{
            for(int i = 0; i < ret.size(); i++){
                if(i) cout << ' ';
                cout << ret[i];
            }
        }
        cout << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
