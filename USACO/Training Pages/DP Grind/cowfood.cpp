/*
ID: vamaddu1
LANG: C++11
TASK: cowfood
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

int N, M, bad [15], dp [2][1<<12];
vector<int> transitions;

int main(){
    freopen("cowfood.in", "r", stdin); freopen("cowfood.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < M; j++){
            int x; cin >> x;
            if(!x) bad[i] |= (1<<j);
        }
    for(int mask = 0; mask < (1<<M); mask++)
        if((mask&(mask<<1)) == 0)
            transitions.pb(mask);
    fill(dp[0], dp[0]+(1<<M), 1);
    for(int i = 1; i <= N; i++){
        int now = i%2, prevy = (i-1)%2;
        fill(dp[now], dp[now]+(1<<M), 0);
        for(int mask = 0; mask < (1<<M); mask++){
            if(bad[i]&(~mask)) continue;
            for(int k : transitions){
                if(k&mask) continue;
                dp[now][mask] += dp[prevy][k|bad[i-1]];
                dp[now][mask] %= 100000000;
            }
        }
    }
    cout << dp[N%2][bad[N]] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
