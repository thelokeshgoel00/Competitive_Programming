/*
ID: vamaddu1
PROG: highway
LANG: C++11
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

int N, perm [3];
long long one [100010], two [100010], dp [100010];

int main(){
    freopen("highway.in", "r", stdin); freopen("highway.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> one[i] >> two[i];
    sort(one+1, one+N+1); sort(two+1, two+N+1);
    for(int i = 1; i <= N; i++){
        dp[i] = INF;
        if(one[i] != two[i])
            dp[i] = min(dp[i], dp[i-1]+abs(one[i]-two[i]));
        if(i < 2) continue;
        if(one[i] != two[i] && one[i-1] != two[i-1])
            dp[i] = min(dp[i], dp[i-2]+abs(one[i]-two[i])+abs(one[i-1]-two[i-1]));
        if(one[i-1] != two[i] && one[i] != two[i-1])
            dp[i] = min(dp[i], dp[i-2]+abs(one[i-1]-two[i])+abs(one[i]-two[i-1]));
        if(i < 3) continue;
        perm[0] = 0; perm[1] = 1; perm[2] = 2;
        do{
            long long temp = dp[i-3]; bool ok = true;
            for(int a = 0; a < 3; a++){
                if(one[i-a] == two[i-perm[a]]) ok = false;
                temp += abs(one[i-a]-two[i-perm[a]]);
            }
            if(ok) dp[i] = min(dp[i], temp);
        }while(next_permutation(perm, perm+3));
    }
    cout << dp[N] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
