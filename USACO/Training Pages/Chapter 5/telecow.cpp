/*
ID: vamaddu1
PROG: telecow
LANG: C++11
*/


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

int N, M, C1, C2, graph [210][210], dupe [210][210], prevs [210], curFlow;
vector<int> ret;

bool bfs(int source, int sink){
    queue<int> q; q.push(source);
    while(q.size() > 0){
        int curr = q.front(); q.pop();
        for(int i = 0; i < 2*N; i++)
            if(dupe[curr][i] > 0 && prevs[i] == -1){
                prevs[i] = curr;
                if(i == sink) return true;
                q.push(i);
            }
    }
    return false;
}

int EdmondsKarp(int source, int sink){
    int flowy = 0;
    while(true){
        for(int i = 0; i < 2*N; i++) prevs[i] = -1;
        if(!bfs(source, sink)) break;
        int add = 1000000000;
        for(int i = sink; i != source; i = prevs[i]) add = min(add, dupe[prevs[i]][i]);
        flowy += add;
        for(int i = sink; i != source; i = prevs[i]){
            dupe[prevs[i]][i] -= add;
            dupe[i][prevs[i]] += add;
        }
    }
    return flowy;
}

int main(){
    freopen("telecow.in", "r", stdin); freopen("telecow.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M >> C1 >> C2; C1--; C2--;
    memset(graph, 0, sizeof(graph));
    for(int i = 0; i < N; i++) graph[2*i][2*i+1]++;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b; a--; b--;
        graph[2*a+1][2*b]++; graph[2*b+1][2*a]++;
    }
    for(int a = 0; a < 210; a++)
            for(int b = 0; b < 210; b++)
                dupe[a][b] = graph[a][b];
    curFlow = EdmondsKarp(C1*2+1, C2*2);
    for(int i = 0; i < N; i++){
        if(i == C1 || i == C2) continue;
        graph[2*i][2*i+1]--;
        for(int a = 0; a < 210; a++)
            for(int b = 0; b < 210; b++)
                dupe[a][b] = graph[a][b];
        int newFlow = EdmondsKarp(C1*2+1, C2*2);
        //cout << i << " " << curFlow << " " << newFlow << endl;
        if(newFlow == curFlow){ graph[2*i][2*i+1]++; continue; }
        curFlow = newFlow;
        ret.push_back(i+1);
        if(curFlow == 0) break;
    }
    cout << ret.size() << '\n';
    for(int i = 0; i < ret.size()-1; i++) cout << ret[i] << ' ';
    cout << ret[ret.size()-1] << '\n';
    return 0;
}
