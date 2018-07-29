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

int N, K, edgeID = 0, weights [10010], dp [10010][110][2][2];
vector<pair<int, int>> ori [10010], adjacency [10010];

void dfs(int curr, int prevy){
    for(pair<int, int> edge : ori[curr]){
        int nexty = edge.f;
        if(nexty == prevy) continue;
        adjacency[curr].pb(mp(nexty, edgeID));
        weights[edgeID] = edge.s; edgeID++;
        dfs(nexty, curr);
    }
}

int solveEdge(int id, int lower, int upper, int techs, int upperMarked);

int solveNode(int curr, int prevy, int techs, int parentMarked){
    if(dp[curr][techs][parentMarked][0] != -1) return dp[curr][techs][parentMarked][0];
    if(techs == 0) return dp[curr][techs][parentMarked][0] = 0;
    if(adjacency[curr].size() == 0) return dp[curr][techs][parentMarked][0] = parentMarked ? weights[prevy] : 0;
    int noMark = solveEdge(adjacency[curr][0].s, curr, techs, 0, 0);
    int yesMark = solveEdge(adjacency[curr][0].s, curr, techs-1, 1, 0);
    if(parentMarked) yesMark += weights[prevy];
    return dp[curr][techs][parentMarked][0] = max(noMark, yesMark);
}

int solveEdge(int id, int upper, int techs, int upperMarked, int num){
    if(dp[id][techs][upperMarked][1] != -1) return dp[id][techs][upperMarked][1];
    if(techs == 0 || (techs == 1 && !upperMarked)) return dp[id][techs][upperMarked][1] = 0;
    int lower = adjacency[upper][num].f;
    if(num == adjacency[upper].size()-1) return dp[id][techs][upperMarked][1] = solveNode(lower, adjacency[upper][num].s, techs, upperMarked);
    int ret = 0;
    for(int i = 0; i <= techs; i++){
        int nextID = adjacency[upper][num+1].s;
        ret = max(ret, solveEdge(nextID, upper, techs-i, upperMarked, num+1)+solveNode(lower, adjacency[upper][num].s, i, upperMarked));
    }
    return dp[id][techs][upperMarked][1] = ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> N >> K; K = min(K, N); memset(dp, -1, sizeof(dp));
    for(int i = 1; i < N; i++){
        int u, v, p; cin >> u >> v >> p;
        ori[u].pb(mp(v, p)); ori[v].pb(mp(u, p));
    }
    dfs(1, 0);
    cout << solveNode(1, -1, K, 0) << '\n';
    return 0;
}

/*
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

int N, K, sizes [10010];
vector<pair<int, int>> adjacency [10010];
vector<int> dp [10010][2];

void dfs(int curr, int prevy){
    sizes[curr] = 1;
    for(pair<int, int> edge : adjacency[curr]){
        int nexty = edge.f;
        if(nexty == prevy) continue;
        dfs(nexty, curr); sizes[curr] += sizes[nexty];
    }
    sizes[curr] = min(sizes[curr], K)+1;
}

int mergeSkip(vector<int> &rs, vector<int> s, int m){
    for(int i = m; i >= 0; i--)
        for(int j = 0; i+j < rs.size() && j < s.size(); j++)
				rs[i+j] = max(rs[i+j], rs[i]+s[j]);
    return min(rs.size(), m+s.size());
}

int mergeTake(vector<int> &rt, vector<int> t, int m){
    for(int i = m; i >= 1; i--)
        for(int j = 0; i+j < rt.size() && j < t.size(); j++)
				rt[i+j] = max(rt[i+j], rt[i]+t[j]);
    return min(rt.size(), m+t.size());
}

vector<int> solveNode(int curr, int parentMarked, int weight, int prevy){
    if(dp[curr][parentMarked].size() > 0) return dp[curr][parentMarked];
    vector<int> retSkip(sizes[curr], 0), retTake(sizes[curr], 0);
    retTake[1] = parentMarked ? weight : 0;
    int maxi = 1;
    for(pair<int, int> edge : adjacency[curr]){
        int nexty = edge.f;
        if(nexty == prevy) continue;
        vector<int> skippy = solveNode(nexty, 0, edge.s, curr), takey = solveNode(nexty, 1, edge.s, curr);
        maxi = mergeSkip(retSkip, skippy, maxi); maxi = mergeTake(retTake, takey, maxi);
    }
    for(int i = 0; i < retSkip.size(); i++) retSkip[i] = max(retSkip[i], retTake[i]);
    return dp[curr][parentMarked] = retSkip;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> N >> K; K = min(K, N); memset(dp, -1, sizeof(dp));
    for(int i = 1; i < N; i++){
        int u, v, p; cin >> u >> v >> p;
        adjacency[u].pb(mp(v, p)); adjacency[v].pb(mp(u, p));
    }
    dfs(1, 0);
    cout << solveNode(1, 0, 0, 0)[K] << '\n';
    return 0;
}
*/
