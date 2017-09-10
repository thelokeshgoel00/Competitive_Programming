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

int N, P, parents [10010], heights [10010];
long long talkTimes [10010], ret = 1010ll;
pair<long long, pair<int, int>> edges [100010];

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
    //freopen("grassplant.in", "r", stdin); freopen("grassplant.out", "w", stdout);
    scanf("%d %d", &N, &P);
    for(int i = 1; i <= N; i++){
        scanf("%lld", &talkTimes[i]);
        ret = min(ret, talkTimes[i]);
        parents[i] = i; heights[i] = 1;
    }
    for(int i = 0; i < P; i++){
        int a, b; long long c; scanf("%d %d %lld", &a, &b, &c);
        edges[i] = make_pair(talkTimes[a]+talkTimes[b]+2*c, make_pair(a, b));
    }
    sort(edges, edges+P);
    for(int i = 0, numEdges = 0; numEdges < N-1; i++){
        if(!combine(edges[i].second.first, edges[i].second.second)) continue;
        ret += edges[i].first; numEdges++;
    }
    cout << ret << '\n';
    return 0;
}
