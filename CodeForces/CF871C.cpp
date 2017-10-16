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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

// Nodes are lines and edges
// are points in the compressed graph

int N, numVertices, numEdges;
unordered_map<int, vector<int>> adjacency;
set<int> notVisited;
long long powMod [100010], ret = 1ll;

void bfs(int curr){
    numVertices++; notVisited.erase(curr);
    for(int i : adjacency[curr]){
        numEdges++;
        if(notVisited.find(i) != notVisited.end()) bfs(i);
    }
}

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    powMod[0] = 1ll; for(int i = 1; i < 100010; i++) powMod[i] = (powMod[i-1]*2ll)%MOD;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        notVisited.insert(2*x); notVisited.insert(2*y+1);
        adjacency[2*x].push_back(2*y+1); adjacency[2*y+1].push_back(2*x);
    }
    while(notVisited.size() > 0){
        int start = *notVisited.begin(); numVertices = numEdges = 0;
        bfs(start); numEdges /= 2;
        if(numEdges == numVertices-1) ret = (ret*(powMod[numVertices]-1ll))%MOD;
        else ret = (ret*powMod[numVertices])%MOD;
    }
    cout << ret << '\n';
    return 0;
}
