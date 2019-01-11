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

int N, dp [2][90010], highest [2][90010];
pair<pair<int, int>, int> arr [310];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N; memset(dp, -1, sizeof(dp)); memset(highest, -1, sizeof(highest));
    dp[0][0] = highest[0][0] = 0;
    for(int a = 1; a <= N; a++){
        string s; cin >> s;
        int mini = 0, sum = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') sum++;
            else sum--;
            mini = min(mini, sum);
        }
        arr[a] = mp(mp(-mini, -sum), s.length());
    }
    sort(arr+1, arr+N+1);
    for(int a = 1; a <= N; a++){
        int curr = a&1, prevy = curr^1, mini = -arr[a].f.f, sum = -arr[a].f.s;
        for(int i = 0; i < 90010; i++){
            dp[curr][i] = dp[prevy][i]; highest[curr][i] = highest[prevy][i];
            int j = i-sum;
            if(j > -1 && j < 90010 && highest[prevy][j]+mini > -1 && dp[prevy][j] != -1){
                if(dp[curr][i] < dp[prevy][j]+arr[a].s){
                    dp[curr][i] = dp[prevy][j]+arr[a].s;
                    highest[curr][i] = highest[prevy][j]+max(sum, 0);
                }
                else if(dp[curr][i] == dp[prevy][j]+arr[a].s)
                    highest[curr][i] = max(highest[curr][i], highest[prevy][j]+max(sum, 0));
            }
        }
    }
    cout << dp[N&1][0] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
