/*
ID: vamaddu1
LANG: C++11
TASK: cowset
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

int N, A, B, arr [35];
vector<int> possible;
long long ret = 0;

int binSearchLow(int sum){
    int lo = 0, hi = possible.size()-1, pos = possible.size();
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(possible[mid]+sum >= A){ hi = mid-1; pos = mid; }
        else lo = mid+1;
    }
    return pos;
}

int binSearchHigh(int sum){
    int lo = 0, hi = possible.size()-1, pos = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(possible[mid]+sum <= B){ lo = mid+1; pos = mid; }
        else hi = mid-1;
    }
    return pos;
}

int main(){
    freopen("cowset.in", "r", stdin); freopen("cowset.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> A >> B;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int mask = 0; mask < (1<<(N/2)); mask++){
        int sum = 0;
        for(int i = 0; i < N/2; i++)
            if(mask&(1<<i))
                sum += arr[i];
        possible.pb(sum);
    }
    sort(possible.begin(), possible.end());
    for(int mask = 0; mask < (1<<(N-N/2)); mask++){
        int sum = 0;
        for(int i = 0; i < N-N/2; i++)
            if(mask&(1<<i))
                sum += arr[N/2+i];
        int lo = binSearchLow(sum), hi = binSearchHigh(sum);
        if(lo <= hi) ret += hi-lo+1;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
