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
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

struct Edge{
    int id;
    long long x1, y1, x2, y2;
    Edge(){ x1 = y1 = x2 = y2 = -1ll; id = -1; }
    bool operator<(Edge const &other) const{
        if (x2 < other.x2) return (y2 - other.y1)*(other.x2 - other.x1) < (other.y2 - other.y1)*(x2 - other.x1);
        return (other.y2 - y1)*(x2 - x1) > (y2 - y1)*(other.x2 - x1);
    }
};

struct Event{
    int edgeID;
    long long x, y;
    Event(){ x = y = -1; edgeID = -1; }
    bool operator<(Event const &other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int N, curEdge = 0, ret = 1;
Edge edges [100010];
Event events [200010];
set<Edge> stuff;

int main(){
    freopen("hillwalk.in", "r", stdin); freopen("hillwalk.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        edges[i].id = i;
        scanf("%lld %lld %lld %lld", &edges[i].x1, &edges[i].y1, &edges[i].x2, &edges[i].y2);
        events[2*i].edgeID = i; events[2*i].x = edges[i].x1; events[2*i].y = edges[i].y1;
		events[2*i+1].edgeID = i; events[2*i+1].x = edges[i].x2; events[2*i+1].y = edges[i].y2;
    }
    sort(events, events+2*N);
    stuff.insert(edges[0]);
    for(int i = 1; i < 2*N; i++){
        Event now = events[i];
        Edge ed = edges[now.edgeID];
        if(now.x == ed.x1){ stuff.insert(ed); continue; }
        if(now.edgeID != curEdge){ stuff.erase(ed); continue; }
        auto ita = stuff.find(ed);
        if(ita == stuff.begin()) continue;
        auto itb = ita; itb--;
        curEdge = itb->id; stuff.erase(ita);
        ret++;
    }
    cout << ret << '\n';
    return 0;
}
