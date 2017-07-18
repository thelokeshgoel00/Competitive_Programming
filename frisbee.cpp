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

int n, m, colors [2001], c1, c2, curSize, visited [2001];
vector<int> adjacency [2001], considering, groups;

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
        if(curSize == 1){ groups.push_back(1); continue; }
        if(!isColorable(0)){ flag = false; break; }
        c1 = 0; c2 = 0;
        for(int i = 0; i < considering.size(); i++){
            if(colors[considering[i]] == 0) c1++;
            else c2++;
        }
        groups.push_back(c1); groups.push_back(c2);
    }
    if(!flag) cout << "Impossible\n";
    else{
        bool dp [n+1][n+1]; memset(dp, false, sizeof(dp)); dp[0][0] = true;
        for(int i = 1; i <= groups.size(); i++)
            for(int j = 0; j <= n; j++){
                dp[i][j] = dp[i-1][j];
                if(groups[i-1] <= j) dp[i][j] = dp[i][j] || dp[i-1][j-groups[i-1]];
            }
        int diff = 5000;
        for (int j = n/2; j > -1; j--)
            if (dp[groups.size()][j] == true){
                diff = n-2*j;
                break;
            }
        for(int i = 0; i < groups.size(); i++) cout << groups[i] << " ";
        cout << endl;
        cout << n-(diff+n)/2 << " " << (diff+n)/2 << '\n';
    }
    return 0;
}
