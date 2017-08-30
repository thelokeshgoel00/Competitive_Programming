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

#define PI 3.141592653589793
#define epsilon 0.000000001

int kase, numStatements, numProven, sccID, tiempo, zeroIn, zeroOut;
int disc [20010], low [20010], inDegree [20010], outDegree [20010], sccNum [20010];
vector<int> oriAdjacency [20010], sccNodes [20010], sccAdjacency [20010];
bool inStack [20010];
stack<int> componente;

void findSCC(int curr){
    disc[curr] = tiempo; low[curr] = tiempo; tiempo++;
    componente.push(curr);
    inStack[curr] = true;
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

int main() {
    scanf("%d", &kase);
    for(int kk = 1; kk <= kase; kk++){
        scanf("%d %d", &numStatements, &numProven); sccID = 0; tiempo = 0; zeroIn = 0; zeroOut = 0;
        memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low)); memset(sccNum, -1, sizeof(inStack));
        memset(inStack, false, sizeof(inStack)); memset(inDegree, 0, sizeof(inDegree)); memset(outDegree, 0, sizeof(outDegree));
        for(int i = 0; i < 20010; i++){ oriAdjacency[i].clear(); sccNodes[i].clear(); sccAdjacency[i].clear(); }
        stack<int> blank;
        swap(componente, blank);
        for(int i = 1; i <= numProven; i++){
            int x, y; scanf("%d %d", &x, &y);
            oriAdjacency[x].push_back(y);
        }
        for(int i = 1; i <= numStatements; i++)
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
        }
        if(sccID == 1) zeroIn = zeroOut = 0;
        printf("%d\n", max(zeroIn, zeroOut));
    }
    return 0;
}
