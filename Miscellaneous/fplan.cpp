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
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001

int kase, numLocations, numMoves, sccID, tiempo, ret;
int disc [100010], low [100010], inDegree [100010], sccNum [100010];
vector<int> oriAdjacency [100010], sccNodes [100010], sccAdjacency [100010];
bool inStack [100010];
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
        scanf("%d %d", &numLocations, &numMoves); sccID = 0; tiempo = 0; ret = -1;
        memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low)); memset(sccNum, -1, sizeof(inStack));
        memset(inStack, false, sizeof(inStack)); memset(inDegree, 0, sizeof(inDegree));
        for(int i = 0; i < 100010; i++){ oriAdjacency[i].clear(); sccNodes[i].clear(); sccAdjacency[i].clear(); }
        stack<int> blank;
        swap(componente, blank);
        for(int i = 1; i <= numMoves; i++){
            int x, y; scanf("%d %d", &x, &y); x++; y++;
            oriAdjacency[x].push_back(y);
        }
        for(int i = 1; i <= numLocations; i++)
            if(disc[i] == -1)
                findSCC(i);
        for(int k = 0; k < sccID; k++)
            for(int i : sccNodes[k])
                for(int j : oriAdjacency[i]){
                    if(sccNum[i] == sccNum[j]) continue;
                    sccAdjacency[sccNum[i]].push_back(sccNum[j]);
                    inDegree[sccNum[j]]++;
                }
        for(int k = 0; k < sccID; k++){
            if(inDegree[k] != 0) continue;
            if(ret > -1){ ret = -1; break; }
            else ret = k;
        }
        if(ret == -1) printf("Confused\n");
        else{
            sort(sccNodes[ret].begin(), sccNodes[ret].end());
            for(int i = 0; i < sccNodes[ret].size(); i++) printf("%d\n", sccNodes[ret][i]-1);
        }
        printf("\n");
    }
    return 0;
}
