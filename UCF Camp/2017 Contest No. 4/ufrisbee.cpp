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

int n, m, colors [200010], c1, c2, curSize, visited [200010], lesserCount = 0;
vector<int> adjacency [200010], considering, groups, reduced;

void bfs(int curr){
    /*if(visited[curr]) return;
    visited[curr] = true; curSize++;
    considering.push_back(curr);
    for(int i = 0; i < adjacency[curr].size(); i++)
        if(!visited[adjacency[curr][i]])
            bfs(adjacency[curr][i]);*/
    queue<int> q; q.push(curr);
    while(q.size() > 0){
        int now = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true; curSize++;
        considering.push_back(now);
        for(int i = 0; i < adjacency[now].size(); i++)
            if(!visited[adjacency[now][i]])
                q.push(adjacency[now][i]);
    }
}

int isColorable(int curr, int prevColor){
    /*int color = 0, ret = 1;
    if(prevColor == 0) color = 1;
    colors[curr] = color;
    for(int j : adjacency[curr]){
        if(colors[j] == color) return 0;
        else if(colors[j] == -1) ret += isColorable(j, color);
    }*/
    queue<pair<int, int>> q; q.push(make_pair(curr, prevColor));
    while(q.size() > 0){
        pair<int, int> now = q.front(); q.pop();
        int color = 0;
        if(now.second == 0) color = 1;
        colors[now.first] = color;
        for(int j : adjacency[now.first]){
            if(colors[j] == color) return 0;
            else if(colors[j] == -1) q.push(make_pair(j, color));
        }
    }
    return curSize;
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
        if(isColorable(considering[0], -1) != curSize){ flag = false; break; }
        c1 = 0; c2 = 0;
        for(int i = 0; i < considering.size(); i++){
            if(colors[considering[i]] == 0) c1++;
            else c2++;
        }
        lesserCount += min(c1, c2); groups.push_back(max(c1, c2)-min(c1, c2));
    }
    if(!flag) cout << "Impossible\n";
    else{
        int freq [200010]; memset(freq, 0, sizeof(freq)); for(int i : groups) freq[i]++;
        for(int i = 1; i < 200010; i++){
            if(freq[i] == 0) continue;
            int numPairs = (freq[i]-1)/2;
            freq[2*i] += numPairs; freq[i] -= numPairs*2;
            for(int j = 0; j < freq[i]; j++) reduced.push_back(i);
        }
        groups = reduced;
        bool dp [n-2*lesserCount+1]; memset(dp, false, sizeof(dp)); dp[0] = true;
        for(int i = 1; i <= groups.size(); i++)
            for(int j = n-2*lesserCount; j >= groups[i-1]; j--)
                dp[j] = dp[j] || dp[j-groups[i-1]];
        int add = -1337;
        //for(int i = 0; i < 7; i++) cout << i << " " << dp[i] << endl;
        for(int j = n/2-lesserCount; j > -1; j--)
            if(dp[j] == true){
                add = j;
                break;
            }
        //for(int i = 0; i < groups.size(); i++) cout << "hi" << groups[i] << "\n";
        cout << lesserCount+add << " " << n-lesserCount-add << '\n';
    }
    return 0;
}
