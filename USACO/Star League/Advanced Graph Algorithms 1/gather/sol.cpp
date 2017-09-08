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

int N, parent [100010];
vector<pair<int, long long>> adjacency [100010];
long long subtreeSize [100010], curCost = 0ll, ret;

void rootIt(int curr, int prev, long long dist){
    parent[curr] = prev; curCost += dist*subtreeSize[curr];
    for(pair<int, long long> next : adjacency[curr]){
        if(next.first == prev) continue;
        rootIt(next.first, curr, dist+next.second);
        subtreeSize[curr] += subtreeSize[next.first];
    }
}

void recurse(int curr, int prev, long long distSum){
    ret = min(ret, distSum);
    for(pair<int, long long> next : adjacency[curr]){
        if(next.first == prev) continue;
        recurse(next.first, curr, distSum+next.second*(subtreeSize[1]-2*subtreeSize[next.first]));
    }
}

int main(){
    //freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%lld", &subtreeSize[i]);
    for(int i = 1; i < N; i++){
        int a, b; long long c; scanf("%d %d %lld", &a, &b, &c);
        adjacency[a].push_back(make_pair(b, c)); adjacency[b].push_back(make_pair(a, c));
    }
    rootIt(1, -1, 0); ret = curCost; recurse(1, -1, curCost);
    cout << ret << '\n';
    return 0;
}
