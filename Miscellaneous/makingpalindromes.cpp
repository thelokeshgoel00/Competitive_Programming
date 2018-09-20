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

int N;
string s;
long long pow26 [210], dp [210][210][210];

long long solveIt(int curr, int st, int en){
    if(dp[curr][st][en] != -1) return dp[curr][st][en];
    if(st > en) return dp[curr][st][en] = pow26[N-curr];
    if(curr == N) return dp[curr][st][en] = 0;
    dp[curr][st][en] = 0;
    if(s[st] == s[en]){
        dp[curr][st][en] = (25*solveIt(curr+1, st, en))%MOD;
        dp[curr][st][en] = (dp[curr][st][en]+solveIt(curr+1, st+1, en-1))%MOD;
    }
    else{
        dp[curr][st][en] = (24*solveIt(curr+1, st, en))%MOD;
        dp[curr][st][en] = (dp[curr][st][en]+solveIt(curr+1, st+1, en))%MOD;
        dp[curr][st][en] = (dp[curr][st][en]+solveIt(curr+1, st, en-1))%MOD;
    }
    return dp[curr][st][en];
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> s; s = "#"+s+"#"; pow26[0] = 1; memset(dp, -1, sizeof(dp));
    for(int i = 1; i < N; i++) pow26[i] = (pow26[i-1]*26)%MOD;
    cout << solveIt(0, 1, N) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
