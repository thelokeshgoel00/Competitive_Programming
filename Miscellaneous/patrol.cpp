#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, K, dists [100010], prevs [100010], endpointA, endpointB, ret, miniDiameter = 0;
set<pair<int, int>> adjacency [100010];

void bfs(int start){
    queue<pair<int, pair<int, int>>> q; memset(prevs, -1, sizeof(prevs));
    q.push(make_pair(0, make_pair(start, 0))); endpointB = start;
    while(q.size() > 0){
        pair<int, pair<int, int>> now = q.front(); q.pop();
        if(prevs[now.second.first] != -1) continue;
        dists[now.second.first] = now.first; prevs[now.second.first] = now.second.second;
        if(dists[now.second.first] > dists[endpointB]) endpointB = now.second.first;
        for(pair<int, int> edge : adjacency[now.second.first])
            if(prevs[edge.first] == -1)
                q.push(make_pair(now.first+edge.second, make_pair(edge.first, now.second.first)));
    }
}

int solveTwo(int curr, int prevy){
    int best = 0, tbest = 0;
    for(pair<int, int> edge : adjacency[curr]){
        if(edge.first == prevy) continue;
        int childRet = solveTwo(edge.first, curr);
        if(best < childRet+edge.second){
            tbest = best;
            best = childRet+edge.second;
        }
        else if(tbest < childRet+edge.second) tbest = childRet+edge.second;
    }
    miniDiameter = max(miniDiameter, best+tbest);
    return best;
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d %d", &N, &K); ret = 2*(N-1)+K;
    for(int i = 1; i < N; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].insert({b, 1}); adjacency[b].insert({a, 1});
    }
    bfs(1); endpointA = endpointB; bfs(endpointA);
    while(endpointB != endpointA){
        adjacency[endpointB].erase(make_pair(prevs[endpointB], 1)); adjacency[endpointB].insert(make_pair(prevs[endpointB], -1));
        adjacency[prevs[endpointB]].erase(make_pair(endpointB, 1)); adjacency[prevs[endpointB]].insert(make_pair(endpointB, -1));
        ret--; endpointB = prevs[endpointB];
    }
    if(K == 2) solveTwo(1, 0);
    cout << ret-miniDiameter << '\n';
    return 0;
}
