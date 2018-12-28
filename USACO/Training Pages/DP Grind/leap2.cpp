/*
ID: vamaddu1
LANG: C++11
TASK: leap2
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
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, grid [410][410], best, dx [] = {1, 1, -1, -1, 2, 2, -2, -2}, dy [] = {2, -2, 2, -2, 1, -1, 1, -1};
pair<int, int> loc [160010], dp [160010];

bool inBounds(int x, int y){ return min(x, y) > -1 && max(x, y) < N; }

int main(){
    freopen("leap2.in", "r", stdin); freopen("leap2.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N; best = N*N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
            loc[grid[i][j]] = mp(i, j);
        }
    for(int i = N*N; i > 0; i--){
        dp[i] = mp(1, -MOD);
        for(int a = 0; a < 8; a++){
            int nr = loc[i].f+dx[a], nc = loc[i].s+dy[a];
            if(inBounds(nr, nc) && grid[nr][nc] > i)
                dp[i] = max(dp[i], mp(dp[grid[nr][nc]].f+1, -grid[nr][nc]));
        }
        if(dp[i].f >= dp[best].f) best = i;
    }
    cout << dp[best].f << '\n';
    while(best != MOD){
        cout << best << '\n';
        best = -dp[best].s;
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
