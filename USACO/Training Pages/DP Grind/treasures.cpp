/*
ID: vamaddu1
LANG: C++11
TASK: treasures
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

int N, dp [2][1010], ret = 0;
pair<pair<int, int>, int> arr [1010];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.f.f-a.f.s != b.f.f-b.f.s) return a.f.f-a.f.s < b.f.f-b.f.s;
    return a.f.f+a.f.s < b.f.f+b.f.s;
}

void resetIt(int curr){ fill(dp[curr], dp[curr]+N+1, -MOD); }

int main(){
    freopen("treasures.in", "r", stdin); freopen("treasures.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N; arr[0].f = mp(-MOD, 0);
    for(int i = 1; i <= N; i++){
        cin >> arr[i].f.f >> arr[i].f.s >> arr[i].s;
        arr[i].f.s *= -1;
    }
    sort(arr, arr+N+1, cmp);
    for(int i = 0; i < N; i++){
        int curr = i&1, nexty = curr^1; resetIt(nexty);
        for(int j = 0; j <= i; j++){
            dp[nexty][j] = max(dp[nexty][j], dp[curr][j]);
            if(arr[i+1].f.f+arr[i+1].f.s > arr[j].f.f+arr[j].f.s){
                int area = arr[i+1].f.s*arr[i+1].f.s;
                int s = (arr[j].f.f+arr[j].f.s)-(arr[i+1].f.f-arr[i+1].f.s)-1;
                if(s > 0){
                    if(s%2) area -= (s+1)*(s+1)/4;
                    else area -= (s/2+1)*s/2;
                }
                dp[nexty][i+1] = max(dp[nexty][i+1], dp[curr][j]+arr[i+1].s-area);
                ret = max(ret, dp[nexty][i+1]);
            }
            else{
                dp[nexty][j] = max(dp[nexty][j], dp[curr][j]+arr[i+1].s);
                ret = max(ret, dp[nexty][j]);
            }
        }
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
