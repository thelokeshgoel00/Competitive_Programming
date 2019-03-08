/*
ID: vamaddu1
LANG: C++11
TASK: fewcoins
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

int N, T, V [110], C [110], dp [2][30010], easy [2][30010], ret = MOD;

int main(){
    freopen("fewcoins.in", "r", stdin); freopen("fewcoins.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> T;
    for(int i = 1; i <= N; i++) cin >> V[i];
    for(int i = 1; i <= N; i++) cin >> C[i];
    memset(dp[0], 0x3f, sizeof(dp[0])); memset(easy[0], 0x3f, sizeof(easy[0]));
    dp[0][0] = easy[0][0] = 0;
    for(int i = 1; i <= N; i++){
        int curr = i&1, prevy = curr^1;
        memset(dp[curr], 0x3f, sizeof(dp[curr])); memset(easy[curr], 0x3f, sizeof(easy[curr]));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq [130];
        for(int j = 0; j < 30010; j++){
            easy[curr][j] = easy[prevy][j];
            if(j >= V[i]) easy[curr][j] = min(easy[curr][j], easy[curr][j-V[i]]+1);
            pq[j%V[i]].push(mp(dp[prevy][j]-j/V[i], j));
            while(pq[j%V[i]].size() > 0){
                pair<int, int> now = pq[j%V[i]].top();
                if(j-now.s > V[i]*C[i]){
                    pq[j%V[i]].pop();
                    continue;
                }
                else break;
            }
            if(pq[j%V[i]].size() > 0) dp[curr][j] = pq[j%V[i]].top().f+j/V[i];
        }
    }
    for(int i = T; i < 30010; i++) ret = min(ret, dp[N&1][i]+easy[N&1][i-T]);
    if(ret == MOD) ret = -1;
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
