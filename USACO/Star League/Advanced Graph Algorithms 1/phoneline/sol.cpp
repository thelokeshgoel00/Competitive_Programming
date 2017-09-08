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

int N, P, K, lo = 0, hi = 1000000, ret = 1000001;
vector<pair<int, int>> adjacency [1010];
bool visited [1010];

bool checkIt(int payLimit){
    memset(visited, false, sizeof(visited));
    priority_queue<pair<int, int>> pq; pq.push(make_pair(K, 1));
    while(pq.size() > 0){
        pair<int, int> now = pq.top(); pq.pop();
        if(now.second == N) return true;
        if(visited[now.second]) continue;
        visited[now.second] = true;
        for(pair<int, int> edge : adjacency[now.second]){
            pair<int, int> next = make_pair(now.first, edge.first);
            if(edge.second > payLimit) next.first--;
            if(next.first > -1) pq.push(next);
        }
    }
    return false;
}

int main(){
    //freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);
    scanf("%d %d %d", &N, &P, &K);
    for(int i = 0; i < P; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        adjacency[a].push_back(make_pair(b, c)); adjacency[b].push_back(make_pair(a, c));
    }
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(checkIt(mid)){
            ret = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    if(ret == 1000001) cout << "-1\n";
    else cout << ret << '\n';
    return 0;
}
