/*
ID: vamaddu1
LANG: C++11
TASK: apples
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

int N, S, dp [5010], ret = 0;
pair<long long, pair<long long, long long>> arr [5010];

long long dist(int a, int b){
    return (arr[a].s.f-arr[b].s.f)*(arr[a].s.f-arr[b].s.f)+
            (arr[a].s.s-arr[b].s.s)*(arr[a].s.s-arr[b].s.s);
}

int main(){
    freopen("apples.in", "r", stdin); freopen("apples.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> S; arr[0] = mp(0, mp(0, 0));
    for(int i = 1; i <= N; i++) cin >> arr[i].s.f >> arr[i].s.s >> arr[i].f;
    sort(arr, arr+N+1);
    for(int i = 1; i <= N; i++){
        if(dist(i, 0) > S*S*arr[i].f*arr[i].f){
            dp[i] = -MOD;
            continue;
        }
        else dp[i] = 1;
        for(int j = 1; j < i; j++)
            if(dist(i, j) <= S*S*(arr[i].f-arr[j].f)*(arr[i].f-arr[j].f))
                dp[i] = max(dp[i], dp[j]+1);
        ret = max(ret, dp[i]);
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
