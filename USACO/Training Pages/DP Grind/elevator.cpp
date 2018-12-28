/*
ID: vamaddu1
LANG: C++11
TASK: elevator
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

int K, ret = 0;
pair<int, pair<int, int>> blocks [410];
bool dp [40010];

int main(){
    freopen("elevator.in", "r", stdin); freopen("elevator.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> K; dp[0] = true;
    for(int i = 0; i < K; i++){
        int h, a, c; cin >> h >> a >> c;
        blocks[i] = mp(a, mp(h, c));
    }
    sort(blocks, blocks+K);
    for(int i = 0; i < K; i++)
        for(int j = blocks[i].f; j > -1; j--){
            if(dp[j]) continue;
            for(int k = j-blocks[i].s.f, num = 1; k > -1 && num <= blocks[i].s.s; k -= blocks[i].s.f, num++){
                dp[j] |= dp[k];
                if(dp[j]){ ret = max(ret, j); break; }
            }
        }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
