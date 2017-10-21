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

int N, M;
vector<pair<int, long long>> adjacency [3][10010]; // 0 = GPS #1, 1 = GPS #2, 2 = complain
long long dist [3][10010];

void dijkstra(int id, int start){
    fill(dist[id], dist[id]+10010, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0ll, start));
    while(pq.size() > 0){
        pair<int, int> now = pq.top(); pq.pop();
        if(dist[id][now.second] < INF) continue;
        dist[id][now.second] = now.first;
        for(pair<int, long long> edge : adjacency[id][now.second])
            if(dist[id][edge.first] == INF)
                pq.push(make_pair(now.first+edge.second, edge.first));
    }
}

int main(){
    freopen("gpsduel.in", "r", stdin); freopen("gpsduel.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; long long c, d; cin >> a >> b >> c >> d;
        adjacency[0][b].push_back(make_pair(a, c));
        adjacency[1][b].push_back(make_pair(a, d));
    }
    dijkstra(0, N); dijkstra(1, N);
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < adjacency[0][i].size(); j++){
            int nexty = adjacency[0][i][j].first, len = 0;
            if(dist[0][nexty]-dist[0][i] != adjacency[0][i][j].second) len++;
            if(dist[1][nexty]-dist[1][i] != adjacency[1][i][j].second) len++;
            adjacency[2][nexty].push_back(make_pair(i, len));
        }
    dijkstra(2, 1);
    cout << dist[2][N] << '\n';
    return 0;
}
