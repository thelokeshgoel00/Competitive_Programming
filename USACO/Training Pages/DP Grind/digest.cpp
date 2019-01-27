/*
ID: vamaddu1
LANG: C++11
TASK: digest
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

int N, S, sizes [15], curSum = 0;
vector<int> points;
bool dp [40010], used [110];

int main(){
    freopen("digest.in", "r", stdin); freopen("digest.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> S; dp[0] = true;
    for(int i = 1; i <= N; i++){
        cin >> sizes[i];
        for(int j = 0; j < sizes[i]; j++){
            int x; cin >> x;
            points.pb(x);
        }
        sizes[i] += sizes[i-1];
    }
    for(int a = 0; a < points.size(); a++){
        int p = points[a];
        if(p > S-curSum) continue;
        else fill(dp+1, dp+S-curSum-p+1, false);
        for(int i = a+1; i < points.size(); i++){
            int x = points[i];
            for(int j = S-curSum-p; j >= x; j--) dp[j] |= dp[j-x];
        }
        if(dp[S-curSum-p]){ used[a] = true; curSum += p; }
    }
    for(int i = 1; i <= N; i++){
        for(int j = sizes[i-1]; j < sizes[i]; j++){
            if(used[j]) cout << '*';
            else cout << '.';
        }
        cout << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
