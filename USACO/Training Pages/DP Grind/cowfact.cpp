/*
ID: vamaddu1
LANG: C++11
TASK: cowfact
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

int N, K, M, R, dp [2][10010];
pair<int, int> best = mp(0, 1);

int main(){
    freopen("cowfact.in", "r", stdin); freopen("cowfact.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> K >> M >> R; R = min(R, 100*N);
    for(int i = 1; i <= N; i++){
        int curr = i&1, prevy = curr^1, c, p; cin >> c >> p;
        for(int j = 0; j <= R; j++){
            dp[curr][j] = dp[prevy][j];
            if(j >= c) dp[curr][j] = max(dp[curr][j], dp[prevy][j-c]+p);
            if(j > 0 && dp[curr][j] >= K)
                if(dp[curr][j]*best.s > best.f*j)
                    best = mp(dp[curr][j], j);
        }
    }
    if(best.f == 0) cout << "-1\n";
    else cout << (int)(1000.0*(M-(double)best.s/(double)best.f)) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
