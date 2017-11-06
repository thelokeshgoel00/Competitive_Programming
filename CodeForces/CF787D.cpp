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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, Q, S, id = 0, tos [10000010], prevs [10000010], lasts [10000010], weights [10000010];
long long dists [1000010];

void addEdge(int u, int v, int w){
    tos[id] = v; prevs[id] = lasts[u];
    weights[id] = w; lasts[u] = id;
    id++;
}

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R, int offset){
    for(int i = L; i <= R; i++){
        if(offset < 0) addEdge(p-offset, i, 0);
        else addEdge(i, p+offset, 0);
    }
    if(L >= R) return;
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2, offset); build(ri, (L+R)/2+1, R, offset);
}

void modify(int p, int L, int R, int l, int r, int s, int offset, int w){
    if(l <= L && r >= R){
        if(offset < 0) addEdge(s, p-offset, w); 
		    else addEdge(p+offset, s, w); 
  	    return; 
	  }
	  int li = left(p), ri = right(p);
	  if(l <= (L+R)/2) modify(li, L, (L+R)/2, l, r, s, offset, w); 
	  if((L+R)/2 < r) modify(ri, (L+R)/2+1, R, l, r, s, offset, w);
}

void dijkstra(){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dists, dists+1000010, INF); pq.push(make_pair(0, S)); dists[S] = 0;
    while(pq.size() > 0){
        int u = pq.top().second; long long d = pq.top().first; pq.pop();
    		if(dists[u] != d) continue;
        for(int i = lasts[u]; ~i; i = prevs[i])
            if(dists[tos[i]] > dists[u] + weights[i]){
                dists[tos[i]] = dists[u] + weights[i]; 
			          pq.push(make_pair(dists[tos[i]], tos[i])); 
            }
    }
}

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> Q >> S; S--; memset(lasts, -1, sizeof(lasts));
    build(1, 0, N-1, -N); build(1, 0, N-1, N+400005);
    for(int i = 0; i < Q; i++){
        int tp; cin >> tp;
        if(tp == 1){
            int u, v, w; cin >> u >> v >> w; u--; v--;
            addEdge(u, v, w);
        }
        else if(tp == 2){
            int u, l, r, w; cin >> u >> l >> r >> w; u--; l--; r--;
            modify(1, 0, N-1, l, r, u, -N, w);
        }
        else{
            int v, l, r, w; cin >> v >> l >> r >> w; v--; l--; r--;
            modify(1, 0, N-1, l, r, v, N+400005, w);
        }
    }
    dijkstra();
    for(int i = 0; i < N; i++){
        if(dists[i] == INF) cout << "-1 ";
        else cout << dists[i] << ' ';
    }
    return 0;
}
