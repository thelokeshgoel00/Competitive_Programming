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
#define INF 1000000000000
#define MOD 1000000007

int N, processOrder [100010], tree [100010], ret [100010];
vector<int> adjacency [100010];

void add(int pos, int x){
    while(pos < 100010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

void solveIt(int curr, int parent){
    ret[processOrder[curr]] = query(processOrder[curr]-1);
    add(processOrder[curr], 1);
    for(int next : adjacency[curr])
        if(next != parent)
            solveIt(next, curr);
    add(processOrder[curr], -1);
}

int main(){
    //freopen("grass.in", "r", stdin); freopen("grass.out", "w", stdout);
    scanf("%d", &N); memset(tree, 0ll, sizeof(tree));
    for(int i = 1; i < N; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        int x; scanf("%d", &x);
        processOrder[x] = i;
    }
    solveIt(1, 0);
    for(int i = 1; i <= N; i++) cout << ret[i] << '\n';
    return 0;
}
