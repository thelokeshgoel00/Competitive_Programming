#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, M, sccID = 0, tiempo = 0;
int values [500010], disc [500010], low [500010], sccNum [500010], sccWeight [500010];
vector<int> oriAdjacency [500010], sccNodes [500010], sccAdjacency [500010];
bool inStack [500010];
stack<int> componente;
pair<int, int> dp [500010][2], ret;

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

pair<int, int> recurse(int curr, int prevTaken){
    if(dp[curr][prevTaken] != make_pair(-1, -1)) return dp[curr][prevTaken];
    if(curr == sccNum[N]){
        if(prevTaken == 0) return dp[curr][prevTaken] = {sccWeight[curr], 1+(sccWeight[curr] == 0 ? 1 : 0)};
        return dp[curr][prevTaken] = {0, 1};
    }
    if(sccAdjacency[curr].size() == 0) return dp[curr][prevTaken] = {-2, -2};
    pair<int, int> takeThis = {sccWeight[curr], 0}, leaveThis = {0, 0};
    bool isDead = true;
    for(int next : sccAdjacency[curr]){
        pair<int, int> tempLeave = recurse(next, 0);
        if(tempLeave != make_pair(-2, -2)) isDead = false;
        if(tempLeave.first > leaveThis.first) leaveThis = tempLeave;
        else if(tempLeave.first == leaveThis.first) leaveThis.second = (leaveThis.second+tempLeave.second)%MOD;
        if(prevTaken == 1) continue;
        pair<int, int> tempTake = recurse(next, 1); tempTake.first += sccWeight[curr];
        if(tempTake.first > takeThis.first) takeThis = tempTake;
        else if(tempTake.first == takeThis.first) takeThis.second = (takeThis.second+tempTake.second)%MOD;
    }
    if(isDead) return dp[curr][prevTaken] = {-2, -2};
    pair<int, int> kek = {max(takeThis.first, leaveThis.first), 0};
    if(takeThis.first == kek.first) kek.second = (kek.second+takeThis.second)%MOD;
    if(leaveThis.first == kek.first) kek.second = (kek.second+leaveThis.second)%MOD;
    return dp[curr][prevTaken] = kek;
}

int main(){
    //freopen("grass.in", "r", stdin); freopen("grass.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) scanf("%d", &values[i]);
    memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low)); memset(sccNum, -1, sizeof(inStack));
    memset(inStack, false, sizeof(inStack));
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        oriAdjacency[a].push_back(b);
    }
    for(int i = 1; i <= N; i++)
        if(disc[i] == -1)
            findSCC(i);
    for(int k = 0; k < sccID; k++){
        sccWeight[k] = 0;
        dp[k][0] = {-1, -1}; dp[k][1] = {-1, -1};
        for(int i : sccNodes[k]){
            sccWeight[k] += values[i];
            for(int j : oriAdjacency[i])
                if(sccNum[i] != sccNum[j])
                    sccAdjacency[sccNum[i]].push_back(sccNum[j]);
        }
    }
    ret = recurse(sccNum[1], 0);
    cout << ret.first << " " << ret.second << '\n';
    return 0;
}
