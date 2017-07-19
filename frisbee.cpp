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

int isColorable(int curr, int prevColor){
    bool possible = true; int color = 0, ret = 1;
    if(prevColor == 0) color = 1;
    colors[curr] = color;
    for(int j : adjacency[curr]){
        if(colors[j] == color) return 0;
        else if(colors[j] == -1) ret += isColorable(j, color);
    }
    return ret;
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
        if(isColorable(considering[0], -1) != considering.size()){ flag = false; break; }
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
