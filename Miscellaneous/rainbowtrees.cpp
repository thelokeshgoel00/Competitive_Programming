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

int kase, N;
long long K, colorings [510][510];
vector<int> adjacency [510];

long long colorIt(int children, int degree){
    if(colorings[children][degree] != -1ll) return colorings[children][degree];
    colorings[children][degree] = 1ll;
    for(int i = 0; i < children; i++) colorings[children][degree] = (colorings[children][degree]*(long long)(K-degree-i))%(MOD+2ll);
    return colorings[children][degree];
}

long long solveIt(int curr, int prevy){
    int parentDegree = adjacency[prevy].size(), children = adjacency[curr].size()-1;
    if(prevy == 0) children++;
    long long ret = colorIt(children, parentDegree);
    for(int i : adjacency[curr])
        if(i != prevy)
            ret = (ret*solveIt(i, curr))%(MOD+2ll);
    return ret;
}

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N >> K; memset(colorings, -1ll, sizeof(colorings));
        for(int i = 1; i <= N; i++) adjacency[i].clear();
        for(int i = 0; i < N-1; i++){
            int a, b; cin >> a >> b;
            adjacency[a].push_back(b); adjacency[b].push_back(a);
        }
        cout << "Case #" << kk << ": " << solveIt(1, 0) << '\n';
    }
    return 0;
}
