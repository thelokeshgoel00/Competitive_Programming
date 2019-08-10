#define __USE_MINGW_ANSI_STDIO 0
 
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5e18
#define MOD 1000000007
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
struct Node{
    long long sum, a, b;
    Node(){ sum = a = b = 0; }
};
 
int N, Q, ori [200010];
Node tree [800010];
 
int left(int p){ return p<<1; }
int right(int p){ return (p<<1)^1; }
 
void build(int p, int L, int R){
    if(L == R){
        tree[p].sum = ori[L];
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].sum = tree[li].sum+tree[ri].sum;
}
 
long long evalSum(int p, int L, int R){ return tree[p].sum+((tree[p].a*(L+R)+tree[p].b*2)*(R-L+1))/2; }
 
void pushDown(int p, int L, int R){
    tree[p].sum = evalSum(p, L, R);
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].a += tree[p].a; tree[li].b += tree[p].b;
        tree[ri].a += tree[p].a; tree[ri].b += tree[p].b;
    }
    tree[p].a = tree[p].b = 0;
}
 
void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p].sum = evalSum(li, L, (L+R)/2)+evalSum(ri, (L+R)/2+1, R);
}
 
void update(int p, int L, int R, int i, int j, int a, int b){
    if(L > j || R < i) return;
    if(L >= i && R <= j){
        tree[p].a += a; tree[p].b += b;
        return;
    }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, a, b); update(ri, (L+R)/2+1, R, i, j, a, b);
    pullUp(p, L, R);
}
 
long long sumQuery(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return 0;
    if(L >= i && R <= j) return evalSum(p, L, R);
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    long long ret = sumQuery(li, L, (L+R)/2, i, j)+sumQuery(ri, (L+R)/2+1, R, i, j);
    pullUp(p, L, R);
    return ret;
}
 
int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> ori[i];
    build(1, 0, N-1);
    for(int q = 0; q < Q; q++){
        int t, a, b; cin >> t >> a >> b; a--; b--;
        if(t == 1) update(1, 0, N-1, a, b, 1, 1-a);
        else cout << sumQuery(1, 0, N-1, a, b) << '\n';
    }
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
