#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef long long ll;

int N, M, K, Q, counter = 0, total = 0, hubs [201];
vector<pair<int, ll>> adjacency [20001], rev [20001];
ll cost = 0, hubToOther [201][20001], otherToHub [20001][201];
bool isHub [20001], visited [20001];

int main(){
    freopen("vacationgold.in", "r", stdin); freopen("vacationgold.out", "w", stdout);
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    for(int i = 0; i < M; i++){
        int a, b; ll c; scanf("%d %d %lld", &a, &b, &c);
        adjacency[a].push_back(make_pair(b, c));
        rev[b].push_back(make_pair(a, c));
    }
    for(int i = 1; i <= K; i++){
        int hu; scanf("%d", &hu);
        isHub[hu] = true; hubs[i] = hu;
    }
    memset(hubToOther, -1, sizeof(hubToOther)); memset(otherToHub, -1, sizeof(otherToHub));
    for(int i = 1; i <= K; i++){
        memset(visited, false, sizeof(visited));
        int start = hubs[i]; priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push(make_pair(0ll, start));
        while(pq.size() > 0){
            pair<ll, int> now = pq.top(); pq.pop();
            if(visited[now.second]) continue;
            visited[now.second] = true; hubToOther[i][now.second] = now.first;
            for(int x = 0; x < adjacency[now.second].size(); x++){
                int next = adjacency[now.second][x].first;
                if(visited[next]) continue;
                pq.push(make_pair(now.first+adjacency[now.second][x].second, next));
            }
        }
        memset(visited, false, sizeof(visited));
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq2;
        pq2.push(make_pair(0ll, start));
        while(pq2.size() > 0){
            pair<ll, int> now = pq2.top(); pq2.pop();
            if(visited[now.second]) continue;
            visited[now.second] = true; otherToHub[now.second][i] = now.first;
            for(int x = 0; x < rev[now.second].size(); x++){
                int next = rev[now.second][x].first;
                if(visited[next]) continue;
                pq2.push(make_pair(now.first+rev[now.second][x].second, next));
            }
        }
    }
    for(int i = 0; i < Q; i++){
        int a, b; scanf("%d %d", &a, &b);
        ll add = 1ll<<55;
        for(int j = 1; j <= K; j++)
            if(otherToHub[a][j] != -1 && hubToOther[j][b] != -1)
                add = min(add, otherToHub[a][j]+hubToOther[j][b]);
        if(add != 1ll<<55){ counter++; cost += add; }
    }
    cout << counter << '\n' << cost << '\n';
    return 0;
}
