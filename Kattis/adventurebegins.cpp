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

struct Node{
    long long sum, lazy;
    Node(){ sum = lazy = 0; }
};

int N, Q;
long long inverses [100010], exsquared = 0, varsum = 0;
Node tree [400010];

long long modInverse(long long a, long long m){
    long long m0 = m, t, q;
    long long x0 = 0ll, x1 = 1ll;
    while(a > 1ll){
        q = a/m; t = m;
        m = a%m, a = t;
        t = x0; x0 = x1-q*x0;
        x1 = t;
    }
    if(x1 < 0) x1 += m0;
    return x1;
}

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void pushDown(int p, int L, int R){
    tree[p].sum += (long long)(R-L+1)*tree[p].lazy; tree[p].sum %= MOD;
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].lazy += tree[p].lazy; tree[li].lazy %= MOD;
        tree[ri].lazy += tree[p].lazy; tree[ri].lazy %= MOD;
    }
    tree[p].lazy = 0;
}

long long evalSum(int p, int L, int R) { return (tree[p].sum+(long long)(R-L+1)*tree[p].lazy)%MOD; }

void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p].sum = evalSum(li, L, (L+R)/2)+evalSum(ri, (L+R)/2+1, R);
}

void update(int p, int L, int R, int i, int j, long long val){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){
        tree[p].lazy += val; tree[p].lazy %= MOD;
        return;
    }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
    pullUp(p, L, R);
}

long long sumQuery(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return 0;
    if(L >= i && R <= j) return evalSum(p, L, R);
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    long long ret = (sumQuery(li, L, (L+R)/2, i, j)+sumQuery(ri, (L+R)/2+1, R, i, j))%MOD;
    pullUp(p, L, R);
    return ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) inverses[i] = modInverse(i, MOD);
    for(int qq = 0; qq < Q; qq++){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y; x--; y--;
            int len = y-x+1;
            long long segSum = sumQuery(1, 0, N-1, x, y);
            long long add = ((inverses[len]*inverses[len])%MOD*(long long)(len))%MOD;
            add = (add+(inverses[len]*segSum*2)%MOD)%MOD; exsquared = (exsquared+add)%MOD;
            update(1, 0, N-1, x, y, inverses[len]);
            varsum += (((long long)len*inverses[len])%MOD*((long long)(len-1)*inverses[len])%MOD)%MOD;
            varsum %= MOD;
        }
        else cout << (exsquared+varsum)%MOD << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
