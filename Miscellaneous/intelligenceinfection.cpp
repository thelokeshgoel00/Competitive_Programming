#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
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
#include <deque>
#include <string.h>
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int S, E, C, sccID = 0, tiempo = 0, ret = 0;
int disc [50010], low [50010], inDegree [50010], sccNum [50010];
vector<int> ori [50010], sccNodes [50010], reverser [50010];
bool isEnemy [50010], inStack [50010], visited [50010], isDirty [50010];
stack<int> componente;

void findSCC(int curr){
    disc[curr] = tiempo; low[curr] = tiempo; tiempo++;
    componente.push(curr); inStack[curr] = true;
    for(int i = 0; i < ori[curr].size(); i++){
        int next = ori[curr][i];
        if(disc[next] == -1){
            findSCC(next);
            low[curr] = min(low[curr], low[next]);
        }
        else if(inStack[next]) low[curr] = min(low[curr], disc[next]);
    }
    if(low[curr] == disc[curr]){
        int now = -1, add = 0;
        while(componente.top() != curr){
            now = componente.top(); componente.pop();
            sccNodes[sccID].push_back(now);
            inStack[now] = false; sccNum[now] = sccID;
            if(isEnemy[now]) isDirty[sccID] = true;
            else add++;
        }
        now = componente.top(); componente.pop();
        sccNodes[sccID].push_back(now);
        inStack[now] = false; sccNum[now] = sccID;
        if(isEnemy[now]) isDirty[sccID] = true;
        else add++;
        if(isDirty[sccID]) ret += add;
        sccID++;
    }
}

void dfs(int curr){
    visited[curr] = true;
    if(!isDirty[curr]) ret += sccNodes[curr].size();
    for(int nexty : reverser[curr])
        if(!visited[nexty])
            dfs(nexty);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> S >> E >> C; memset(inDegree, 0, sizeof(inDegree));
    memset(disc, -1, sizeof(disc)); memset(low, -1, sizeof(low)); memset(sccNum, -1, sizeof(sccNum));
    for(int i = 0; i < C; i++){
        int a, b; cin >> a >> b;
        ori[a].push_back(b);
    }
    for(int i = 0; i < E; i++){
        int x; cin >> x;
        isEnemy[x] = true;
    }
    for(int i = 0; i < S; i++)
        if(disc[i] == -1)
            findSCC(i);
    for(int k = 0; k < sccID; k++)
        for(int i : sccNodes[k])
            for(int j : ori[i])
                if(sccNum[i] != sccNum[j])
                    reverser[sccNum[j]].push_back(sccNum[i]);
    for(int k = 0; k < sccID; k++)
        if(!visited[k] && isDirty[k])
            dfs(k);
    for(int k = 0; k < sccID; k++){
        if(visited[k]) continue;
        for(int i : sccNodes[k])
            for(int j : ori[i])
                if(sccNum[i] != sccNum[j] && !visited[sccNum[j]])
                    inDegree[sccNum[j]]++;
    }
    for(int k = 0; k < sccID; k++)
        if(!visited[k] && inDegree[k] == 0)
            ret++;
    cout << ret << '\n';
    return 0;
}
