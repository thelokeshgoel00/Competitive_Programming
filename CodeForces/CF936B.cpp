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

int N, M, dp [100010][2], nexts [100010][2], works, st;
vector<int> adjacency [100010];
bool visited [100010][2], canTie [100010][2];

int solveIt(int curr, int parity){
    if(dp[curr][parity] != -1) return dp[curr][parity];
    nexts[curr][parity] = -1; visited[curr][parity] = true;
    if(adjacency[curr].size() == 0) return dp[curr][parity] = parity;
    for(int nexty : adjacency[curr]){
        if(visited[nexty][parity^1] && dp[nexty][parity^1] == -1){
            canTie[curr][parity] = true;
            continue;
        }
        if(dp[curr][parity] != 1 && solveIt(nexty, parity^1)){
            nexts[curr][parity] = nexty;
            dp[curr][parity] = 1;
        }
        canTie[curr][parity] |= canTie[nexty][parity^1];
    }
    dp[curr][parity] = max(dp[curr][parity], 0);
    return dp[curr][parity];
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; memset(dp, -1, sizeof(dp)); memset(nexts, -1, sizeof(nexts));
    memset(visited, false, sizeof(visited)); memset(canTie, false, sizeof(canTie));
    for(int i = 1; i <= N; i++){
        int x; cin >> x;
        for(int j = 0; j < x; j++){
            int y; cin >> y;
            adjacency[i].pb(y);
        }
    }
    cin >> st;
    works = solveIt(st, 0);
    if(works){
        cout << "Win\n";
        int curr = st, parity = 0;
        while(curr != -1){
            cout << curr << ' ';
            curr = nexts[curr][parity]; parity ^= 1;
        }
        cout << '\n';
        return 0;
    }
    if(canTie[st][0]) cout << "Draw\n";
    else cout << "Lose\n";
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
