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
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

struct Edge{
    int destination, capacity, residualFlow, cost;
    Edge* counterEdge;
};

struct Graph{
    int numVertices;
    vector<Edge*> *adj;
};

Edge* genEdge(int destination, int capacity, int residualFlow, int cost){
    Edge* e1 = new Edge;
    e1->destination = destination; e1->capacity = capacity;
    e1->residualFlow = residualFlow; e1->cost = cost;
    return e1;
}

int C, N, S, T, ret;
Graph g, resGraph;

bool BF(Graph resGraph, int source, int sink, int parentVertex[], Edge* parentEdge[]){
    int numVertices = resGraph.numVertices;
    vector<Edge*> *adj = resGraph.adj;
    int distance[numVertices];
    for(int i = 0; i < numVertices; i++){
        parentVertex[i] = -1;
        distance[i] = MOD;
    }
    distance[source] = 0;
    for(int i = 0; i < numVertices-1; i++)
        for(int u = 0; u < numVertices; u++)
            for(int e = 0; e < adj[u].size(); e++){
                if(adj[u][e]->residualFlow > 0){
                    int v = adj[u][e]->destination;
                    int w = adj[u][e]->cost;
                    if(distance[v] > distance[u]+w){
                        distance[v] = distance[u]+w;
                        parentVertex[v] = u;
                        parentEdge[v] = adj[u][e];
                    }
                }
            }
    return parentVertex[sink] != -1;
}

int calcMinCostFlow(int s, int t, int requiredFlow){
    int u, v, currFlow = 0, runningCost = 0;
    Edge *te1, *te2;
    int parent[g.numVertices];
    Edge* parentEdge[g.numVertices];
    while(BF(resGraph, s, t, parent, parentEdge)){
        int path_flow = MOD;
        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            te1 = parentEdge[v];
            path_flow = min(path_flow, te1->residualFlow);
        }
        path_flow = min(path_flow, requiredFlow-currFlow);
        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            te1 = parentEdge[v];
            te2 = te1->counterEdge;
            te1->residualFlow -= path_flow;
            te2->residualFlow += path_flow;
            runningCost += path_flow*(te1->cost);
        }
        currFlow += path_flow;
        if(currFlow == requiredFlow) break;
    }
    if(currFlow == requiredFlow) return runningCost;
    else return MOD;
}


int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> C >> N;
    for(int kk = 1; kk <= C; kk++){
        cin >> S >> T; g = Graph(), resGraph = Graph();
        g.numVertices = N; g.adj = new vector<Edge*>[N];
        resGraph.numVertices = N; resGraph.adj = new vector<Edge*>[N];
        for(int i = 0; i < N; i++){
            int j = (i+1)%N;
            Edge* tmpEdge1 = genEdge(j, 1, 1, 1);
            Edge* tmpEdge2 = genEdge(i, 1, 0, -1);
            tmpEdge1->counterEdge = tmpEdge2;
            tmpEdge2->counterEdge = tmpEdge1;
            g.adj[i].push_back(tmpEdge1);
            resGraph.adj[i].push_back(tmpEdge1);
            resGraph.adj[j].push_back(tmpEdge2);
        }
        for(int i = 0; i < N; i++){
            int j = (i*i)%N;
            Edge* tmpEdge1 = genEdge(j, 1, 1, 2);
            Edge* tmpEdge2 = genEdge(i, 1, 0, -2);
            tmpEdge1->counterEdge = tmpEdge2;
            tmpEdge2->counterEdge = tmpEdge1;
            g.adj[i].push_back(tmpEdge1);
            resGraph.adj[i].push_back(tmpEdge1);
            resGraph.adj[j].push_back(tmpEdge2);
        }
        for(int i = 0; i < N; i++){
            int j = (i*i*i)%N;
            Edge* tmpEdge1 = genEdge(j, 1, 1, 3);
            Edge* tmpEdge2 = genEdge(i, 1, 0, -3);
            tmpEdge1->counterEdge = tmpEdge2;
            tmpEdge2->counterEdge = tmpEdge1;
            g.adj[i].push_back(tmpEdge1);
            resGraph.adj[i].push_back(tmpEdge1);
            resGraph.adj[j].push_back(tmpEdge2);
        }
        ret = calcMinCostFlow(S, T, 2);
        if(ret == MOD) cout << "impossible\n";
        else cout << ret << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
