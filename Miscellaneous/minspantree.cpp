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
#include <sstream>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, M, parents [20010], heights [20010], totalWeight;
pair<int, pair<int, int>> edges [30010];
vector<pair<int, int>> mst;

int findParent(int x){
    if(x == parents[x]) return x;
    parents[x] = findParent(parents[x]);
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
    //freopen("greedy.in", "r", stdin); freopen("greedy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        for(int i = 0; i < N; i++){ parents[i] = i; heights[i] = 0; }
        for(int i = 0; i < M; i++){
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
            if(edges[i].second.first > edges[i].second.second) swap(edges[i].second.first, edges[i].second.second);
        }
        sort(edges, edges+M); totalWeight = 0; mst.clear();
        for(int i = 0; i < M; i++){
            bool ok = combine(edges[i].second.first, edges[i].second.second);
            if(!ok) continue;
            totalWeight += edges[i].first; mst.push_back(edges[i].second);
            if(mst.size() == N-1) break;
        }
        if(mst.size() == N-1){
            cout << totalWeight << '\n';
            sort(mst.begin(), mst.end());
            for(int i = 0; i < N-1; i++) cout << mst[i].first << " " << mst[i].second << '\n';
        }
        else cout << "Impossible\n";
    }
    return 0;
}
