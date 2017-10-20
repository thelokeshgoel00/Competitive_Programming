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

int N, M, visited [510][510][2]; //0 is initial gravity, 1 is inverted gravity
string grid [510];
pair<int, int> C, D;
deque<pair<pair<int, int>, pair<int, int>>> dq;

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < N && y < M; }

pair<int, int> fallIt(pair<int, int> now, int direction){
    if(!inBounds(now.first, now.second) || grid[now.first][now.second] == '#') return make_pair(-1, -1);
    while(true){
        if(grid[now.first][now.second] == 'D') break;
        if(!inBounds(now.first+direction, now.second)) return make_pair(-1, -1);
        if(grid[now.first+direction][now.second] == '#') break;
        now.first += direction;
    }
    return now;
}

int main(){
    freopen("gravity.in", "r", stdin); freopen("gravity.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> grid[i];
        for(int j = 0; j < M; j++){
            if(grid[i][j] == 'C'){ C.first = i; C.second = j; }
            else if(grid[i][j] == 'D'){ D.first = i; D.second = j; }
            visited[i][j][0] = visited[i][j][1] = 1000000000;
        }
    }
    C = fallIt(C, 1);
    if(C.first != -1){ dq.push_back(make_pair(make_pair(0, 0), C)); visited[C.first][C.second][0] = 0; }
    while(dq.size() > 0){
        pair<pair<int, int>, pair<int, int>> now = dq.front(); dq.pop_front();
        pair<int, int> moveLeft = make_pair(now.second.first, now.second.second-1);
        if(now.first.second == 0) moveLeft = fallIt(moveLeft, 1);
        else moveLeft = fallIt(moveLeft, -1);
        if(moveLeft.first != -1 && now.first.first < visited[moveLeft.first][moveLeft.second][now.first.second]){
            dq.push_front(make_pair(now.first, moveLeft));
            visited[moveLeft.first][moveLeft.second][now.first.second] = now.first.first;
        }
        pair<int, int> moveRight = make_pair(now.second.first, now.second.second+1);
        if(now.first.second == 0) moveRight = fallIt(moveRight, 1);
        else moveRight = fallIt(moveRight, -1);
        if(moveRight.first != -1 && now.first.first < visited[moveRight.first][moveRight.second][now.first.second]){
            dq.push_front(make_pair(now.first, moveRight));
            visited[moveRight.first][moveRight.second][now.first.second] = now.first.first;
        }
        pair<int, int> invert = make_pair(now.second.first, now.second.second);
        if(now.first.second == 0) invert = fallIt(invert, -1);
        else invert = fallIt(invert, 1);
        if(invert.first != -1 && now.first.first+1 < visited[invert.first][invert.second][1-now.first.second]){
            dq.push_back(make_pair(make_pair(now.first.first+1, 1-now.first.second), invert));
            visited[invert.first][invert.second][1-now.first.second] = now.first.first+1;
        }
    }
    if(min(visited[D.first][D.second][0], visited[D.first][D.second][1]) == 1000000000) cout << "-1\n";
    else cout << min(visited[D.first][D.second][0], visited[D.first][D.second][1]) << '\n';
    return 0;
}
