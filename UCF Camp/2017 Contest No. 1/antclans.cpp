#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

#define INF 1000000000

int n, m, k, ret, msts [1<<20], dp [1<<20], adjacency [20][20];

void generateMST(){
    for(int mask = 0; mask < (1<<n); mask++){
        if(__builtin_popcount(mask) != n/k) continue;
        vector<int> places; bool visited [n/k]; memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; i++)
            if((mask&(1<<i)) > 0)
                places.push_back(i);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> temp;
        int numEdges = 0; int sum = 0;
        for(int i = 1; i < n/k; i++)
            if(adjacency[places[0]][places[i]] != -1)
                temp.push(make_pair(adjacency[places[0]][places[i]], make_pair(0, i)));
        while(numEdges < n/k-1 && temp.size() > 0){
            pair<int, pair<int, int>> now = temp.top(); temp.pop();
            if(visited[now.second.first] && visited[now.second.second]) continue;
            if(!visited[now.second.first]){
                int curr = now.second.first; visited[now.second.first] = true;
                for(int i = 0; i < n/k; i++)
                    if(!visited[i] && adjacency[places[curr]][places[i]] != -1)
                        temp.push(make_pair(adjacency[places[curr]][places[i]], make_pair(curr, i)));
            }
            if(!visited[now.second.second]){
                int curr = now.second.second; visited[now.second.second] = true;
                for(int i = 0; i < n/k; i++)
                    if(!visited[i] && adjacency[places[curr]][places[i]] != -1)
                        temp.push(make_pair(adjacency[places[curr]][places[i]], make_pair(curr, i)));
            }
            numEdges++; sum += now.first;
        }
        if(numEdges < n/k-1) msts[mask] = INF;
        else msts[mask] = sum;
        dp[mask] = msts[mask];
    }
}

int hob(int x){
    if(x == 0) return 0;
    int num = 1;
    while(x >>= 1) num <<= 1;
    return num;
}

int solve(int mask){
    if(dp[mask] != -1) return dp[mask];
    dp[mask] = INF; int hi = hob(mask);
    for(int cmask = mask; cmask > 0; cmask = ((cmask-1)&mask)){
        if((hi&cmask) == 0) break;
        if(__builtin_popcount(cmask) != n/k || msts[cmask] == INF) continue;
        dp[mask] = min(dp[mask], solve(mask^cmask)+msts[cmask]);
    }
    return dp[mask];
}


int main(){
    scanf("%d %d %d", &n, &m, &k);
    memset(adjacency, -1, sizeof(adjacency)); memset(dp, -1, sizeof(dp));
    for(int i = 0; i < m; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
        adjacency[a][b] = c; adjacency[b][a] = c;
    }
    if(n%k != 0){ cout << "-1\n"; return 0; }
    if(n == k){ cout << "0\n"; return 0; }
    generateMST();
    ret = solve((1<<n)-1);
    if(ret == INF) ret = -1;
    cout << ret << '\n';
    //for(int i = 0; i < (1<<n); i++) cout << i << " " << dp[i] << '\n';
    return 0;
}
