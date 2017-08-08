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

int numFields, numPaths, sccID = 0, tiempo = 0, ret;
int disc [100010], low [100010], sccNum [100010], sccWeight [100010], visited [100010][2];
vector<int> oriAdjacency [100010], sccNodes [100010], sccAdjacency [100010], reverses [100010];
bool inStack [100010];
stack<int> componente;

void findSCC(int curr){
    disc[curr] = tiempo; low[curr] = tiempo; tiempo++;
    componente.push(curr); inStack[curr] = true;
    for(int i = 0; i < oriAdjacency[curr].size(); i++){
        int next = oriAdjacency[curr][i];
        if(disc[next] == -1){
            findSCC(next);
            low[curr] = min(low[curr], low[next]);
        }
        else if(inStack[next]) low[curr] = min(low[curr], disc[next]);
    }
    if(low[curr] == disc[curr]){
        int now = -1;
        while(componente.top() != curr){
            now = componente.top(); componente.pop();
            sccNodes[sccID].push_back(now);
            inStack[now] = false; sccNum[now] = sccID;
        }
        now = componente.top(); componente.pop();
        sccNodes[sccID].push_back(now);
        inStack[now] = false; sccNum[now] = sccID;
        sccID++;
    }
}

int main(){
    //freopen("grass.in", "r", stdin); freopen("grass.out", "w", stdout);
    cin >> numFields >> numPaths;
    memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low)); memset(sccNum, -1, sizeof(inStack));
    memset(inStack, false, sizeof(inStack)); memset(visited, -1, sizeof(visited));
    for(int i = 0; i < numPaths; i++){
        int a, b; cin >> a >> b;
        oriAdjacency[a].push_back(b);
    }
    for(int i = 1; i <= numFields; i++)
        if(disc[i] == -1)
            findSCC(i);
    for(int k = 0; k < sccID; k++){
        sccWeight[k] = sccNodes[k].size();
        for(int i : sccNodes[k])
            for(int j : oriAdjacency[i]){
                if(sccNum[i] == sccNum[j]) continue;
                sccAdjacency[sccNum[i]].push_back(sccNum[j]);
                reverses[sccNum[j]].push_back(sccNum[i]);
            }
    }
    ret = sccWeight[0];
    return 0;
}
