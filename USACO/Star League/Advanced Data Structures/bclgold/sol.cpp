/*
ID: vamaddu1
LANG: C++11
TASK: bclgold
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

int N, st, en;
char arr [30010];
long long powa [30010], pre [30010], suf [30010];

int main(){
    freopen("bclgold.in", "r", stdin); freopen("bclgold.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N; st = 1; en = N; powa[0] = 1;
    for(int i = 1; i <= N; i++){
        cin >> arr[i]; powa[i] = (powa[i-1]*47)%MOD;
        pre[i] = (pre[i-1]*47+(arr[i]-'A'))%MOD;
    }
    for(int i = N; i > 0; i--) suf[i] = (suf[i+1]*47+(arr[i]-'A'))%MOD;
    while(st < en){
        int lo = 1, hi = (en-st+1)/2, best = 0;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            long long startHash = (pre[st+mid-1]-(pre[st-1]*powa[mid])%MOD+MOD)%MOD;
            long long endinHash = (suf[en-mid+1]-(suf[en+1]*powa[mid])%MOD+MOD)%MOD;
            if(startHash == endinHash){ lo = mid+1; best = mid; }
            else hi = mid-1;
        }
        if(arr[st+best] < arr[en-best]) cout << arr[st++];
        else cout << arr[en--];
        if((st-1+N-en)%80 == 0) cout << '\n';
    }
    cout << arr[st] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
