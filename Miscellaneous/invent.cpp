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

int kase, N, parents [15010], heights [15010];
pair<long long, pair<int, int>> edges [15010];
long long ret, compSizes [15010];

int findParent(int x){
    if(x == parents[x]) return x;
    parents[x] = findParent(parents[x]);
    return parents[x];
}

bool combine(int x, int y){
    int a = findParent(x); int b = findParent(y);
    if(a == b) return false;
    if(heights[b] < heights[a]){
        parents[b] = a;
        compSizes[a] += compSizes[b];
    }
    else if(heights[a] < heights[b]){
        parents[a] = b;
        compSizes[b] += compSizes[a];
    }
    else{
        parents[b] = a; heights[a]++;
        compSizes[a] += compSizes[b];
    }
    return true;
}

int main(){
    //freopen("odometer.in", "r", stdin); freopen("odometer.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; ret = 0ll;
        for(int i = 0; i < N-1; i++){
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
            ret += edges[i].first;
        }
        for(int i = 1; i <= N; i++){ parents[i] = i; heights[i] = 1; compSizes[i] = 1ll; }
        sort(edges, edges+N-1);
        for(int i = 0; i < N-1; i++){
            int x = findParent(edges[i].second.first), y = findParent(edges[i].second.second);
            if(x == y) continue;
            ret += (compSizes[x]*compSizes[y]-1ll)*(edges[i].first+1ll);
            combine(x, y);
        }
        cout << ret << '\n';
    }
    return 0;
}
