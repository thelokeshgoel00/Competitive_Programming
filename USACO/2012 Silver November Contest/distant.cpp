#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;


struct Point{
    int row, col, dist;
    Point(int i, int j, int d): row(i), col(j), dist(d) {}
    bool operator<(Point const &other) const{ return dist > other.dist; }
};

int N, A, B, ret = 0, dx [] = {1, -1, 0, 0}, dy [] = {0, 0, 1, -1};
char grid [30][30];
bool visited [30][30];

bool inBounds(int r, int c){ return r > -1 && c > -1 && r < N && c < N; }

void go(int x, int y){
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            visited[i][j] = false;
    priority_queue<Point> pq; pq.push(Point(x, y, 0));
    while(pq.size() > 0){
        Point p = pq.top(); pq.pop();
        if(visited[p.row][p.col]) continue;
        visited[p.row][p.col] = true;
        ret = max(ret, p.dist);
        for(int i = 0; i < 4; i++){
            int nr = p.row+dx[i]; int nc = p.col+dy[i];
            if(inBounds(nr, nc) && !visited[nr][nc])
                pq.push(Point(nr, nc, p.dist+(grid[p.row][p.col] == grid[nr][nc] ? A : B)));
        }
    }
}

int main(){
    freopen("distant.in", "r", stdin); freopen("distant.out", "w", stdout);
    scanf("%d %d %d", &N, &A, &B);
    for(int i = 0; i < N; i++) scanf("%s", &grid[i]);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            go(i, j);
        }
    cout << ret << endl;
    return 0;
}
