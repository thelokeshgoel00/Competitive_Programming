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
	long long cnt, cost, lazy;
	Node(){ cnt = cost = lazy = 0; }
};

int N = 2000000, Q;
Node tree [8000100];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void combine(Node a, Node b, Node &c){
	c.cnt = a.cnt+b.cnt;
	c.cost = a.cost+b.cost;
}

void applyIt(int p, long long L, long long R, long long lazy){
	if(lazy == -1){
		tree[p].cnt = tree[p].cost = 0;
		if(L != R) tree[p].lazy = lazy;
		return;
	}
	tree[p].cnt += lazy*(R-L+1);
	tree[p].cost += lazy*(R*(R+1)/2-L*(L-1)/2);
	if(L == R) return;
	if(tree[p].lazy == -1){
		tree[p].lazy = lazy;
		int li = left(p), ri = right(p);
		tree[li] = Node(); tree[ri] = Node();
		tree[li].lazy = tree[ri].lazy = -1;
	}
	else tree[p].lazy += lazy;
}

void pushDown(int p, int L, int R){
	int li = left(p), ri = right(p);
	applyIt(li, L, (L+R)/2, tree[p].lazy); applyIt(ri, (L+R)/2+1, R, tree[p].lazy);
	tree[p].lazy = 0;
}

void update(int p, int L, int R, int i, int j, long long val){
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

long long buyAmt(int p, int L, int R, long long Q){
	if(tree[p].lazy != 0 && L != R) pushDown(p, L, R);
	long long ret = 0;
	if(tree[p].cost <= Q){
		ret = tree[p].cnt; tree[p] = Node();
		if(L != R) tree[p].lazy = -1;
	}
	else{
		if(L == R){
			ret = Q/L; tree[p].cnt -= ret;
			tree[p].cost -= ret*L;
		}
		else{
			int li = left(p), ri = right(p);
			if(tree[li].cost >= Q) ret = buyAmt(li, L, (L+R)/2, Q);
			else{
				Q -= tree[li].cost;
				ret = buyAmt(li, L, (L+R)/2, tree[li].cost)+buyAmt(ri, (L+R)/2+1, R, Q);
			}
			combine(tree[li], tree[ri], tree[p]);
		}
	}
	return ret;
}

long long buyLow(int p, int L, int R, long long Q){
	if(tree[p].lazy != 0 && L != R) pushDown(p, L, R);
	long long ret = 0;
	if(tree[p].cnt <= Q){
		ret = tree[p].cost; tree[p] = Node();
		if(L != R) tree[p].lazy = -1;
	}
	else{
		if(L == R){
			ret = Q*L; tree[p].cnt -= Q;
			tree[p].cost -= ret;
		}
		else{
			int li = left(p), ri = right(p);
			if(tree[li].cnt >= Q) ret = buyLow(li, L, (L+R)/2, Q);
			else{
				Q -= tree[li].cnt;
				ret = buyLow(li, L, (L+R)/2, tree[li].cnt)+buyLow(ri, (L+R)/2+1, R, Q);
			}
			combine(tree[li], tree[ri], tree[p]);
		}
	}
	return ret;
}

long long buyHigh(int p, int L, int R, long long Q){
	if(tree[p].lazy != 0 && L != R) pushDown(p, L, R);
	long long ret = 0;
	if(tree[p].cnt <= Q){
		ret = tree[p].cost; tree[p] = Node();
		if(L != R) tree[p].lazy = -1;
	}
	else{
		if(L == R){
			ret = Q*L; tree[p].cnt -= Q;
			tree[p].cost -= ret;
		}
		else{
			int li = left(p), ri = right(p);
			if(tree[ri].cnt >= Q) ret = buyHigh(ri, (L+R)/2+1, R, Q);
			else{
				Q -= tree[ri].cnt;
				ret = buyHigh(li, L, (L+R)/2, Q)+buyHigh(ri, (L+R)/2+1, R, tree[ri].cnt);
			}
			combine(tree[li], tree[ri], tree[p]);
		}
	}
	return ret;
}

long long getCost(int p, int L, int R, long long C){
	if(tree[p].lazy != 0 && L != R) pushDown(p, L, R);
	long long ret = -1;
	if(L == R) ret = L;
	else{
		int li = left(p), ri = right(p);
		if(tree[li].cnt >= C) ret = getCost(li, L, (L+R)/2, C);
		else{
			C -= tree[li].cnt;
			ret = getCost(ri, (L+R)/2+1, R, C);
		}
	}
	return ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> Q;
    for(int qq = 1; qq <= Q; qq++){
        string command; cin >> command;
        if(command.compare("ADD") == 0){
            long long K; int P; cin >> K >> P;
            update(1, 1, N, P, P, K);
        }
        if(command.compare("ADDRANGE") == 0){
            int A, B; cin >> A >> B;
            update(1, 1, N, A, B, 1);
        }
        if(command.compare("BUYAMT") == 0){
            long long Q; cin >> Q;
            cout << buyAmt(1, 1, N, Q) << '\n';
        }
        if(command.compare("BUYLOW") == 0){
            long long Q; cin >> Q;
            cout << buyLow(1, 1, N, Q) << '\n';
        }
        if(command.compare("BUYHIGH") == 0){
            long long Q; cin >> Q;
            cout << buyHigh(1, 1, N, Q) << '\n';
        }
        if(command.compare("COST") == 0){
            long long C; cin >> C;
            if(query(1, 1, N, 1, N).cnt < C) cout << "-1\n";
            else cout << getCost(1, 1, N, C) << '\n';
        }
        if(command.compare("NUMCONES") == 0) cout << query(1, 1, N, 1, N).cnt << '\n';
        if(command.compare("TOTALCOST") == 0) cout << query(1, 1, N, 1, N).cost << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
