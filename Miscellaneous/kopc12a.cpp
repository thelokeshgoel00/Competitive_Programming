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

int kase, N;
long long heights [10010], costs [10010], lo, hi, ret;

long long checkIt(long long x){
    long long sum = 0;
    for(int i = 0; i < N; i++) sum += abs(heights[i]-x)*costs[i];
    return sum;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; lo = 0; hi = 10000; ret = INF;
        for(int i = 0; i < N; i++) cin >> heights[i];
        for(int i = 0; i < N; i++) cin >> costs[i];
        while(lo <= hi){
            long long t1 = (2*lo+hi)/3, t2 = (lo+2*hi)/3;
            long long eval1 = checkIt(t1), eval2 = checkIt(t2);
            if(eval1 < eval2) hi = t2-1;
            else lo = t1+1;
            ret = min(ret, min(eval1, eval2));
        }
        cout << ret << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
