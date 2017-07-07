#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string.h>

using namespace std;

int d, c, ret = 0;
vector<int> adjacency [1005];
bool visited [1005];
unordered_set<int> possible;

void bfs(int curr){
    if(visited[curr]) return;
    visited[curr] = true;
    for(int next : adjacency[curr])
        if(!visited[next])
            bfs(next);
}

int main(){
    //freopen("shufflegold.in","r",stdin); freopen("shufflegold.out","w",stdout);
    scanf("%d %d", &d, &c);
    for(int i = 0; i < c; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(b); adjacency[b].push_back(a);
        possible.insert(a); possible.insert(b);
    }
    for(int i = 1; i <= d; i++){
        if(visited[i] || possible.find(i) == possible.end()) continue;
        ret++; bfs(i);
    }
    cout << ret << '\n';
    return 0;
}
