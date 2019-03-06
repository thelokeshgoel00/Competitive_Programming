/*
ID: vamaddu1
LANG: C++11
TASK: cbridge
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

int N, M, B, lo, hi, ret;
long long powa [35], arr [50010], freq [35];

int main(){
    freopen("cbridge.in", "r", stdin); freopen("cbridge.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M >> B; lo = 0; hi = M; powa[0] = 1;
    for(int i = 0; i <= B; i++){ cin >> freq[i]; powa[i+1] = powa[i]*2; }
    for(int i = 0; i < M; i++) cin >> arr[i];
    while(lo <= hi){
        int mid = (lo+hi)/2;
        priority_queue<long long> pq;
        for(int i = 0; i < mid; i++) pq.push(arr[i]);
        for(int i = 32; i > -1 && pq.size() > 0; i--)
            for(int j = 0; j < freq[i] && pq.size() > 0; j++){
                long long x = pq.top(); pq.pop();
                if(x > powa[i]) pq.push(x-powa[i]);
            }
        if(pq.size() == 0){ lo = mid+1; ret = mid; }
        else hi = mid-1;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
