#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

int rows, cols, dx [] = {1, -1, 0, 0}, dy [] = {0, 0, 1, -1}, ret = 0;
bool grid [1010][1010], visited [1010][1010];
queue<pair<int, int>> q;

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < rows+2 && y < cols+2; }

int main(){
    cin >> rows >> cols;
    memset(grid, false, sizeof(grid)); memset(visited, false, sizeof(visited));
    for(int i = 1; i <= rows; i++){
        string s; cin >> s;
        for(int j = 1; j <= cols; j++) grid[i][j] = s[j-1] == '1';
    }
    q.push(make_pair(0, 0));
    while(q.size() > 0){
        pair<int, int> p = q.front(); q.pop();
        if(visited[p.first][p.second]) continue;
        visited[p.first][p.second] = true;
        for(int i = 0; i < 4; i++){
            int nr = p.first+dx[i]; int nc = p.second+dy[i];
            if(!inBounds(nr, nc)) continue;
            if(grid[nr][nc]) ret++;
            else if(!visited[nr][nc]) q.push(make_pair(nr, nc));
        }
    }
    cout << ret << '\n';
    return 0;
}
