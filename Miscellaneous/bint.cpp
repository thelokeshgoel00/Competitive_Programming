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
 
struct Node{
    long long maxi, lazy;
    Node(){ maxi = 0; lazy = 0; }
};
 
int N, M, lasty = 0;
pair<pair<int, int>, long long> intervals [200010];
Node tree [800010];
 
int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }
 
void pushDown(int p, int L, int R){
    tree[p].maxi += tree[p].lazy;
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].lazy += tree[p].lazy;
        tree[ri].lazy += tree[p].lazy;
    }
    tree[p].lazy = 0;
}
 
long long evalMax(int p){ return tree[p].maxi+tree[p].lazy; }
 
void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p].maxi = max(evalMax(li), evalMax(ri));
}
 
void update(int p, int L, int R, int i, int j, long long val){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){ tree[p].lazy += val; return; }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
    pullUp(p, L, R);
}
 
long long maxQuery(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return -INF/5;
    if(L >= i && R <= j) return evalMax(p);
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    long long ret = -INF/5;
    ret = max(ret, max(maxQuery(li, L, (L+R)/2, i, j), maxQuery(ri, (L+R)/2+1, R, i, j)));
    pullUp(p, L, R);
    return ret;
}
 
int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 0; i < M; i++) cin >> intervals[i].f.s >> intervals[i].f.f >> intervals[i].s;
    sort(intervals, intervals+M);
    for(int i = 0; i < M; i++){
        int lefty = intervals[i].f.s, righty = intervals[i].f.f;
        long long val = intervals[i].s;
        if(lasty < righty) update(1, 0, N, lasty+1, righty, maxQuery(1, 0, N, 0, lasty));
        update(1, 0, N, lefty, righty, val); lasty = righty;
    }
    cout << max(0ll, maxQuery(1, 0, N, 0, N)) << '\n';
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
