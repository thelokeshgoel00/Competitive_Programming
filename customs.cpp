#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

#define MOD 1000000007

int n, m, parents [20010], discoveryTime [20010], lowest [20010], time = 0;
pair<int, int> edges [100010]; //first = from, second = to
vector<pair<int, int>> adjacency [20010]; //first = ID, second = to
stack<int> curGroup;
vector<vector<int>> components;

void popIt(int edgy){
    vector<int> temp;
    while(curGroup.size() > 0 && edgy != curGroup.top()){ temp.push_back(curGroup.top()); curGroup.pop(); }
    if(curGroup.size() > 0) temp.push_back(curGroup.top()); curGroup.pop();
    if(temp.size() > 0) components.push_back(temp);
}

void findBCC(int curr, bool isRoot){
    discoveryTime[curr] = time; lowest[curr] = time; time++;
    int numChildren = 0;
    for(int k = 0; k < adjacency[curr].size(); k++){
        int next = adjacency[curr][k].second;
        if(discoveryTime[next] == -1){
            numChildren++; parents[next] = curr;
            curGroup.push(adjacency[curr][k].first);
            findBCC(next, false);
            lowest[curr] = min(lowest[curr], lowest[next]);
            if((isRoot && numChildren > 1) || (!isRoot && lowest[next] >= discoveryTime[curr]))
                popIt(adjacency[curr][k].first);
        }
        else if(next != parents[curr] && discoveryTime[next] < lowest[curr]){
            lowest[curr] = discoveryTime[next];
            curGroup.push(adjacency[curr][k].first);
        }
    }
}

bool isLoop(vector<int> stuff){
    if(stuff.size() < 4) return true;
    set<int> nodes;
    for(int i = 0; i < stuff.size(); i++){ nodes.insert(edges[stuff[i]].first); nodes.insert(edges[stuff[i]].second); }
    return stuff.size() == nodes.size();
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(make_pair(i, b)); adjacency[b].push_back(make_pair(i, a));
        edges[i] = make_pair(a, b);
    }
    int numMarked = 0; bool marked [20010]; memset(marked, false, sizeof(marked)); queue<int> q; q.push(1);
    while(q.size() > 0){
        int now = q.front(); q.pop();
        if(marked[now]) continue;
        marked[now] = true; numMarked++;
        if(numMarked == n) break;
        for(int i = 0; i < adjacency[now].size(); i++)
            if(!marked[adjacency[now][i].second])
                q.push(adjacency[now][i].second);
    }
    if(numMarked < n){ cout << "safe\n"; return 0; }
    memset(discoveryTime, -1, sizeof(discoveryTime)); memset(lowest, -1, sizeof(lowest)); memset(parents, -1, sizeof(parents));
    for(int i = 1; i <= n; i++){
        if(discoveryTime[i] != -1) continue;
        findBCC(i, true);
        popIt(-1);
    }
    bool flag = true; long long prod = 1ll;
    for(int i = 0; i < components.size(); i++){
        prod = (prod*(long long)components[i].size())%MOD;
        if(!isLoop(components[i])){ flag = false; break; }
    }
    if(!flag){ cout << "safe\n"; return 0; }
    cout << prod << '\n';
    return 0;
}
