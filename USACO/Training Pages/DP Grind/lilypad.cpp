/*
ID: vamaddu1
LANG: C++11
TASK: lilypad
*/

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
#define epsilon 1e-9
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, M, grid [32][32], reachable [32][32][32][32], dists [32][32];
int dx [] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy [] = {-1, -2, -2, -1, 1, 2, 2, 1};
pair<int, int> st, en;
queue<pair<int, int>> q;
long long dp [32][32];

bool inBounds(int x, int y, int k){
    return x+dx[k] > -1 && y+dy[k] > -1 && x+dx[k] < N && y+dy[k] < M;
}

int main(){
    freopen("lilypad.in", "r", stdin); freopen("lilypad.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M; memset(dists, -1, sizeof(dists));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 3){ st = mp(i, j); dists[i][j] = 0; dp[i][j] = 1; }
            if(grid[i][j] == 4) en = mp(i, j);
            if(grid[i][j] >= 3) grid[i][j] = 0;
        }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(grid[i][j] != 0) continue;
            q.push(mp(i, j)); reachable[i][j][i][j] = 1;
            while(q.size() > 0){
                int x = q.front().f, y = q.front().s; q.pop();
                for(int k = 0; k < 8; k++)
                    if(inBounds(x, y, k) && grid[x+dx[k]][y+dy[k]] == 1 && reachable[i][j][x+dx[k]][y+dy[k]] == 0){
                        q.push(mp(x+dx[k], y+dy[k]));
                        reachable[i][j][x+dx[k]][y+dy[k]] = 1;
                    }
            }
            for(int x = 0; x < N; x++)
                for(int y = 0; y < M; y++)
                    if(reachable[i][j][x][y] == 1)
                        for(int k = 0; k < 8; k++)
                            if(inBounds(x, y, k) && grid[x+dx[k]][y+dy[k]] == 0 && reachable[i][j][x+dx[k]][y+dy[k]] == 0)
                                reachable[i][j][x+dx[k]][y+dy[k]] = 2;
        }
    q.push(st);
    while(q.size() > 0){
        int x = q.front().f, y = q.front().s; q.pop();
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++){
                if(reachable[x][y][i][j] != 2) continue;
                if(dists[i][j] == -1){
                    dists[i][j] = dists[x][y]+1;
                    dp[i][j] = dp[x][y]; q.push(mp(i, j));
                }
                else if(dists[i][j] == dists[x][y]+1) dp[i][j] += dp[x][y];
            }
    }
    if(dists[en.f][en.s] == -1) cout << "-1\n";
    else cout << dists[en.f][en.s]-1 << '\n' << dp[en.f][en.s] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
