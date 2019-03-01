/*
ID: vamaddu1
PROG: clusters
LANG: C++11
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

int N;
pair<long long, long long> arr [50010], li = mp(2*MOD, 2*MOD), ri = mp(-2*MOD, -2*MOD);
long long lo = 0, hi = 2*MOD, ret;

int main(){
    freopen("clusters.in", "r", stdin); freopen("clusters.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++){
        long long x, y; cin >> x >> y;
        arr[i] = mp(x+y, x-y);
        li.f = min(li.f, arr[i].f); li.s = min(li.s, arr[i].s);
        ri.f = max(ri.f, arr[i].f); ri.s = max(ri.s, arr[i].s);
    }
    while(lo <= hi){
        long long mid = (lo+hi)/2;
        bool ok1 = true, ok2 = true;
        for(int i = 0; i < N; i++){
            if(max(abs(arr[i].f-li.f), abs(arr[i].s-li.s)) > mid)
                if(max(abs(arr[i].f-ri.f), abs(arr[i].s-ri.s)) > mid)
                    ok1 = false;
            if(max(abs(arr[i].f-li.f), abs(arr[i].s-ri.s)) > mid)
                if(max(abs(arr[i].f-ri.f), abs(arr[i].s-li.s)) > mid)
                    ok2 = false;
        }
        if(ok1 || ok2){ hi = mid-1; ret = mid; }
        else lo = mid+1;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
