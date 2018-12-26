/*
ID: vamaddu1
LANG: C++11
TASK: cheappal
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

int N, M, costs [26], dp [3][2010];
string s;

int main(){
    freopen("cheappal.in", "r", stdin); freopen("cheappal.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N >> M >> s;
    for(int i = 0; i < N; i++){
        char c; int a, b; cin >> c >> a >> b;
        costs[c-'a'] = min(a, b);
    }
    for(int len = 2; len <= M; len++)
        for(int i = 0; i < M-len+1; i++){
            if(s[i] == s[i+len-1]) dp[len%3][i] = dp[(len-2)%3][i+1];
            else dp[len%3][i] = min(dp[(len-1)%3][i+1]+costs[s[i]-'a'], dp[(len-1)%3][i]+costs[s[i+len-1]-'a']);
        }
    cout << dp[M%3][0] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
