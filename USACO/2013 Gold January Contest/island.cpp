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

int N = 0, rows, cols, dp [16][1<<16], adjacency [16][16], ret = 2500;
int dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1}, grid [60][60]; //100 is unmarked land, 200 is shallow water, -1 is deep water
vector<pair<int, int>> places [16];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < rows && y < cols; }

void markIt(int i, int j){
    queue<pair<int, int>> q; q.push(make_pair(i, j));
    while(q.size() > 0){
        pair<int, int> now = q.front(); q.pop();
        if(grid[now.first][now.second] != 100) continue;
        grid[now.first][now.second] = N; places[N].push_back(now);
        for(int i = 0; i < 4; i++){
            int nr = now.first+dx[i], nc = now.second+dy[i];
            if(inBounds(nr, nc) && grid[nr][nc] == 100) q.push(make_pair(nr, nc));
        }
    }
    N++;
}

int findDist(int i, int j){
    priority_queue<pair<int, pair<int, int>>> pq;
    bool visited [60][60]; memset(visited, false, sizeof(visited));
    for(pair<int, int> lol : places[i]) pq.push(make_pair(0, lol));
    while(pq.size() > 0){
        pair<int, pair<int, int>> now = pq.top(); pq.pop();
        if(grid[now.second.first][now.second.second] == j) return -now.first;
        if(visited[now.second.first][now.second.second]) continue;
        visited[now.second.first][now.second.second] = true;
        int shallow = now.first;
        if(grid[now.second.first][now.second.second] == 200) shallow--;
        for(int i = 0; i < 4; i++){
            int nr = now.second.first+dx[i], nc = now.second.second+dy[i];
            if(inBounds(nr, nc) && grid[nr][nc] != -1) pq.push(make_pair(shallow, make_pair(nr, nc)));
        }
    }
    return -1;
}

int recurse(int curr, int mask){
    if(dp[curr][mask] != -1) return dp[curr][mask];
    if(mask == ((1<<N)-1)) return 0;
    dp[curr][mask] = 2500;
    for(int i = 0; i < N; i++)
        if((mask&(1<<i)) == 0)
            dp[curr][mask] = min(dp[curr][mask], adjacency[curr][i]+recurse(i, mask|(1<<i)));
    return dp[curr][mask];
}

int main(){
    freopen("island.in", "r", stdin); freopen("island.out", "w", stdout);
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++){
        string s; cin >> s;
        for(int j = 0; j < cols; j++){
            if(s[j] == '.') grid[i][j] = -1;
            if(s[j] == 'X') grid[i][j] = 100;
            if(s[j] == 'S') grid[i][j] = 200;
        }
    }
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(grid[i][j] == 100)
                markIt(i, j);
    for(int i = 0; i < N; i++){
        adjacency[i][i] = 0;
        for(int j = i+1; j < N; j++)
            adjacency[i][j] = adjacency[j][i] = findDist(i, j);
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) ret = min(ret, recurse(i, 1<<i));
    cout << ret << '\n';
    return 0;
}
