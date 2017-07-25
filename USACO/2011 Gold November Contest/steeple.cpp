#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

#define INF 1000000000

struct Edge{
    int from, to, cap, flow, backIndex;
    Edge(int a, int b, int c, int d): from(a), to(b), cap(c), flow(d) {}
};

struct Dinic{
    int n, source, sink, dist [1000];
    queue<int> q;
    vector<Edge> adjacency [1000];
    bool blocked [1000];
    Dinic(int x): n(x), source(n++), sink(n++) { }
    void add(int v1, int v2, int c, int f){
        Edge e(v1, v2, c, f); Edge r(v2, v1, 0, 0);
        e.backIndex = adjacency[v2].size(); r.backIndex = adjacency[v1].size();
        adjacency[v1].push_back(e); adjacency[v2].push_back(r);
    }
    bool bfs(){
        q = queue<int>(); fill_n(dist, 1000, -1); dist[sink] = 0; q.push(sink);
        while(q.size() > 0){
            int node = q.front(); q.pop();
            if(node == source) return true;
            for(int i = 0; i < adjacency[node].size(); i++){
                if(adjacency[adjacency[node][i].to][adjacency[node][i].backIndex].cap >
                   adjacency[adjacency[node][i].to][adjacency[node][i].backIndex].flow && dist[adjacency[node][i].to] == -1){
                    dist[adjacency[node][i].to] = dist[node]+1;
                    q.push(adjacency[node][i].to);
                }
            }
        }
        return dist[source] != -1;
    }
    int dfs(int pos, int mini){
        if(pos == sink) return mini;
        int flowy = 0;
        for(int i = 0; i < adjacency[pos].size(); i++){
            int curr = 0;
            if(!blocked[adjacency[pos][i].to] && dist[adjacency[pos][i].to] == dist[pos]-1 && adjacency[pos][i].cap > adjacency[pos][i].flow){
                curr = dfs(adjacency[pos][i].to, min(mini-flowy, adjacency[pos][i].cap-adjacency[pos][i].flow));
                adjacency[pos][i].flow += curr; adjacency[adjacency[pos][i].to][adjacency[pos][i].backIndex].flow -= adjacency[pos][i].flow;
                flowy += curr;
            }
            if(flowy == mini) return flowy;
        }
        blocked[pos] = flowy != mini;
        return flowy;
    }
    int flow(){
        int ret = 0; fill_n(blocked, 1000, false);
        while(bfs()){
            fill_n(blocked, 1000, false);
            ret += dfs(source, INF);
            //cout << ret << endl;
        }
        return ret;
    }
};

int numSegments, Hindex = 0, Vindex = 0, horizontal [250][4], vertical [250][4];

int main(){
    freopen("steeple.in", "r", stdin); freopen("steeple.out", "w", stdout);
    scanf("%d", &numSegments); Dinic solve(numSegments);
    for(int i = 0; i < numSegments; i++){
        int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
        if(b == d){
            horizontal[Hindex][0] = a; horizontal[Hindex][1] = b;
            horizontal[Hindex][2] = c; horizontal[Hindex][3] = d;
            solve.add(solve.source, Hindex, 1, 0); Hindex++;
        }
        else{
            vertical[Vindex][0] = a; vertical[Vindex][1] = b;
            vertical[Vindex][2] = c; vertical[Vindex][3] = d;
            Vindex++;
        }
    }
    for(int i = 0; i < Vindex; i++) solve.add(Hindex+i, solve.sink, 1, 0);
    for(int i = 0; i < Hindex; i++)
        for(int j = 0; j < Vindex; j++){
            if(abs(vertical[j][0]-horizontal[i][0])+abs(vertical[j][0]-horizontal[i][2]) == abs(horizontal[i][0]-horizontal[i][2]))
                if(abs(vertical[j][1]-horizontal[i][1])+abs(vertical[j][3]-horizontal[i][1]) == abs(vertical[j][1]-vertical[j][3])){
                    solve.add(i, Hindex+j, 1, 0);
                    //cout << i << " " << Hindex+j << endl;
                }
        }
    cout << numSegments-solve.flow() << endl;
    return 0;
}

/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 1000000000
struct Edge{
    int from, to, cap, flow;
    Edge* backwards;
    Edge(int a, int b, int c, int d): from(a), to(b), cap(c), flow(d) {}
};
struct Dinic{
    int n, source, sink, dist [1000];
    queue<int> q;
    vector<Edge> adjacency [1000];
    bool blocked [1000];
    Dinic(int x): n(x), source(n++), sink(n++) { }
    void add(int v1, int v2, int c, int f){
        Edge e(v1, v2, c, f); Edge r(v2, v1, 0, 0);
        adjacency[v1].push_back(e); adjacency[v2].push_back(r);
        adjacency[v1].back().backwards = &adjacency[v2].back();
        adjacency[v2].back().backwards = &adjacency[v1].back();
    }
    bool bfs(){
        q = queue<int>(); fill_n(dist, 1000, -1); dist[sink] = 0; q.push(sink);
        while(q.size() > 0){
            int node = q.front(); q.pop();
            if(node == source) return true;
            for(int i = 0; i < adjacency[node].size(); i++){
                if(adjacency[node][i].backwards->cap > adjacency[node][i].backwards->flow && dist[adjacency[node][i].to] == -1){
                    dist[adjacency[node][i].to] = dist[node]+1;
                    q.push(adjacency[node][i].to);
                }
            }
        }
        return dist[source] != -1;
    }
    int dfs(int pos, int mini){
        if(pos == sink) return mini;
        int flowy = 0;
        for(int i = 0; i < adjacency[pos].size(); i++){
            int curr = 0;
            if(!blocked[adjacency[pos][i].to] && dist[adjacency[pos][i].to] == dist[pos]-1 && adjacency[pos][i].cap > adjacency[pos][i].flow){
                curr = dfs(adjacency[pos][i].to, min(mini-flowy, adjacency[pos][i].cap-adjacency[pos][i].flow));
                adjacency[pos][i].flow += curr; adjacency[pos][i].backwards->flow -= adjacency[pos][i].flow;
                flowy += curr;
            }
            if(flowy == mini) return flowy;
        }
        blocked[pos] = flowy != mini;
        return flowy;
    }
    int flow(){
        int ret = 0; fill_n(blocked, 1000, false);
        while(bfs()){
            fill_n(blocked, 1000, false);
            ret += dfs(source, INF);
            //cout << ret << endl;
        }
        return ret;
    }
};
int numSegments, Hindex = 0, Vindex = 0, horizontal [250][4], vertical [250][4];
int main(){
    freopen("steeple.in", "r", stdin); freopen("steeple.out", "w", stdout);
    scanf("%d", &numSegments); Dinic solve(numSegments);
    for(int i = 0; i < numSegments; i++){
        int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
        if(b == d){
            horizontal[Hindex][0] = a; horizontal[Hindex][1] = b;
            horizontal[Hindex][2] = c; horizontal[Hindex][3] = d;
            solve.add(solve.source, Hindex, 1, 0); Hindex++;
        }
        else{
            vertical[Vindex][0] = a; vertical[Vindex][1] = b;
            vertical[Vindex][2] = c; vertical[Vindex][3] = d;
            Vindex++;
        }
    }
    for(int i = 0; i < Vindex; i++) solve.add(Hindex+i, solve.sink, 1, 0);
    for(int i = 0; i < Hindex; i++)
        for(int j = 0; j < Vindex; j++){
            if(abs(vertical[j][0]-horizontal[i][0])+abs(vertical[j][0]-horizontal[i][2]) == abs(horizontal[i][0]-horizontal[i][2]))
                if(abs(vertical[j][1]-horizontal[i][1])+abs(vertical[j][3]-horizontal[i][1]) == abs(vertical[j][1]-vertical[j][3])){
                    solve.add(i, Hindex+j, 1, 0);
                    //cout << i << " " << Hindex+j << endl;
                }
        }
    cout << numSegments-solve.flow() << endl;
    return 0;
}
*/
