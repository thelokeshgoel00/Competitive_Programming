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

int kase, N, M, K, grid [60][60], dx [] = {1, -1, 0, 0}, dy [] = {0, 0, 1, -1};
int best [110][110], parents [2510], heights [2510], compSizes [2510], ret;
vector<pair<int, int>> seenAtDist [110];
bool visited [60][60], active [60][60];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < N && y < M; }

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

void preprocessIt(int mini){
    for(int i = 0; i < N*M; i++){
        parents[i] = i; heights[i] = 0;
        compSizes[i] = 1; visited[i/M][i%M] = false;
        active[i/M][i%M] = false;
    }
    for(int i = 0; i < 100; i++) seenAtDist[i] = vector<pair<int, int>>();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(grid[i][j] == mini)
                pq.push(mp(0, mp(i, j)));
    while(pq.size() > 0){
        pair<int, pair<int, int>> now = pq.top(); pq.pop();
        if(visited[now.s.f][now.s.s]) continue;
        visited[now.s.f][now.s.s] = true;
        seenAtDist[now.f].pb(now.s);
        for(int a = 0; a < 4; a++){
            int nr = now.s.f+dx[a], nc = now.s.s+dy[a];
            if(!inBounds(nr, nc) || grid[nr][nc] < mini) continue;
            if(!visited[nr][nc]) pq.push(mp(max(now.f, grid[nr][nc]-mini), mp(nr, nc)));
        }
    }
    for(int i = 0; i < 100; i++){
        best[mini][i] = 1;
        for(pair<int, int> loc : seenAtDist[i]) active[loc.f][loc.s] = true;
        for(pair<int, int> loc : seenAtDist[i]){
            for(int a = 0; a < 4; a++){
                int nr = loc.f+dx[a], nc = loc.s+dy[a];
                if(!inBounds(nr, nc) || !active[nr][nc]) continue;
                combine(loc.f*M+loc.s, nr*M+nc);
                best[mini][i] = max(best[mini][i], compSizes[findParent(loc.f*M+loc.s)]);
            }
        }
        if(i > 0) best[mini][i] = max(best[mini][i], best[mini][i-1]);
    }
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> grid[i][j];
    for(int i = 0; i < 100; i++) preprocessIt(i);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> K; ret = 100;
        for(int i = 0; i < 100; i++){
            int j = 0;
            while(j < 100 && best[i][j] < K) j++;
            ret = min(ret, j);
        }
        cout << ret << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
