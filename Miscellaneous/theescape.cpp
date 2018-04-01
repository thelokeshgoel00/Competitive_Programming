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
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, M, root = 0, dp1 [200010], dp2 [200010], dp3 [200010];
// 1: wolves to remove so everyone escapes to a leaf (considering only the subtree rooted at curr)
// 2: wolves to remove so everyone escapes to a leaf OR can reach de-wolfed curr
// 3: wolves to remove so everyone escapes to a leaf AND curr can get to a leaf
vector<int> adjacency [200010];
bool isPig [200010];

void extendIt(int u, int v){
    if(isPig[u]){
        dp1[u] = dp3[v];
        dp2[u] = min(dp1[v], dp2[v]);
        dp3[u] = dp3[v];
    }
    else{
        dp1[u] = dp1[v];
        dp2[u] = min(dp1[v], dp2[v])+1;
        dp3[u] = dp3[v]+1;
    }
}

void chainIt(int u, int v){
    int ndp1 = dp1[u]+dp1[v];
    ndp1 = min(ndp1, min(dp2[u]+dp3[v], dp2[v]+dp3[u]));
    int ndp2 = dp2[u]+min(dp1[v], dp2[v]);
    int ndp3 = min(dp3[u]+min(dp1[v], dp2[v]), dp2[u]+dp3[v]);
    dp1[u] = ndp1; dp2[u] = ndp2; dp3[u] = ndp3;
}

void solveIt(int curr, int prevy){
    if(adjacency[curr].size() == 1){
        dp1[curr] = 0;
        dp2[curr] = dp3[curr] = isPig[curr] ? 0 : 1;
        return;
    }
    bool firsty = true;
    for(int nexty : adjacency[curr]){
        if(nexty == prevy) continue;
        solveIt(nexty, curr);
        if(firsty){
            extendIt(curr, nexty);
            firsty = false;
        }
        else chainIt(curr, nexty);
    }
}

int main(){
    //freopen("disrupt.in", "r", stdin); freopen("disrupt.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; memset(isPig, false, sizeof(isPig));
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        isPig[x] = true;
    }
    while(adjacency[root].size() == 1) root++;
    solveIt(root, -1); cout << dp1[root] << '\n';
    return 0;
}
