/*
ID: vamaddu1
PROG: schlnet
LANG: C++11
*/

//http://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/

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

int numSchools, sccID = 0, tiempo = 0, zeroIn = 0, zeroOut = 0;
int disc [101], low [101], superParent [101], inDegree [101], outDegree [101], sccNum [101];
vector<int> oriAdjacency [101], sccNodes [101], sccAdjacency [101];
bool inStack [101];
stack<int> componente;
set<int> starters;

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

void updateSP(int curr, int updateVal){
    superParent[curr] = updateVal;
    for(int i : sccAdjacency[curr]) updateSP(i, updateVal);
}

int main(){
    freopen("schlnet.in", "r", stdin); freopen("schlnet.out", "w", stdout);
    cin >> numSchools;
    memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low)); memset(sccNum, -1, sizeof(inStack));
    memset(inStack, false, sizeof(inStack)); memset(superParent, -1, sizeof(superParent));
    memset(inDegree, 0, sizeof(inDegree)); memset(outDegree, 0, sizeof(outDegree));
    for(int i = 1; i <= numSchools; i++){
        while(true){
            int x; cin >> x;
            if(x == 0) break;
            oriAdjacency[i].push_back(x);
        }
    }
    for(int i = 1; i <= numSchools; i++)
        if(disc[i] == -1)
            findSCC(i);
    for(int k = 0; k < sccID; k++)
        for(int i : sccNodes[k])
            for(int j : oriAdjacency[i]){
                if(sccNum[i] == sccNum[j]) continue;
                sccAdjacency[sccNum[i]].push_back(sccNum[j]);
                inDegree[sccNum[j]]++; outDegree[sccNum[i]]++;
            }
    for(int k = 0; k < sccID; k++){
        if(inDegree[k] == 0) zeroIn++;
        if(outDegree[k] == 0) zeroOut++;
        if(superParent[k] != -1) continue;
        updateSP(k, k);
    }
    for(int k = 0; k < sccID; k++) starters.insert(superParent[k]);
    if(sccID == 1) zeroIn = zeroOut = 0;
    cout << starters.size() << '\n' << max(zeroIn, zeroOut) << '\n';
    return 0;
}
