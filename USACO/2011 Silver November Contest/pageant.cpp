#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

class Point{
    public:
        int row;
        int col;
        int dist;
        Point(int r, int c): row(r), col(c) {}
};

int rows, cols, index = 0, dx [] = {0, 0, 1, -1}, dy [] = {1, -1, 0, 0}, spot12 = 10000, spot13 = 10000, spot23 = 10000, ret = 100000;
char grid [50][50];
bool visited [50][50];
vector <Point> spots [3];

bool inBounds(int r, int c){ return r > -1 && c > -1 && r < rows && c < cols; }

void markSpot(int r, int c){
    queue <Point> bfs; Point start(r, c); bfs.push(start);
    while(bfs.size() > 0){
        Point p = bfs.front(); bfs.pop();
        if(visited[p.row][p.col]) continue;
        visited[p.row][p.col] = true;
        spots[index].push_back(p);
        for(int i = 0; i < 4; i++){
            int nr = dx[i]+p.row, nc = dy[i]+p.col;
            if(inBounds(nr, nc) && !visited[nr][nc] && grid[nr][nc] == 'X'){
                Point next(nr, nc); bfs.push(next);
            }
        }
    }
    index++;
}

int main(){
    freopen("pageant.in", "r", stdin); freout("pageant.out", "w", stdout);
    scanf("%d %d", &rows, &cols);
    for(int i = 0; i < rows; i++) scanf("%s", &grid[i]);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(grid[i][j] == 'X' && !visited[i][j])
                markSpot(i, j);
    //cout << spots[0].size() << " " << spots[1].size() << " " << spots[2].size() << endl;
    for(int i = 0; i < spots[0].size(); i++)
        for(int j = 0; j < spots[1].size(); j++)
            spot12 = min(spot12, abs(spots[0][i].row-spots[1][j].row)+abs(spots[0][i].col-spots[1][j].col));
    for(int i = 0; i < spots[0].size(); i++)
        for(int j = 0; j < spots[2].size(); j++)
            spot13 = min(spot13, abs(spots[0][i].row-spots[2][j].row)+abs(spots[0][i].col-spots[2][j].col));
    for(int i = 0; i < spots[1].size(); i++)
        for(int j = 0; j < spots[2].size(); j++)
            spot23 = min(spot23, abs(spots[1][i].row-spots[2][j].row)+abs(spots[1][i].col-spots[2][j].col));
    ret = min(spot12+spot13, min(spot12+spot23, spot13+spot23))-2;
    //cout << spot12 << " " << spot13 << " " << spot23 << endl;
    //cout << ret << endl;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 'X') continue;
            for(int a = 0; a < spots[0].size(); a++)
                for(int b = 0; b < spots[1].size(); b++)
                    for(int c = 0; c < spots[2].size(); c++){
                        ret = min(ret, abs(spots[0][a].row-i)+abs(spots[0][a].col-j)
                                  +abs(spots[1][b].row-i)+abs(spots[1][b].col-j)+abs(spots[2][c].row-i)+abs(spots[2][c].col-j)-2);
                    }
        }
    cout << ret << endl;
    return 0;
}
