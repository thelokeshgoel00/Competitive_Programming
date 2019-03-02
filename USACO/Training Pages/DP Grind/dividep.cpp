/*
ID: vamaddu1
PROG: dividep
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

int N, L, A, B, dp [1000010];
deque<int> dq;

int main(){
    freopen("dividep.in", "r", stdin); freopen("dividep.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> L >> A >> B; fill(dp+1, dp+L+1, MOD);
    for(int i = 0; i < N; i++){
        int s, e; cin >> s >> e;
        for(int j = s+1; j < e; j++) dp[j] = MOD+1;
    }
    for(int i = 2; i < 2*A; i += 2) dp[i] = MOD+1;
    for(int i = 2*A; i <= L; i += 2){
        while(dq.size() > 0 && dp[dq.back()] >= dp[i-2*A]) dq.pop_back();
        dq.pb(i-2*A);
        while(dq.size() > 0 && dq.front() < i-2*B) dq.pop_front();
        if(dq.size() > 0 && dp[i] <= MOD) dp[i] = dp[dq.front()]+1;
    }
    if(dp[L] >= MOD) cout << "-1\n";
    else cout << dp[L] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
