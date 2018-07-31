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

int N, Q, subtreeSizes [100010], parents [100010], cenPar [100010], depths [100010], table [20][100010], ans [100010];
vector<int> ori [100010];
bool visited [100010];

void preDFS(int curr, int prevy, int d){
    depths[curr] = d; table[0][curr] = prevy;
    for(int i : ori[curr])
        if(i != prevy)
            preDFS(i, curr, d+1);
}

void buildIt(){
    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= N; j++)
            table[i][j] = table[i-1][table[i-1][j]];
}

int lca(int p, int q){
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

void dfs(int curr){
    for(int nexty : ori[curr]){
        if(visited[nexty] || parents[curr] == nexty) continue;
        parents[nexty] = curr;
        dfs(nexty);
    }
}

void decomposeIt(int curr, int par){
    curr = getCentroid(curr); visited[curr] = true;
    if(par == 0) par = curr;
    cenPar[curr] = par;
    for(int nexty : ori[curr]){
        if(visited[nexty]) continue;
        parents[nexty] = curr; dfs(nexty);
    }
    for(int nexty : ori[curr])
        if(!visited[nexty])
            decomposeIt(nexty, curr);
}

int dist(int x, int y){ return depths[x]+depths[y]-2*depths[lca(x, y)]; }

void update(int curr){
    int cen = curr;
    while(true){
        ans[cen] = min(ans[cen], dist(cen, curr));
        if(cen == cenPar[cen]) break;
        cen = cenPar[cen];
    }
}

int query(int curr){
    int cen = curr, ret = MOD;
    while(true){
        ret = min(ret, ans[cen]+dist(cen, curr));
        if(cen == cenPar[cen]) break;
        cen = cenPar[cen];
    }
    return ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> N >> Q;
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        ori[a].pb(b); ori[b].pb(a);
    }
    preDFS(1, 1, 0); buildIt(); decomposeIt(1, 0);
    fill(ans, ans+100010, MOD); update(1);
    for(int i = 0; i < Q; i++){
        int type, x; cin >> type >> x;
        if(type == 1) update(x);
        else cout << query(x) << '\n';
    }
    return 0;
}
