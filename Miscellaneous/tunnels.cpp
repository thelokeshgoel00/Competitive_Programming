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

int N, T, edgeSum = 0, degree [200010], source = 1, dist [3][200010];
vector<pair<int, int>> adjacency [200010];

void processIt(){
    for(int i = 0; i < 3; i++){
        int farNode = source;
        queue<pair<int, int>> q; q.push(make_pair(0, source));
        while(q.size() > 0){
            pair<int, int> now = q.front(); q.pop();
            if(dist[i][now.second] != -1) continue;
            dist[i][now.second] = now.first;
            if(dist[i][now.second] > dist[i][farNode]) farNode = now.second;
            for(pair<int, int> edge : adjacency[now.second])
                if(dist[i][edge.first] == -1)
                    q.push(make_pair(now.first+edge.second, edge.first));
        }
        source = farNode;
    }
}

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> T; memset(degree, 0, sizeof(degree)); memset(dist, -1, sizeof(dist));
    for(int i = 0; i < N-1; i++){
        int a, b, c; cin >> a >> b >> c;
        adjacency[a].push_back(make_pair(b, c)); adjacency[b].push_back(make_pair(a, c));
        degree[a]++; degree[b]++; edgeSum += c;
    }
    processIt();
    for(int i = 1; i <= N; i++)
        if(degree[i] == T)
            cout << i << " " << edgeSum*2-max(dist[1][i], dist[2][i]) << '\n';
    return 0;
}
