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

int numCows, numRopes, sccID = 0, tiempo = 0, ret = 0;
int disc [10010], low [10010], sccNum [10010];
vector<int> oriAdjacency [100010], sccNodes [10010], sccAdjacency [10010];
bool inStack [10010];
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
    cin >> numCows >> numRopes;
    memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low));
    memset(sccNum, -1, sizeof(inStack)); memset(inStack, false, sizeof(inStack));
    for(int i = 0; i < numRopes; i++){
        int a, b; cin >> a >> b;
        oriAdjacency[a].push_back(b);
    }
    for(int i = 1; i <= numCows; i++)
        if(disc[i] == -1)
            findSCC(i);
    for(int k = 0; k < sccID; k++)
        if(sccNodes[k].size() > 1)
            ret++;
    cout << ret << '\n';
    return 0;
}
