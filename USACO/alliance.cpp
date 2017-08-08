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

#define MOD 1000000007

int numFarms, numEdges;
long long ret = 1ll, degree [100010], sizeCounter, edgeCounter;
vector<int> adjacency [100010];
bool visited [100010];
queue<int> q;

int main(){
    freopen("alliance.in", "r", stdin); freopen("alliance.out", "w", stdout);
    cin >> numFarms >> numEdges;
    memset(degree, 0ll, sizeof(degree)); memset(visited, false, sizeof(visited));
    for(int i = 0; i < numEdges; i++){
        int a, b; cin >> a >> b; a--; b--;
        adjacency[a].push_back(b); degree[a]++;
        adjacency[b].push_back(a); degree[b]++;
    }
    for(int i = 0; i < numFarms; i++){
        if(visited[i]) continue;
        q.push(i); sizeCounter = 0ll; edgeCounter = 0ll;
        while(q.size() > 0){
            int now = q.front(); q.pop();
            if(visited[now]) continue;
            visited[now] = true; sizeCounter++; edgeCounter += degree[now];
            for(int next : adjacency[now])
                if(!visited[next])
                    q.push(next);
        }
        edgeCounter /= 2;
        if(sizeCounter-1ll == edgeCounter) ret = (ret*sizeCounter)%MOD;
        else if(sizeCounter == edgeCounter) ret = (ret*2ll)%MOD;
        else{ ret = 0ll; break; }
    }
    cout << ret << '\n';
    return 0;
}
