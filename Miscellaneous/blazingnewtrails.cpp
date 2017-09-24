#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <string.h>

using namespace std;

int n, m, k, w, parents [200010], heights [200010];
bool isSpecial [200010];
long long ret, lowerBound = 0ll, upperBound = 0ll, low = -200500ll, high = 200500ll, originalCost [500010];
pair<int, int> endpoints [500010];
vector<pair<long long, int>> normalEdges, specialEdges;

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
    cin >> n >> m >> k >> w;
    memset(isSpecial, false, sizeof(isSpecial));
    for(int i = 0; i < k; i++){
        int temp; cin >> temp;
        isSpecial[temp] = true;
    }
    for(int i = 0; i < m; i++){
        int a, b; long long c; cin >> a >> b >> c; c *= 2ll;
        endpoints[i] = make_pair(a, b); originalCost[i] = c;
        if(isSpecial[a] == isSpecial[b]) normalEdges.push_back(make_pair(c, i));
        else specialEdges.push_back(make_pair(c, i));
    }
    sort(normalEdges.begin(), normalEdges.end()); sort(specialEdges.begin(), specialEdges.end());
    while(low <= high){
        long long mid = (low+high)/2ll;
        for(int i = 1; i <= n; i++){ parents[i] = i; heights[i] = 0; }
        for(int i = 0; i < specialEdges.size(); i++) specialEdges[i].first = originalCost[specialEdges[i].second]+mid;
        vector<pair<long long, int>> all;
        merge(specialEdges.begin(), specialEdges.end(), normalEdges.begin(), normalEdges.end(), back_inserter(all));
        long long cost = 0ll; int totEd = 0; int spEd = 0;
        for(int i = 0; i < all.size(); i++){
            int id = all[i].second, from = endpoints[id].first, to = endpoints[id].second;
            bool ok = combine(from, to);
            if(!ok) continue;
            cost += originalCost[id]; totEd++;
            if(isSpecial[from] != isSpecial[to]) spEd++;
            if(totEd == n-1) break;
        }
        if(totEd < n-1){ cout << "-1\n"; return 0; }
        if(spEd < w){
            upperBound = (cost>>1)+(mid>>1)*(spEd-w);
            high = mid-1;
        }
        else if(spEd > w) {
            lowerBound = (cost>>1)+(mid>>1)*(spEd-w);
            low = mid+1;
        }
        else{ lowerBound = upperBound = cost/2ll; break; }
    }
    if(lowerBound == 0ll || upperBound == 0ll) ret = -1ll;
    else ret = upperBound;
    cout << ret << '\n';
    return 0;
}
