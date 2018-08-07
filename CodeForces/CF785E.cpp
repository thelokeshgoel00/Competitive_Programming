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
//template <class T>
//using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

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

int N, Q, arr [200010];
ordered_set<int> tree [800010];
long long ret = 0;

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        tree[p].insert(arr[L]);
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    for(int i = L; i <= R; i++) tree[p].insert(arr[i]);
}

void update(int p, int L, int R, int i, int j){
    if(L == R){
        tree[p].erase(arr[i]); tree[p].insert(arr[j]);
        return;
    }
    int li = left(p), ri = right(p);
    if(i <= (L+R)/2) update(li, L, (L+R)/2, i, j);
    else update(ri, (L+R)/2+1, R, i, j);
    if(j >= L && j <= R) return;
    tree[p].erase(arr[i]); tree[p].insert(arr[j]);
}

int query(int p, int L, int R, int i, int j, int val){
    if(L > R || L > j || R < i) return 0;
    if(L >= i && R <= j) return tree[p].order_of_key(val);
    int li = left(p), ri = right(p);
    return query(li, L, (L+R)/2, i, j, val)+query(ri, (L+R)/2+1, R, i, j, val);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) arr[i] = i;
    build(1, 0, N-1);
    for(int i = 0; i < Q; i++){
        int li, ri; cin >> li >> ri; li--; ri--;
        if(li > ri) swap(li, ri);
        ret -= ri-li-1-query(1, 0, N-1, li+1, ri-1, arr[ri]);
        ret -= query(1, 0, N-1, li+1, ri, arr[li]);
        update(1, 0, N-1, li, ri); update(1, 0, N-1, ri, li); swap(arr[li], arr[ri]);
        ret += ri-li-1-query(1, 0, N-1, li+1, ri-1, arr[ri]);
        ret += query(1, 0, N-1, li+1, ri, arr[li]);
        cout << ret << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
