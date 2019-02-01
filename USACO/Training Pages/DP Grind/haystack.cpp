/*
ID: vamaddu1
LANG: C++11
TASK: haystack
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

int N, dp [210][210][2], ret = MOD;
pair<int, int> arr [210];

int solveIt(int li, int ri, int which){
    if(dp[li][ri][which] != -1) return dp[li][ri][which];
    if(li > ri) return dp[li][ri][which] = 0;
    if(li == ri) return dp[li][ri][which]= arr[li].s;
    int best = MOD, base;
    for(int mid = li; mid <= ri; mid++){
        if(which) base = arr[ri].f-arr[mid].f+2*arr[mid].s;
        else base = arr[mid].f-arr[li].f+2*arr[mid].s;
        int trash1 = solveIt(li, mid-1, 1);
        if(li <= mid-1) trash1 += arr[mid].f-arr[mid-1].f;
        int trash0 = solveIt(mid+1, ri, 0);
        if(mid+1 <= ri) trash0 += arr[mid+1].f-arr[mid].f;
        best = min(best, base+max(trash1, trash0));
    }
    return dp[li][ri][which] = best;
}

int main(){
    freopen("haystack.in", "r", stdin); freopen("haystack.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N; memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= N; i++){ cin >> arr[i].f >> arr[i].s; arr[i].s = abs(arr[i].s); }
    sort(arr+1, arr+N+1); arr[0] = arr[1]; arr[N+1] = arr[N];
    if(N == 1){
        cout << abs(arr[1].f)+arr[1].s << '\n';
        return 0;
    }
    for(int i = 1; i <= N; i++)
        ret = min(ret, abs(arr[i].f)+2*arr[i].s+max(solveIt(1, i-1, 1)+arr[i].f-arr[i-1].f, solveIt(i+1, N, 0)+arr[i+1].f-arr[i].f));
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
