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
#include <bitset>
#include <math.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, M, parents [10010], disc [10010], low [10010], tiempo = 0, ret = 0;
bool visited [10010];
vector<int> adjacency [10010];
map<pair<int, int>, int> edgeFreq;
set<pair<int, int>> bridges;
queue<int> q;

void findBridges(int curr){
    visited[curr] = true; disc[curr] = low[curr] = tiempo++;
    for(int next : adjacency[curr]){
        if(!visited[next]){
            parents[next] = curr; findBridges(next);
            low[curr] = min(low[curr], low[next]);
            if(low[next] > disc[curr] && edgeFreq[mp(min(curr, next), max(curr, next))] == 1)
                bridges.insert(mp(min(curr, next), max(curr, next)));
        }
        else if(next != parents[curr]) low[curr] = min(low[curr], disc[next]);
    }
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M; memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low)); memset(parents, -1, sizeof(parents));
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b; if(a > b) swap(a, b);
        adjacency[a].push_back(b); adjacency[b].push_back(a);
        if(edgeFreq.find(mp(a, b)) == edgeFreq.end()) edgeFreq[mp(a, b)] = 0;
        edgeFreq[mp(a, b)]++;
    }
    for(int i = 0; i < N; i++)
        if(!visited[i])
            findBridges(i);
    q.push(0); memset(visited, false, sizeof(visited));
    while(q.size() > 0){
        int x = q.front(); q.pop();
        if(visited[x]) continue;
        visited[x] = true; ret++;
        for(int y : adjacency[x])
            if(!visited[y] && bridges.find(mp(min(x, y), max(x, y))) == bridges.end())
                q.push(y);
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
