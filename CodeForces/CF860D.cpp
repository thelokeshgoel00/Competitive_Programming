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

int N, M;
bool used [200010];
vector<int> adjacency [200010], edges [200010], x, y, z;

int dfs(int curr){
    int ret = -1;
    for(int i = 0; i < adjacency[curr].size(); i++){
        int nt = adjacency[curr][i], ni = edges[curr][i];
        if(used[ni]) continue;
        used[ni] = true; int nexty = dfs(nt);
        if(nexty != -1){ x.push_back(curr); y.push_back(nt); z.push_back(nexty); }
        else{
            if(ret == -1) ret = nt;
            else{ x.push_back(ret); y.push_back(curr); z.push_back(nt); ret = -1; }
        }
    }
    return ret;
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; memset(used, false, sizeof(used));
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        adjacency[a].push_back(b); adjacency[b].push_back(a);
        edges[a].push_back(i); edges[b].push_back(i);
    }
    for(int i = 1; i <= N; i++) dfs(i);
    cout << x.size() << '\n';
    for(int i = 0; i < x.size(); i++) cout << x[i] << " " << y[i] << " " << z[i] << '\n';
    return 0;
}
