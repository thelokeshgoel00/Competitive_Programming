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
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, M, sr, sc, dists [1010][1010];
char grid [1010][1010];
pair<int, int> prevy [1010][1010];
vector<pair<int, int>> adjacency [1010][1010];
queue<pair<int, int>> q;

void saveIt(){
    for(int i = 1; i < N-1; i++)
        for(int j = 1; j < M-1; j++)
            if(grid[i][j] != '#' && prevy[i][j] != make_pair(i, j))
                adjacency[prevy[i][j].first][prevy[i][j].second].push_back(make_pair(i, j));
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> M >> N; memset(dists, -1, sizeof(dists));
    for(int i = 0; i < N; i++){
        cin >> grid[i];
        for(int j = 0; j < M; j++)
            if(grid[i][j] == 'M'){
                grid[i][j] = '.';
                sr = i; sc = j;
            }
    }
    for(int i = 1; i < N-1; i++)
        for(int j = 1; j < M-1; j++){
            if(grid[i-1][j] == '#') prevy[i][j] = make_pair(i, j);
            else if(grid[i-1][j] == '.') prevy[i][j] = make_pair(i-1, j);
            else prevy[i][j] = prevy[i-1][j];
        }
    saveIt();
    for(int i = N-2; i > 0; i--)
        for(int j = 1; j < M-1; j++){
            if(grid[i+1][j] == '#') prevy[i][j] = make_pair(i, j);
            else if(grid[i+1][j] == '.') prevy[i][j] = make_pair(i+1, j);
            else prevy[i][j] = prevy[i+1][j];
        }
    saveIt();
    for(int i = 1; i < N-1; i++)
        for(int j = M-2; j > 0; j--){
            if(grid[i][j+1] == '#') prevy[i][j] = make_pair(i, j);
            else if(grid[i][j+1] == '.') prevy[i][j] = make_pair(i, j+1);
            else prevy[i][j] = prevy[i][j+1];
        }
    saveIt();
    for(int i = 1; i < N-1; i++)
        for(int j = 1; j < M-1; j++){
            if(grid[i][j-1] == '#') prevy[i][j] = make_pair(i, j);
            else if(grid[i][j-1] == '.') prevy[i][j] = make_pair(i, j-1);
            else prevy[i][j] = prevy[i][j-1];
        }
    saveIt();
    dists[sr][sc] = 0; q.push(make_pair(sr, sc));
    while(q.size() > 0){
        pair<int, int> now = q.front(); q.pop();
        for(pair<int, int> nexty : adjacency[now.first][now.second])
            if(dists[nexty.first][nexty.second] == -1){
                dists[nexty.first][nexty.second] = dists[now.first][now.second]+1;
                q.push(nexty);
            }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cout << dists[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
