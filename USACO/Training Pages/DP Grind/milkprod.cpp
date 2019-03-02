/*
ID: vamaddu1
PROG: milkprod
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

int N, M, R, id = 0;
tuple<int, int, long long> intervals [50010]; // end, start, value
set<int> allEnd;
unordered_map<int, int> compress;
long long tree [200050], ret = 0;

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void update(int p, int L, int R, int place, long long val){
    if(L > place || R < place) return;
    if(L == R){
        tree[p] = max(tree[p], val);
        return;
    }
    int li = left(p); int ri = right(p);
    update(li, L, (L+R)/2, place, val); update(ri, (L+R)/2+1, R, place, val);
    tree[p] = max(tree[li], tree[ri]);
}

long long query(int p, int L, int R, int i, int j){
    if(j < L || i > R) return 0;
    if(L >= i && R <= j) return tree[p];
    int li = left(p); int ri = right(p);
    return max(query(li, L, (L+R)/2, i, j), query(ri, (L+R)/2+1, R, i, j));
}

int main(){
    freopen("milkprod.in", "r", stdin); freopen("milkprod.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M >> R; allEnd.insert(-MOD); allEnd.insert(MOD);
    for(int i = 0; i < M; i++){
        int s, e; long long v; cin >> s >> e >> v;
        intervals[i] = make_tuple(e, s, v);
        allEnd.insert(e);
    }
    sort(intervals, intervals+M);
    for(auto it = allEnd.begin(); it != allEnd.end(); it++){ compress[*it] = id; id++; }
    for(int i = 0; i < M; i++){
        auto it = allEnd.lower_bound(get<1>(intervals[i])-R);
        while(*it > get<1>(intervals[i])-R) it--;
        int idx1 = compress[*it], idx2 = compress[get<0>(intervals[i])];
        long long now = get<2>(intervals[i])+query(1, 0, 50005, 0, idx1);
        ret = max(ret, now); update(1, 0, 50005, idx2, now);
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
