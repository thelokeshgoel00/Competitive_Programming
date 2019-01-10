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

int N, M, C, parents [1810], dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1};
char grid [40][40];
long long costs [26], graph [1810][1810], dp [1810], ret = 0;
queue<int> q;

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < N && y < M; }

void solveIt(){
    int s = 2*N*M, t = s+1;
    while(true){
        fill(parents, parents+2*N*M+2, -1); fill(dp, dp+2*N*M+2, 0);
        parents[s] = -2; dp[s] = INF; q = queue<int>(); q.push(s);
        while(q.size() > 0 && dp[t] == 0){
            int curr = q.front(); q.pop();
            for(int i = 0; i < 2*N*M+2; i++){
                if(parents[i] != -1 || graph[curr][i] == 0) continue;
                dp[i] = min(dp[curr], graph[curr][i]); parents[i] = curr;
                q.push(i);
            }
        }
        ret += dp[t];
        if(dp[t] == 0 || ret >= INF/500) break;
        int curr = t;
        while(curr != s){
            graph[parents[curr]][curr] -= dp[t];
            graph[curr][parents[curr]] += dp[t];
            curr = parents[curr];
        }
    }
    cout << (ret < INF/500 ? ret : -1) << '\n';
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> M >> N >> C;
    for(int i = 0; i < N; i++) cin >> grid[i];
    for(int i = 0; i < C; i++) cin >> costs[i];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            int entryHash = i*M+j, exitHash = entryHash+N*M;
            if(grid[i][j] == 'B') graph[2*N*M][entryHash] = INF/500;
            if(grid[i][j] >= 'a' && grid[i][j] <= 'z') graph[entryHash][exitHash] = costs[grid[i][j]-'a'];
            else graph[entryHash][exitHash] = INF/500;
            if(i == 0 || i == N-1 || j == 0 || j == M-1) graph[exitHash][2*N*M+1] = INF/500;
            for(int k = 0; k < 4; k++){
                int nr = i+dx[k], nc = j+dy[k];
                if(inBounds(nr, nc)) graph[exitHash][nr*M+nc] = INF;
            }
        }
    solveIt();
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
