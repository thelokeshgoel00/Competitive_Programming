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

int numJunctions, junctionDepth [100001], junctionPos [100001], parents [100001];
vector<int> atDepth [100001], children [100001];

void dfs(int now, int depth){
    sort(children[now].begin(), children[now].end());
    for(int i = 0; i < children[now].size(); i++){
        int next = children[now][i];
        junctionDepth[next] = junctionDepth[parents[next]]+1;
        junctionPos[next] = atDepth[junctionDepth[next]].size();
        atDepth[junctionDepth[next]].push_back(next);
        dfs(next, depth+1);
    }
}

int main(){
    scanf("%d", &numJunctions); junctionDepth[1] = 0; atDepth[0].push_back(1); junctionPos[1] = 0;
    for(int i = 2; i <= numJunctions; i++){
        int parent; scanf("%d", &parent);
        children[parent].push_back(i);
        parents[i] = parent;
    }
    dfs(1, 0);
    for(int i = 1; i <= numJunctions; i++){
        int depth = junctionDepth[i]; int pos = junctionPos[i];
        if(pos == 0) cout << "-1";
        else cout << atDepth[depth][pos-1];
        if(i == numJunctions) cout << '\n';
        else cout << " ";
    }
    for(int i = 1; i <= numJunctions; i++){
        int depth = junctionDepth[i]; int pos = junctionPos[i];
        if(pos == atDepth[depth].size()-1) cout << "-1";
        else cout << atDepth[depth][pos+1];
        if(i == numJunctions) cout << '\n';
        else cout << " ";
    }
    return 0;
}
