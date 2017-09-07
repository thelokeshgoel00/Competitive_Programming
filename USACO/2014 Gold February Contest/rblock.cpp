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

int N, M, firstPrev [300], firstShort, maxPrev [300], maxShort, curEdgeEnd, adjIndex [300][300];
vector<pair<int, int>> adjacency [300];
priority_queue<pair<int, pair<int, int>>> pq;

int main(){
    freopen("rblock.in", "r", stdin); freopen("rblock.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int x, y, z; scanf("%d %d %d", &x, &y, &z);
        adjacency[x].push_back(make_pair(y, z)); adjIndex[x][y] = adjacency[x].size()-1;
        adjacency[y].push_back(make_pair(x, z)); adjIndex[y][x] = adjacency[y].size()-1;
    }
    memset(firstPrev, -1, sizeof(firstPrev)); pq.push(make_pair(0, make_pair(1, 0)));
    while(pq.size() > 0){
        pair<int, pair<int, int>> now = pq.top(); pq.pop();
        if(firstPrev[now.second.first] != -1) continue;
        firstPrev[now.second.first] = now.second.second;
        if(now.second.first == N){
            firstShort = -now.first; maxShort = firstShort;
            pq = priority_queue<pair<int, pair<int, int>>>(); break;
        }
        for(pair<int, int> e : adjacency[now.second.first])
            if(firstPrev[e.first] == -1)
                pq.push(make_pair(now.first-e.second, make_pair(e.first, now.second.first)));
    }
    //cout << firstShort << endl;
    curEdgeEnd = N;
    while(curEdgeEnd != 1){
        int x = firstPrev[curEdgeEnd], y = curEdgeEnd; memset(maxPrev, -1, sizeof(maxPrev));
        adjacency[x][adjIndex[x][y]].second *= 2; adjacency[y][adjIndex[y][x]].second *= 2;
        pq.push(make_pair(0, make_pair(1, 0)));
        while(pq.size() > 0){
            pair<int, pair<int, int>> now = pq.top(); pq.pop();
            if(maxPrev[now.second.first] != -1) continue;
            maxPrev[now.second.first] = now.second.second;
            if(now.second.first == N){
                maxShort = max(maxShort, -now.first);
                pq = priority_queue<pair<int, pair<int, int>>>(); break;
            }
            for(pair<int, int> e : adjacency[now.second.first])
                if(maxPrev[e.first] == -1)
                    pq.push(make_pair(now.first-e.second, make_pair(e.first, now.second.first)));
        }
        adjacency[x][adjIndex[x][y]].second /= 2; adjacency[y][adjIndex[y][x]].second /= 2;
        curEdgeEnd = x;
    }
    printf("%d\n", maxShort-firstShort);
    return 0;
}
