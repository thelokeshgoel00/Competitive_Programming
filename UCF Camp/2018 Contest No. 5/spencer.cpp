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
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int R, C, dx [] = {-1, 0, 1, 0}, dy [] = {0, 1, 0, -1};
char grid [60][60];
priority_queue<pair<int, pair<int, int>>> pq;
bool visited [60][60][4];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < R && y < C; }

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> R >> C; memset(visited, false, sizeof(visited));
    for(int i = 0; i < R; i++){
        cin >> grid[i];
        for(int j = 0; j < C; j++){
            if(grid[i][j] == 'X' || grid[i][j] == '_') continue;
            if(grid[i][j] == 'N') pq.push(mp(0, mp(C*i+j, 0)));
            if(grid[i][j] == 'E') pq.push(mp(0, mp(C*i+j, 1)));
            if(grid[i][j] == 'S') pq.push(mp(0, mp(C*i+j, 2)));
            if(grid[i][j] == 'W') pq.push(mp(0, mp(C*i+j, 3)));
        }
    }
    while(pq.size() > 0){
        pair<int, pair<int, int>> now = pq.top(); pq.pop();
        int r = now.s.f/C, c = now.s.f%C, dir = now.s.s;
        if(r == 0 || r == R-1 || c == 0 || c == C-1){
            cout << -now.f << '\n';
            return 0;
        }
        if(visited[r][c][dir]) continue;
        visited[r][c][dir] = true;
        int nr = r+dx[dir], nc = c+dy[dir];
        if(inBounds(nr, nc) && grid[nr][nc] != 'X' && !visited[nr][nc][dir]) pq.push(mp(now.f, mp(C*nr+nc, dir)));
        if(!visited[r][c][(dir+1)%4]) pq.push(mp(now.f-1, mp(now.s.f, (dir+1)%4)));
        if(!visited[r][c][(dir+3)%4]) pq.push(mp(now.f-1, mp(now.s.f, (dir+3)%4)));
    }
    cout << "-1\n";
    return 0;
}
