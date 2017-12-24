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

int N, M, Q, dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1};
int disc [1510][1510], low [1510][1510], tiempo, compID;
pair<int, int> A, B, parents [1510][1510];
char grid [1510][1510];
bool possible [1510][1510][4], starts [1510][1510];
queue<pair<int, int>> qqq;
stack<pair<pair<int, int>, pair<int, int>>> componente;
map<pair<pair<int, int>, pair<int, int>>, int> adjacency [1510][1510];
queue<pair<pair<int, int>, int>> q;

void findBCC(int r, int c){
    disc[r][c] = low[r][c] = tiempo++;
    int numChildren = 0; pair<int, int> curr = make_pair(r, c);
    for(int i = 0; i < 4; i++){
        int nr = r+dx[i], nc = c+dy[i]; pair<int, int> nexty = make_pair(nr, nc);
        if(grid[nr][nc] == '#' || nexty == parents[r][c]) continue;
        if(disc[nr][nc] == -1){
            parents[nr][nc] = make_pair(r, c); componente.push(make_pair(curr, nexty)); findBCC(nr, nc);
            low[r][c] = min(low[r][c], low[nr][nc]); numChildren++;
            if((disc[r][c] == 0 && numChildren > 1) || (disc[r][c] > 0 && low[nr][nc] >= disc[r][c])){
                while(componente.top() != make_pair(curr, nexty)){
                    adjacency[componente.top().first.first][componente.top().first.second][componente.top()] = compID;
                    adjacency[componente.top().second.first][componente.top().second.second][componente.top()] = compID;
                    componente.pop();
                }
                adjacency[componente.top().first.first][componente.top().first.second][componente.top()] = compID;
                adjacency[componente.top().second.first][componente.top().second.second][componente.top()] = compID;
                componente.pop(); compID++;
            }
        }
        else if(disc[nr][nc] < disc[r][c]){
            low[r][c] = min(low[r][c], disc[nr][nc]);
            componente.push(make_pair(curr, nexty));
        }
    }
}

int main(){
    freopen("pushabox.in", "r", stdin); freopen("pushabox.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M >> Q; memset(possible, false, sizeof(possible)); memset(starts, false, sizeof(starts));
    memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low)); tiempo = 0; compID = 0;
    for(int i = 0; i < 1510; i++)
        for(int j = 0; j < 1510; j++)
            grid[i][j] = '#';
    for(int i = 1; i <= N; i++){
        string s; cin >> s;
        for(int j = 1; j <= M; j++){
            grid[i][j] = s[j-1];
            if(grid[i][j] == 'A'){ A = make_pair(i, j); grid[i][j] = '.'; }
            else if(grid[i][j] == 'B') B = make_pair(i, j);
        }
    }
    qqq.push(make_pair(A.first, A.second));
    while(qqq.size() > 0){
        pair<int, int> now = qqq.front(); qqq.pop();
        if(starts[now.first][now.second]) continue;
        starts[now.first][now.second] = true;
        for(int i = 0; i < 4; i++){
            int nx = now.first+dx[i], ny = now.second+dy[i];
            if(grid[nx][ny] == '#' || grid[nx][ny] == 'B' || starts[nx][ny]) continue;
            qqq.push(make_pair(nx, ny));
        }
    }
    grid[B.first][B.second] = '.';
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(disc[i][j] == -1 && grid[i][j] != '#'){
                findBCC(i, j);
                if(componente.size() == 0) continue;
                while(componente.size() > 0){
                    adjacency[componente.top().first.first][componente.top().first.second][componente.top()] = compID;
                    adjacency[componente.top().second.first][componente.top().second.second][componente.top()] = compID;
                    componente.pop();
                }
                compID++;
            }
    for(int i = 0; i < 4; i++){
        int nx = B.first-dx[i], ny = B.second-dy[i];
        if(starts[nx][ny]) q.push(make_pair(make_pair(B.first, B.second), i));
    }
    while(q.size() > 0){
        pair<pair<int, int>, int> now = q.front(); q.pop();
        if(possible[now.first.first][now.first.second][now.second]) continue;
        possible[now.first.first][now.first.second][now.second] = true;
        int nx = now.first.first+dx[now.second], ny = now.first.second+dy[now.second];
        if(grid[nx][ny] == '.') q.push(make_pair(make_pair(nx, ny), now.second));
        int cx = now.first.first-dx[now.second], cy = now.first.second-dy[now.second];
        int id1, id2;
        if(adjacency[now.first.first][now.first.second].find(make_pair(make_pair(cx, cy), now.first)) !=
              adjacency[now.first.first][now.first.second].end())
            id1 = adjacency[now.first.first][now.first.second][make_pair(make_pair(cx, cy), now.first)];
        else
            id1 = adjacency[now.first.first][now.first.second][make_pair(now.first, make_pair(cx, cy))];
        for(int i = 0; i < 4; i++){
            if(i == now.second) continue;
            nx = now.first.first-dx[i], ny = now.first.second-dy[i];
            if(grid[nx][ny] == '#') continue;
            if(adjacency[now.first.first][now.first.second].find(make_pair(make_pair(nx, ny), now.first)) !=
                  adjacency[now.first.first][now.first.second].end())
                id2 = adjacency[now.first.first][now.first.second][make_pair(make_pair(nx, ny), now.first)];
            else
                id2 = adjacency[now.first.first][now.first.second][make_pair(now.first, make_pair(nx, ny))];
            if(id1 != id2) continue;
            if(possible[now.first.first][now.first.second][i]) continue;
            q.push(make_pair(make_pair(now.first.first, now.first.second), i));
        }
    }
    for(int i = 0; i < Q; i++){
        int a, b; cin >> a >> b;
        if(possible[a][b][0] || possible[a][b][1] || possible[a][b][2] || possible[a][b][3] || (a == B.first && b == B.second)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
