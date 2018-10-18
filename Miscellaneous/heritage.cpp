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
unordered_map<string, long long> stuff;
long long dp [40];

int main(){
    //freopen("greedy.in", "r", stdin); freopen("greedy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> s; s = '.'+s; memset(dp, 0, sizeof(dp)); dp[0] = 1;
    for(int i = 0; i < N; i++){
        string d; long long x; cin >> d >> x;
        stuff[d] = x;
    }
    for(int i = 0; i < s.length(); i++){
        if(dp[i] == 0) continue;
        for(int len = 1; i+len < s.length(); len++){
            string temp = s.substr(i+1, len);
            dp[i+len] = (dp[i+len]+(stuff[temp]*dp[i]%MOD))%MOD;
        }
    }
    cout << dp[s.length()-1] << '\n';
    return 0;
}
