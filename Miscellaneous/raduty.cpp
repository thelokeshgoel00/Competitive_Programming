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
#define INF 1000000000000000000
#define MOD 1000000007

int N, M, graph [200][200], dupe [200][200], prevs [200], ret = 1;
string names [100];
vector<int> assigned [40];

bool bfs(int source, int sink){
    queue<int> q; q.push(source);
    while(q.size() > 0){
        int curr = q.front(); q.pop();
        for(int i = 0; i < 160; i++)
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
        for(int i = 0; i < 160; i++) prevs[i] = -1;
        if(!bfs(source, sink)) break;
        int add = 1000000000;
        for(int i = sink; i != source; i = prevs[i]) add = min(add, dupe[prevs[i]][i]);
        flowy += add;
        for(int i = sink; i != source; i = prevs[i]){
            dupe[prevs[i]][i] -= add;
            dupe[i][prevs[i]] += add;
        }
        assigned[prevs[sink]-100].push_back(prevs[prevs[sink]]);
    }
    return flowy;
}

int main(){
    //freopen("mowing.in", "r", stdin); freopen("mowing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; memset(graph, 0, sizeof(graph));
    for(int i = 1; i <= N; i++){
        int d; cin >> names[i] >> d;
        graph[0][i] = ret;
        for(int j = 0; j < d; j++){
            int x; cin >> x; x--;
            graph[i][100+x] = 1;
        }
    }
    for(int i = 0; i < M; i++) graph[100+i][150] = 2;
    while(true){
        for(int a = 0; a < 160; a++)
            for(int b = 0; b < 160; b++)
                dupe[a][b] = graph[a][b];
        int ek = EdmondsKarp(0, 150);
        if(ek == 2*M) break;
        ret++; for(int a = 1; a <= N; a++) graph[0][a] = ret;
        for(int i = 0; i < M; i++) assigned[i].clear();
    }
    cout << ret << '\n';
    for(int i = 0; i < M; i++) cout << "Day " << i+1 << ": " << names[assigned[i][0]] << " " << names[assigned[i][1]] << '\n';
    return 0;
}
