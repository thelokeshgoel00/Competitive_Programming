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
#include <bitset>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, minX = 1010, maxX = 0, maxHeight = 0, rowSpan [1010], dx [] = {1, -1, 0, 0}, dy [] = {0, 0, 1, -1}, ret;
pair<pair<int, int>, int> buildings [10010];
char filler [1010][1010], grid [1010][1010];
bool visited [1010][1010];
queue<pair<int, int>> q;

bool inBounds(int x, int y){ return x > 0 && y > -1 && x < maxHeight+6 && y < maxX+6; }

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(filler, '.', sizeof(filler)); memset(filler[0], '*', sizeof(filler[0]));
    memset(grid, '.', sizeof(grid)); memset(grid[0], '*', sizeof(grid[0])); memset(rowSpan, 0, sizeof(rowSpan));
    for(int i = 0; i < N; i++){
        cin >> buildings[i].first.first >> buildings[i].first.second >> buildings[i].second;
        minX = min(minX, buildings[i].first.first); maxHeight = max(maxHeight, buildings[i].second);
    }
    for(int i = 0; i < N; i++){
        buildings[i].first.first -= minX; buildings[i].first.second -= minX;
        maxX = max(maxX, buildings[i].first.second);
        for(int j = buildings[i].first.first; j < buildings[i].first.second; j++)
            rowSpan[j] = max(rowSpan[j], buildings[i].second);
    }
    for(int j = 0; j < maxX; j++)
        for(int i = 1; i <= rowSpan[j]; i++)
            filler[i][j] = grid[i][j] = '#';
    for(int j = 1; j < maxX; j++)
        for(int i = 1; i <= maxHeight; i++){
            bool boxed = true;
            for(int a = -1; a < 2; a++)
                for(int b = -1; b < 2; b++)
                    if(filler[i+a][j+b] == '.')
                        boxed = false;
            if(boxed) grid[i][j] = '.';
        }
    q.push(make_pair(maxHeight+5, maxX+5)); memset(visited, false, sizeof(visited));
    ret = rowSpan[0];
    while(q.size() > 0){
        pair<int, int> p = q.front(); q.pop();
        if(visited[p.first][p.second]) continue;
        visited[p.first][p.second] = true;
        for(int i = 0; i < 4; i++){
            int nr = p.first+dx[i]; int nc = p.second+dy[i];
            if(!inBounds(nr, nc)) continue;
            if(grid[nr][nc] == '#') ret++;
            else if(!visited[nr][nc]) q.push(make_pair(nr, nc));
        }
    }
    cout << ret << '\n';
    for(int i = maxHeight; i > -1; i--){
        for(int j = 0; j < maxX; j++) cout << grid[i][j];
        cout << '\n';
    }
    return 0;
}
