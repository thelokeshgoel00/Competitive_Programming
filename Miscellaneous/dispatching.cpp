#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

int N, hashes [100001], start = -1;
vector<int> adjacency [100001];
priority_queue<long long> peeps [100001];
long long M, level [100001], salary [100001], total [100001], ret = 0;

void clean(int curr){
    int id = hashes[curr];
    while(total[curr] > M && peeps[id].size() > 0){
        total[curr] -= peeps[id].top();
        peeps[id].pop();
    }
}

void combine(int a, int b){
    int x = hashes[a]; int y = hashes[b];
    total[b] += total[a];
    if(peeps[x].size() > peeps[y].size()){
        while(peeps[y].size() > 0){
            peeps[x].push(peeps[y].top());
            peeps[y].pop();
        }
        hashes[a] = y; hashes[b] = x;
    }
    else{
        while(peeps[x].size() > 0){
            peeps[y].push(peeps[x].top());
            peeps[x].pop();
        }
    }
    clean(b);
}

void dfs(int curr, int parent){
    peeps[hashes[curr]].push(salary[curr]); total[curr] = salary[curr];
    for(int i : adjacency[curr]) dfs(i, curr);
    clean(curr);
    ret = max(ret, (long long)(peeps[hashes[curr]].size())*level[curr]);
    combine(curr, parent);
}

int main(){
    scanf("%d %lld", &N, &M);
    for(int i = 1; i <= N; i++){
        int x; long long y, z; scanf("%d %lld %lld", &x, &y, &z);
        adjacency[x].push_back(i); salary[i] = y; level[i] = z;
        if(x == 0) start = i;
        hashes[i] = i;
    }
    dfs(start, 0);
    cout << ret << endl;
    return 0;
}
