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

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, E, dists [1010], dp [1010], ret = 0;
pair<int, int> patches [1010]; //quality, ID
vector<int> adjacency [1010];

int main(){
    freopen("buffet.in", "r", stdin); freopen("buffet.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> E; memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++){
        cin >> patches[i].first; patches[i].second = i;
        int numEdges; cin >> numEdges;
        for(int j = 0; j < numEdges; j++){
            int x; cin >> x;
            adjacency[i].push_back(x);
        }
    }
    sort(patches+1, patches+N+1);
    for(int i = N; i > 0; i--){
        int ender = patches[i].second;
        queue<int> q; memset(dists, -1, sizeof(dists));
        q.push(ender); dists[ender] = 0;
        while(q.size() > 0){
            int now = q.front(); q.pop();
            for(int nexty : adjacency[now])
                if(dists[nexty] == -1){
                    q.push(nexty);
                    dists[nexty] = dists[now]+1;
                }
        }
        dp[ender] = patches[i].first;
        for(int j = 1; j <= N; j++)
            if(dists[j] != -1 && j != ender)
                dp[ender] = max(dp[ender], dp[j]+patches[i].first-E*dists[j]);
        ret = max(ret, dp[ender]);
    }
    cout << ret << '\n';
    return 0;
}
