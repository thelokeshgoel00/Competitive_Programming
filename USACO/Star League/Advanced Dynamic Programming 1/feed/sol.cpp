/*
ID: vamaddu1
LANG: C++11
TASK: feed
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

int N, K;
long long E, dp [2][10010];
pair<long long, pair<int, long long>> arr [510];

int main(){
    freopen("feed.in", "r", stdin); freopen("feed.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> K >> E >> N; arr[0] = mp(0, mp(0, 0));
    for(int i = 1; i <= N; i++) cin >> arr[i].f >> arr[i].s.f >> arr[i].s.s;
    sort(arr+1, arr+N+1); fill(dp[0]+1, dp[0]+K+1, -1);
    for(int i = 1; i <= N; i++){
        int curr = i&1, prevy = curr^1; fill(dp[curr], dp[curr]+K+1, -1);
        long long dist = arr[i].f-arr[i-1].f;
        deque<pair<long long, int>> dq;
        for(int j = 0; j <= K; j++){
            if(dp[prevy][j] != -1){
                pair<long long, int> add = mp(dp[prevy][j]+dist*(long long)(j*j)-arr[i].s.s*j, j+arr[i].s.f);
                while(dq.size() > 0 && dq.back().f > add.f) dq.pop_back();
                dq.pb(add);
            }
            while(dq.size() > 0 && dq.front().s < j) dq.pop_front();
            if(dq.size() > 0) dp[curr][j] = dq.front().f+arr[i].s.s*j;
        }
    }
    cout << dp[N&1][K]+(long long)(K*K)*(E-arr[N].f) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
