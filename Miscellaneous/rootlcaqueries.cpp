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
#define INF 5000000000000000000
#define MOD 1000000007

int N, Q, curID = 0, depths [100010], subtreeSizes [100010], parents [20][100010], id [100010], mx [100010];
vector<int> adjacency [100010];

void dfs(int curr, int prevy, int d){
    depths[curr] = d; subtreeSizes[curr] = 1; parents[0][curr] = prevy;
    id[curr] = curID; mx[curr] = id[curr]; curID++;
    for(int i : adjacency[curr]){
        if(i == prevy) continue;
        dfs(i, curr, d+1); subtreeSizes[curr] += subtreeSizes[i];
    }
    mx[curr] = curID;
}

void buildIt(){
    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= N; j++)
            parents[i][j] = parents[i-1][parents[i-1][j]];
}

int moveIt(int from, int to){ //finds lowest depth point that can be reached starting at "from" without going through "to"
    if(!(id[to] < id[from] && mx[to] >= mx[from])) return parents[0][to];
    for(int i = 19; i > -1; i--)
        if(depths[parents[i][from]] > depths[to])
            from = parents[i][from];
    return from;
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> Q;
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    dfs(1, 1, 0); buildIt();
    for(int i = 0; i < Q; i++){
        int a, b, c; cin >> a >> b >> c;
        a = moveIt(a, c); b = moveIt(b, c);
        if(a == b){ cout << "0\n"; continue; }
        int ret = N;
        if(a == parents[0][c]) ret -= N-subtreeSizes[c];
        else ret -= subtreeSizes[a];
        if(b == parents[0][c]) ret -= N-subtreeSizes[c];
        else ret -= subtreeSizes[b];
        cout << ret << '\n';
    }
    return 0;
}
