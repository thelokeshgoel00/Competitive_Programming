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
    int rows, cols, best = -1, dx [] = {1, -1, 0, 0}, dy [] = {0, 0, 1, -1}; scanf("%d %d", &rows, &cols); char grid [510][510];
    bool marked [510][510]; memset(marked, false, sizeof(marked));
    for(int i = 0; i < rows; i++) scanf("%s", &grid[i]);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    while(pq.size() > 0){
        pair<int, pair<int, int>> now = pq.top(); pq.pop();
        int row = now.second.first; int col = now.second.second;
        if(row == rows-1 && col == cols-1){ best = now.first; break; }
        if(marked[row][col]) continue;
        marked[row][col] = true;
        for(int i = 0; i < 4; i++){
            int nr = row+(grid[row][col]-'0')*dx[i]; int nc = col+(grid[row][col]-'0')*dy[i];
            if(nr <= -1 || nr >= rows || nc <= -1 || nc >= cols) continue;
            if(marked[nr][nc]) continue;
            pq.push(make_pair(now.first+1, make_pair(nr, nc)));
        }
    }
    cout << best << '\n';
    return 0;
}
