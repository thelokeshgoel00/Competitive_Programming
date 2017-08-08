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
int disc [100010], low [100010], sccNum [100010], sccWeight [100010], dp [100010][2];
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

int recurse(int now, int goal, int isRev){
    if(dp[now][isRev] != -1) return dp[now][isRev];
    if(now == goal) return 0;
    dp[now][isRev] = -2;
    if(isRev == 0){
        for(int i = 0; i < sccAdjacency[now].size(); i++){
            int temp = recurse(sccAdjacency[now][i], goal, isRev);
            if(temp > -1) dp[now][isRev] = max(dp[now][isRev], sccWeight[now]+temp);
        }
    }
    else{
        for(int i = 0; i < reverses[now].size(); i++){
            int temp = recurse(reverses[now][i], goal, isRev);
            if(temp > -1) dp[now][isRev] = max(dp[now][isRev], sccWeight[now]+temp);
        }
    }
    return dp[now][isRev];
}

int main(){
    freopen("grass.in", "r", stdin); freopen("grass.out", "w", stdout);
    cin >> numFields >> numPaths;
    memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low)); memset(sccNum, -1, sizeof(inStack));
    memset(inStack, false, sizeof(inStack)); memset(dp, -1, sizeof(dp));
    for(int i = 0; i < numPaths; i++){
        int a, b; cin >> a >> b;
        oriAdjacency[a].push_back(b);
    }
    for(int i = 1; i <= numFields; i++)
        if(disc[i] == -1)
            findSCC(i);
    for(int k = 0; k < sccID; k++){
        sccWeight[k] = sccNodes[k].size();
        for(int i : sccNodes[k]){
            for(int j : oriAdjacency[i]){
                if(sccNum[i] == sccNum[j]) continue;
                sccAdjacency[sccNum[i]].push_back(sccNum[j]);
                reverses[sccNum[j]].push_back(sccNum[i]);
            }
        }
    }
    ret = sccWeight[sccNum[1]];
    for(int i = 0; i < sccID; i++){
        int x = recurse(i, sccNum[1], 0); //path from i to sccNum[1]
        if(x < 0) continue;
        for(int j : sccAdjacency[i]){
            int y = recurse(j, sccNum[1], 1); //path from sccNum[1] to j
            if(y > -1) ret = max(ret, x+y+sccWeight[sccNum[1]]);
        }
    }
    cout << ret << '\n';
    return 0;
}
