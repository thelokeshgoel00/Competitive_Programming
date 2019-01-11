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

int N, L, dp [1010][2010];
string s;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> s; L = s.length(); s.append("XXX");
    for(int j = 0; j <= 2*L; j++){
        for(int i = L-1; i > -1; i--){
            dp[i][j] = dp[i+3][j]+(s.compare(i, 3, "ATG") == 0);
            if(j == 0) continue;
            dp[i][j] = max(dp[i][j], dp[i+2][j-1]+(s.compare(i, 2, "AT") == 0 || s.compare(i, 2, "AG") == 0 || s.compare(i, 2, "TG") == 0));
            if(j == 1) continue;
            dp[i][j] = max(dp[i][j], dp[i+1][j-2]+(s.compare(i, 1, "A") == 0 || s.compare(i, 1, "T") == 0 || s.compare(i, 1, "G") == 0));
            if(j == 2) continue;
            dp[i][j] = max(dp[i][j], dp[i][j-3]+1);
        }
        if(dp[0][j] >= N){
            cout << j << '\n';
            return 0;
        }
    }
    cout << min(min((N-dp[0][2*L])*3+2*L, (N-dp[0][2*L-1])*3+2*L-1), (N-dp[0][2*L-2])*3+2*L-2) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
