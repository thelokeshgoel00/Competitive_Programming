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

int N, Q, subtreeSizes [100010], parents [100010];
vector<int> ori [100010];
bool visited [100010], marked [100010];
vector<pair<int, int>> cenDists [100010];
set<pair<int, int>> queryDists [100010];

void findSubtreeSizes(int curr){
    subtreeSizes[curr] = 1;
    for(int nexty : ori[curr]){
        if(visited[nexty] || parents[curr] == nexty) continue;
        parents[nexty] = curr; findSubtreeSizes(nexty);
        subtreeSizes[curr] += subtreeSizes[nexty];
    }
}

int getCentroid(int curr){
    parents[curr] = 0; findSubtreeSizes(curr);
    int sz = subtreeSizes[curr];
    while(true){
        pair<int, int> maxi = make_pair(0, 0);
        for(int nexty : ori[curr]){
            if(visited[nexty] || parents[curr] == nexty) continue;
            maxi = max(maxi, make_pair(subtreeSizes[nexty], nexty));
        }
        if(maxi.first*2 > sz) curr = maxi.second;
        else return curr;
    }
    return -1;
}

void dfs(int curr, int dist, int source){
    cenDists[curr].pb(mp(source, dist));
    for(int nexty : ori[curr]){
        if(visited[nexty] || parents[curr] == nexty) continue;
        parents[nexty] = curr;
        dfs(nexty, dist+1, source);
    }
}

void decomposeIt(int curr){
    curr = getCentroid(curr); visited[curr] = true;
    for(int nexty : ori[curr]){
        if(visited[nexty]) continue;
        parents[nexty] = curr; dfs(nexty, 1, curr);
    }
    cenDists[curr].pb(mp(curr, 0));
    for(int nexty : ori[curr])
        if(!visited[nexty])
            decomposeIt(nexty);
}

void update(int curr){
    marked[curr] = !marked[curr];
    for(pair<int, int> vd : cenDists[curr]){
        if(marked[curr]) queryDists[vd.f].insert(mp(vd.s, curr));
        else queryDists[vd.f].erase(mp(vd.s, curr));
    }
}

int query(int curr){
    int ret = MOD;
    for(pair<int, int> vd : cenDists[curr])
        if(queryDists[vd.f].size() > 0)
            ret = min(ret, vd.s+(*queryDists[vd.f].begin()).f);
    if(ret == MOD) ret = -1;
    return ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        ori[a].pb(b); ori[b].pb(a);
    }
    decomposeIt(1);
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int type, x; cin >> type >> x;
        if(type == 0) update(x);
        else cout << query(x) << '\n';
    }
    return 0;
}
