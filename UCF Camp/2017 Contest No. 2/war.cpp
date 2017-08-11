#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

int parents [1000], heights [1000], degree [1000];

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
    int s, e, maxDeg = 0; bool good = true; cin >> s >> e;
    for(int i = 0; i < 1000; i++){ parents[i] = i; heights[i] = 1; degree[i] = 0; }
    for(int i = 0; i < e; i++){
        int v1, v2; cin >> v1 >> v2;
        combine(v1, v2+s); combine(v1+s, v2);
        if(findParent(v1) == findParent(v2)){ good = false; break; }
        degree[v1]++; degree[v2]++;
        maxDeg = max(maxDeg, max(degree[v1], degree[v2]));
    }
    if(good && maxDeg < s-1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
