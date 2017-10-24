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

int rows, cols, dx [] = {0, 1, 0, -1}, dy [] = {1, 0, -1, 0}, grid [20][20];
bool isFinish [20][20];
map<pair<int, pair<int, int>>, int> energyNeeded;
priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>,
        greater<pair<pair<int, int>, pair<int, int>>>> pq;

// State: ((maxEnergy, curEnergy), (row, col))

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < rows && y < cols; }

int main(){
    //freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> rows >> cols; rows += 2;
    for(int i = 0; i < cols; i++){
        string s; cin >> s;
        grid[0][i] = 0;
        isFinish[0][i] = true;
    }
    for(int i = 1; i < rows-1; i++)
        for(int j = 0; j < cols; j++){
            cin >> grid[i][j];
            isFinish[i][j] = false;
        }
    for(int i = 0; i < cols; i++){
        string s; cin >> s;
        grid[rows-1][i] = 0;
        isFinish[rows-1][i] = false;
    }
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            if(inBounds(i+1, j) && grid[i][j]+grid[i+1][j] < 0)
                isFinish[i][j] = isFinish[i+1][j] = true;
            if(inBounds(i, j+1) && grid[i][j]+grid[i][j+1] < 0)
                isFinish[i][j] = isFinish[i][j+1] = true;
        }
    energyNeeded[make_pair(0, make_pair(rows-1, 0))] = 0;
    pq.push(make_pair(make_pair(0, 0), make_pair(rows-1, 0)));
    while(pq.size() > 0){
        pair<pair<int, int>, pair<int, int>> now = pq.top(); pq.pop();
        if(isFinish[now.second.first][now.second.second]){
            cout << now.first.first << '\n';
            break;
        }
        for(int i = 0; i < 4; i++){
            int nr = now.second.first+dx[i], nc = now.second.second+dy[i];
            if(!inBounds(nr, nc)) continue;
            int nextCurEnergy = now.first.second-grid[nr][nc];
            int nextMaxEnergy = max(now.first.first, -nextCurEnergy);
            pair<int, pair<int, int>> mapState = make_pair(nextCurEnergy, make_pair(nr, nc));
            if(energyNeeded.find(mapState) == energyNeeded.end() || energyNeeded[mapState] > nextMaxEnergy){
                energyNeeded[mapState] = nextMaxEnergy;
                pq.push(make_pair(make_pair(nextMaxEnergy, nextCurEnergy), make_pair(nr, nc)));
            }
        }
    }
    return 0;
}
