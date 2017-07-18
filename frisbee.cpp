#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

int n, m, colors [2001], c1 = 0, c2 = 0, singles = 0, curSize, visited [2001];
vector<int> adjacency [2001], considering;

void bfs(int curr){
    if(visited[curr]) return;
    visited[curr] = true; curSize++;
    considering.push_back(curr);
    for(int i = 0; i < adjacency[curr].size(); i++)
        if(!visited[adjacency[curr][i]])
            bfs(adjacency[curr][i]);
}

bool isColorable(int curr){
    if(curr == curSize) return true;
    for(int color = 0; color < 2; color++){
        bool possible = true;
        for(int j : adjacency[considering[curr]])
            if(colors[j] == color){ possible = false; break; }
        if(possible){
            colors[considering[curr]] = color;
            bool b = isColorable(curr+1);
            if(b) return true;
            colors[considering[curr]] = -1;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    memset(colors, -1, sizeof(colors)); memset(visited, false, sizeof(visited));
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        curSize = 0; considering.clear(); bfs(i);
        if(curSize == 1){ singles++; continue; }
        if(!isColorable(0)){ flag = false; break; }
    }
    if(!flag) cout << "Impossible\n";
    else{
        for(int i = 1; i <= n; i++){
            if(colors[i] == 0) c1++;
            else c2++;
        }
        if(c1 > c2) swap(c1, c2);
        if(c1+singles <= c2) c1 += singles;
        else{
            c1 = c2;
            singles -= c2-c1;
            c1 += singles/2; c2 += singles/2;
            if(singles%2 == 1) c2++;
        }
        cout << c1 << " " << c2 << '\n';
    }
    return 0;
}
