/*
ID: vamaddu1
PROG: snail
LANG: C++11
*/

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

int len, numBlocks, dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1}, ret = 0, nr, nc;
bool grid [210][210], visited [210][210][4];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < len && y < len; }

void searchIt(int row, int col, int direction, int covered, char grid [210][210], bool visited [210][210]){
    visited[row][col] = true; ret = max(ret, covered);
    nr = row+dx[direction]; nc = col+dy[direction];
    if(inBounds(nr, nc) && grid[nr][nc] == '.'){
        if(!visited[nr][nc]) searchIt(nr, nc, direction, covered+1, grid, visited);
    }
    else{
        nr = row+dx[(direction+1)%4]; nc = col+dy[(direction+1)%4];
        if(inBounds(nr, nc) && !visited[nr][nc] && grid[nr][nc] == '.') searchIt(nr, nc, (direction+1)%4, covered+1, grid, visited);
        nr = row+dx[(direction+3)%4]; nc = col+dy[(direction+3)%4];
        if(inBounds(nr, nc) && !visited[nr][nc] && grid[nr][nc] == '.') searchIt(nr, nc, (direction+3)%4, covered+1, grid, visited);
    }
    visited[row][col] = false;
}

int main(){
    freopen("snail.in", "r", stdin); freopen("snail.out", "w", stdout);
    cin >> len >> numBlocks; char grid [210][210]; bool visited [210][210];
    memset(grid, '.', sizeof(grid)); memset(visited, false, sizeof(visited));
    for(int i = 0; i < numBlocks; i++){
        char s1 [3], s2 [2]; cin >> s1; s2[0] = s1[1]; s2[1] = s1[2];
        int x = atoi(s2)-1, y = s1[0]-'A';
        grid[x][y] = '@';
        //cout << x << " " << y << '\n';
    }
    searchIt(0, 0, 0, 1, grid, visited); searchIt(0, 0, 1, 1, grid, visited);
    cout << ret << '\n';
    return 0;
}
