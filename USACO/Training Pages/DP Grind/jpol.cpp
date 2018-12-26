/*
ID: vamaddu1
LANG: C++11
TASK: jpol
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
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int K, total = 0;
pair<int, int> ori [210];
vector<pair<int, int>> arr;

int main(){
    freopen("jpol.in", "r", stdin); freopen("jpol.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> K;
    for(int i = 1; i <= 3*K; i++){
        cin >> ori[i].f;
        ori[i].s = i;
    }
    sort(ori+1, ori+3*K+1);
    for(int i = 1; i <= 3*K; i++){
        if(i <= K) cout << ori[i].s << '\n';
        else{ arr.pb(ori[i]); total += ori[i].f; }
    }
    while(true){
        random_shuffle(arr.begin(), arr.end());
        int sum = 0;
        for(int i = 0; i < K; i++) sum += arr[i].f;
        if(sum > 500*K && total-sum > 500*K) break;
    }
    for(int i = 0; i < 2*K; i++) cout << arr[i].s << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
