#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int main(){
    int rows, cols, counter = 0, dx [] = {1, -1, 0, 0}, dy [] = {0, 0, 1, -1}; scanf("%d %d", &rows, &cols); char grid [60][60];
    bool marked [60][60]; memset(marked, false, sizeof(marked));
    for(int i = 0; i < rows; i++) scanf("%s", &grid[i]);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            if(grid[i][j] != 'w' || marked[i][j]) continue;
            queue<int> q; q.push(i); q.push(j);
            while(q.size() > 0){
                int r = q.front(); q.pop(); int c = q.front(); q.pop();
                if(marked[r][c]) continue;
                marked[r][c] = true;
                for(int i = 0; i < 4; i++){
                    int nr = r+dx[i]; int nc = c+dy[i];
                    if(nr <= -1 || nr >= rows || nc <= -1 || nc >= cols) continue;
                    if(marked[nr][nc] || grid[nr][nc] != 'w') continue;
                    q.push(nr); q.push(nc);
                }
            }
            counter++;
        }
    cout << counter << '\n';
    return 0;
}
