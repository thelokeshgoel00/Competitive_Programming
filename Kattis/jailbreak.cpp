#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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

int kase, rows, cols, dx [] = {0, 1, 0, -1}, dy [] = {1, 0, -1, 0}, dist [3][120][120], ret;
char grid [120][120];
pair<int, int> starters [3];
deque<pair<int, int>> dq;

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < rows+2 && y < cols+2; }

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> kase; starters[0] = make_pair(0, 0);
    for(int kk = 1; kk <= kase; kk++){
        cin >> rows >> cols; ret = 100010;
        for(int i = 0; i < rows+2; i++)
            for(int j = 0; j < cols+2; j++){
                grid[i][j] = '.';
                for(int k = 0; k < 3; k++) dist[k][i][j] = 100010;
            }
        starters[1] = make_pair(-1, -1); starters[2] = make_pair(-1, -1);
        for(int i = 1; i <= rows; i++){
            string s; cin >> s;
            for(int j = 1; j <= cols; j++){
                grid[i][j] = s[j-1];
                if(grid[i][j] == '$'){
                    if(starters[1].first == -1) starters[1] = make_pair(i, j);
                    else starters[2] = make_pair(i, j);
                }
            }
        }
        for(int k = 0; k < 3; k++){
            dist[k][starters[k].first][starters[k].second] = 0;
            dq.push_back(make_pair(starters[k].first, starters[k].second));
            while(dq.size() > 0){
                pair<int, int> now = dq.front(); dq.pop_front();
                for(int i = 0; i < 4; i++){
                    pair<int, int> nexty = make_pair(now.first+dx[i], now.second+dy[i]);
                    if(!inBounds(nexty.first, nexty.second) || grid[nexty.first][nexty.second] == '*') continue;
                    int edgeWeight = grid[nexty.first][nexty.second] == '#';
                    if(dist[k][now.first][now.second]+edgeWeight >= dist[k][nexty.first][nexty.second]) continue;
                    dist[k][nexty.first][nexty.second] = dist[k][now.first][now.second]+edgeWeight;
                    if(edgeWeight == 1) dq.push_back(nexty);
                    else dq.push_front(nexty);
                }
            }
        }
        for(int i = 0; i < rows+2; i++)
            for(int j = 0; j < cols+2; j++){
                int tot = dist[0][i][j]+dist[1][i][j]+dist[2][i][j]; if(grid[i][j] == '#') tot -= 2;
                ret = min(ret, tot);
            }
        cout << ret << '\n';
    }
    return 0;
}
