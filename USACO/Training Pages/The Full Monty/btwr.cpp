/*
ID: vamaddu1
LANG: C++11
TASK: btwr
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

int N, taggy = 0, dp [50010], tree [200010];
pair<int, int> arr [50010];
set<int> ys;
unordered_map<int, int> compress;

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void update(int p, int L, int R, int place, int val){
    if(L > place || R < place) return;
    if(L == R){
        tree[p] = max(tree[p], val);
        return;
    }
    int li = left(p); int ri = right(p);
    update(li, L, (L+R)/2, place, val); update(ri, (L+R)/2+1, R, place, val);
    tree[p] = max(tree[li], tree[ri]);
}

int query(int p, int L, int R, int i, int j){
    if(j < L || i > R) return 0;
    if(L >= i && R <= j) return tree[p];
    int li = left(p); int ri = right(p);
    return max(query(li, L, (L+R)/2, i, j), query(ri, (L+R)/2+1, R, i, j));
}

int main(){
    freopen("btwr.in", "r", stdin); freopen("btwr.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i].f >> arr[i].s;
        ys.insert(arr[i].s);
    }
    sort(arr, arr+N);
    for(auto it = ys.begin(); it != ys.end(); it++) compress[*it] = taggy++;
    for(int i = 0; i < N; ){
        int j = i;
        while(j < N && arr[i].f == arr[j].f){
            arr[j].s = compress[arr[j].s];
            if(arr[j].s == 0) dp[j] = 1;
            else dp[j] = query(1, 0, taggy-1, 0, arr[j].s-1)+1;
            j++;
        }
        for(int k = i; k < j; k++) update(1, 0, taggy-1, arr[k].s, dp[k]);
        i = j;
    }
    cout << *max_element(dp, dp+N) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
