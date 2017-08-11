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

int rows, cols, minAccess, parents [250010], heights [250010], compSizes [250010], dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1};
long long grid [510][510], difficulty [250010], ret = 0ll;
vector<pair<long long, pair<int, int>>> edges;
vector<int> inComp [250010];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < rows && y < cols; }

int findParent(int x){
    if(x == parents[x]) return x;
    parents[x] = findParent(parents[x]);
    return parents[x];
}

bool combine(int x, int y){
    int a = findParent(x); int b = findParent(y);
    if(a == b) return false;
    if(heights[b] < heights[a]){
        parents[b] = a; compSizes[a] += compSizes[b];
        for(int i : inComp[b]) inComp[a].push_back(i);
    }
    else if(heights[a] < heights[b]){
        parents[a] = b; compSizes[b] += compSizes[a];
        for(int i : inComp[a]) inComp[b].push_back(i);
    }
    else{
        parents[b] = a; heights[a]++; compSizes[a] += compSizes[b];
        for(int i : inComp[b]) inComp[a].push_back(i);
    }
    return true;
}

int main(){
    freopen("skilevel.in", "r", stdin); freopen("skilevel.out", "w", stdout);
    cin >> rows >> cols >> minAccess;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            cin >> grid[i][j];
            for(int k = 2; k < 4; k++){
                int nr = i+dx[k], nc = j+dy[k];
                if(inBounds(nr, nc)) edges.push_back(make_pair(abs(grid[i][j]-grid[nr][nc]), make_pair(nr*cols+nc, i*cols+j)));
            }
            parents[i*cols+j] = i*cols+j; heights[i*cols+j] = 0; compSizes[i*cols+j] = 1; difficulty[i*cols+j] = -1;
            inComp[i*cols+j].push_back(i*cols+j);
        }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i++){
        pair<long long, pair<int, int>> now = edges[i];
        int x = findParent(now.second.first), y = findParent(now.second.second);
        if(x == y) continue;
        if(compSizes[x]+compSizes[y] >= minAccess){
            if(compSizes[x] < minAccess)
                for(int j : inComp[x]) difficulty[j] = now.first;
            if(compSizes[y] < minAccess)
                for(int j : inComp[y]) difficulty[j] = now.first;
        }
        combine(x, y);
    }
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            int b; cin >> b;
            if(b == 0) continue;
            ret += difficulty[i*cols+j];
        }
    cout << ret << '\n';
    return 0;
}
