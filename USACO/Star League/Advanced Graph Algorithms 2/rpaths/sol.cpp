#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000
#define MOD 1000000007

int N, M, parents [5010], disc [5010], low [5010], tiempo = 0, compID = 0, compNum [5010], degree [5010], pendantCount = 0;
bool visited [5010];
vector<int> adjacency [20010];
map<pair<int, int>, int> edgeFreq;
set<pair<int, int>> bridges;
vector<vector<int>> componentes;

void findBridges(int curr){
    visited[curr] = true; disc[curr] = low[curr] = tiempo++;
    for(int next : adjacency[curr]){
        if(!visited[next]){
            parents[next] = curr; findBridges(next);
            low[curr] = min(low[curr], low[next]);
            if(low[next] > disc[curr] && edgeFreq[make_pair(min(curr, next), max(curr, next))] == 1)
                bridges.insert(make_pair(min(curr, next), max(curr, next)));
        }
        else if(next != parents[curr]) low[curr] = min(low[curr], disc[next]);
    }
}

int main(){
    //freopen("grass.in", "r", stdin); freopen("grass.out", "w", stdout);
    scanf("%d %d", &N, &M);
    memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low)); memset(parents, -1, sizeof(parents));
    memset(visited, false, sizeof(visited)); memset(compNum, -1, sizeof(compNum)); memset(degree, 0, sizeof(degree));
    for(int i = 0; i < M; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(b); adjacency[b].push_back(a);
        if(edgeFreq.find(make_pair(min(a, b), max(a, b))) == edgeFreq.end()) edgeFreq[make_pair(min(a, b), max(a, b))] = 0;
        edgeFreq[make_pair(min(a, b), max(a, b))]++;
    }
    for(int i = 1; i <= N; i++)
        if(!visited[i])
            findBridges(i);
    for(int i = 1; i <= N; i++){
        if(compNum[i] > -1) continue;
        queue<int> q; q.push(i);
        while(q.size() > 0){
            int x = q.front(); q.pop();
            if(compNum[x] > -1) continue;
            compNum[x] = compID;
            for(int y : adjacency[x])
                if(compNum[y] == -1 && bridges.find(make_pair(min(x, y), max(x, y))) == bridges.end())
                    q.push(y);
        }
        compID++;
    }
    for(pair<int, int> edge : bridges){
        degree[compNum[edge.first]]++;
        degree[compNum[edge.second]]++;
    }
    for(int i = 0; i < compID; i++)
        if(degree[i] == 1)
            pendantCount++;
    cout << (pendantCount+1)/2 << '\n';
    return 0;
}
