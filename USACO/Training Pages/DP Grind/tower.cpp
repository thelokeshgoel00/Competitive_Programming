/*
ID: vamaddu1
LANG: C++11
TASK: tower
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

int N, dp [3][10010];
//0 = obligated to cover
//1 = covered from above
//2 = neutral
vector<int> adjacency[10010];

int go(int type, int now, int from){
    if(dp[type][now] != -1) return dp[type][now];
    if(adjacency[now].size() == 1 && from != -1){
        if(type == 1) dp[type][now] = 0;
        else dp[type][now] = 1;
        return dp[type][now];
    }
    int oneSum = 0, twoSum = 0;
    for(int i = 0; i < adjacency[now].size(); i++)
        if(adjacency[now][i] != from){
            oneSum += go(1, adjacency[now][i], now);
            twoSum += go(2, adjacency[now][i], now);
        }
    if(type == 0) dp[type][now] = 1+oneSum;
    else if(type == 1) dp[type][now] = min(twoSum, 1+oneSum);
    else{
        dp[type][now] = 1+oneSum;
        for(int i = 0; i < adjacency[now].size(); i++){
            if(adjacency[now][i] == from) continue;
            dp[type][now] = min(dp[type][now], twoSum-go(2, adjacency[now][i],now)+go(0, adjacency[now][i],now));
        }
    }
    return dp[type][now];
}

int main(){
    freopen("tower.in", "r", stdin); freopen("tower.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N; memset(dp, -1, sizeof(dp));
    for(long i = 1; i < N; i++){
        int a, b; cin >> a >> b; a--; b--;
        adjacency[a].pb(b); adjacency[b].pb(a);
    }
    cout << go(2, 0, -1) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
