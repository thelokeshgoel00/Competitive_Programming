#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int N, id = 0, seq [40000], from [80000], to [80000], dp [80000][2], ret = 0;
vector<int> adjacency [40000];
bool visited[40000][2];

int go(int e, int m){
    if(dp[e][m == 1] != -1) return dp[e][m == 1];
    int u = to[e];
    if(visited[u][m == 1]){
        int r = 0;
        for(int i = 0; i < adjacency[u].size(); i++){
            dp[adjacency[u][i]^1][m == 1] = max(r, dp[adjacency[u][i]^1][m == 1]);
            r = max(r, m*seq[u]+dp[adjacency[u][i]][m == 1]);
        }
        r = 0;
        for(int i = adjacency[u].size()-1; i > -1; i--){
            dp[adjacency[u][i]^1][m == 1] = max(r, dp[adjacency[u][i]^1][m == 1]);
            r = max(r, m*seq[u]+dp[adjacency[u][i]][m == 1]);
        }
        return dp[e][m == 1];
    }
    visited[u][m == 1] = true;
    int temp = max(0, m*seq[u]);
    for(int i = 0; i < adjacency[u].size(); i++){
        if(e == (adjacency[u][i]^1)) continue;
        temp = max(temp, m*seq[u]+go(adjacency[u][i], m));
    }
    return dp[e][m == 1] = temp;
}

int main(){
    freopen("btree.in", "r", stdin); freopen("btree.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 1; i < N; i++){
        int x; scanf("%d", &x); x--;
        from[id] = i;
        to[id] = x;
        adjacency[i].push_back(id++);
        from[id] = x;
        to[id] = i;
        adjacency[x].push_back(id++);
    }
    for(int i = 0; i < N; i++){
        char c [1]; scanf("%s", &c);
        if(c[0] == '(') seq[i] = 1;
        else seq[i] = -1;
        visited[i][0] = false; visited[i][1] = false;
        dp[2*i][0] = -1; dp[2*i][1] = -1;
        dp[2*i+1][0] = -1; dp[2*i+1][1] = -1;
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < adjacency[i].size(); j++){
            int lol = adjacency[i][j];
            ret = max(ret, min(go(lol, 1), go(lol^1, -1)));
        }
    cout << ret << endl;
    return 0;
}
