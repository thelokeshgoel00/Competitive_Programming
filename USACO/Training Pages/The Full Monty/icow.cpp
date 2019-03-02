/*
ID: vamaddu1
PROG: icow
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

struct Node{
    pair<int, int> val;
    int lazy;
    Node(){ val = mp(0, 0); lazy = 0; }
};

int N, T, arr [100010];
Node tree [400010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }
void combine(Node a, Node b, Node &c){ c.val = max(a.val, b.val); }

void applyIt(int p, int L, int R, int lazy){
	tree[p].val.f += lazy;
	if(L != R) tree[p].lazy += lazy;
}

void pushDown(int p, int L, int R){
	int li = left(p), ri = right(p);
	applyIt(li, L, (L+R)/2, tree[p].lazy); applyIt(ri, (L+R)/2+1, R, tree[p].lazy);
	tree[p].lazy = 0;
}

void build(int p, int L, int R){
    if(L == R){
        tree[p].val = mp(arr[L], -L);
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    combine(tree[li], tree[ri], tree[p]);
}

void update(int p, int L, int R, int i, int j, int val){
    if(tree[p].lazy != 0 && L != R) pushDown(p, L, R);
	if(i > R || j < L) return;
	if(i <= L && j >= R){
		applyIt(p, L, R, val);
		return;
	}
	int li = left(p), ri = right(p);
	update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
	combine(tree[li], tree[ri], tree[p]);
}

Node query(int p, int L, int R, int i, int j){
	if(i > R || j < L) return Node();
	if(tree[p].lazy != 0 && L != R) pushDown(p, L, R);
	if(i <= L && j >= R) return tree[p];
	int li = left(p), ri = right(p); Node a, b, c;
	a = query(li, L, (L+R)/2, i, j); b = query(ri, (L+R)/2+1, R, i, j);
	combine(a, b, c);
	return c;
}

int main(){
    freopen("icow.in", "r", stdin); freopen("icow.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> T;
    for(int i = 0; i < N; i++) cin >> arr[i];
    build(1, 0, N-1);
    for(int i = 0; i < T; i++){
        Node best = query(1, 0, N-1, 0, N-1);
        int idx = -best.val.s;
        cout << idx+1 << '\n';
        int everyAdd = best.val.f/(N-1), remainder = best.val.f%(N-1);
        if(idx > 0) update(1, 0, N-1, 0, idx-1, everyAdd);
        if(idx < N-1) update(1, 0, N-1, idx+1, N-1, everyAdd);
        update(1, 0, N-1, idx, idx, -best.val.f);
        if(remainder == 0) continue;
        if(remainder-1 < idx) update(1, 0, N-1, 0, remainder-1, 1);
        else{
            update(1, 0, N-1, 0, idx-1, 1);
            update(1, 0, N-1, idx+1, remainder, 1);
        }
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
