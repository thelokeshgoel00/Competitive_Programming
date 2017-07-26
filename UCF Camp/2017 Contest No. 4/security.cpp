#define __USE_MINGW_ANSI_STDIO 0
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

int kase, n, a, b, ret, used, id, rooms [200], parents [200], heights [200];
vector<pair<int, int>> endpoints, edges;

int findParent(int x){
    if(x == parents[x]) return x;
    parents[x] = findParent(parents[x]);
    heights[x] = 1;
    return parents[x];
}

bool combine(int x, int y){
    int a = findParent(x); int b = findParent(y);
    if(a == b) return false;
    if(heights[b] < heights[a]) parents[b] = a;
    else if(heights[a] < heights[b]) parents[a] = b;
    else{ parents[b] = a; heights[a]++; }
    return true;
}

int main(){
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> n >> a >> b; ret = 0, used = 0, id = 0;
        endpoints.clear(); edges.clear();
        for(int i = 0; i < n; i++){
            cin >> rooms[i]; int y = rooms[i]%100; int z = rooms[i]/100;
            parents[i] = i; heights[i] = 0;
            for(int j = 0; j < i; j++){
                int w = rooms[j]%100; int x = rooms[j]/100;
                endpoints.push_back(make_pair(i, j));
                edges.push_back(make_pair(a*abs(w-y)+b*abs(x-z), id++));
            }
        }
        sort(edges.begin(), edges.end());
        for(int i = 0; i < edges.size() && used < n-1; i++){
            int cur = edges[i].second, from = endpoints[cur].first, to = endpoints[cur].second;
            bool succ = combine(from, to);
            if(!succ) continue;
            ret += edges[i].first; used++;
        }
        cout << ret << '\n';
    }
}
