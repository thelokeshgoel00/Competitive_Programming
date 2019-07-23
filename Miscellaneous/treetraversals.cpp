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
 
int N, retidx = 0, preorder [100010], inorder [100010], postorder [100010], places [100010];
 
void recurseIt(int inidx, int preidx, int sz){
    int rootidx = places[preorder[preidx]]-inidx;
    if(rootidx != 0) recurseIt(inidx, preidx+1, rootidx);
    if(rootidx != sz-1) recurseIt(inidx+rootidx+1, preidx+rootidx+1, sz-rootidx-1);
    postorder[retidx++] = preorder[preidx];
}
 
int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> preorder[i];
    for(int i = 0; i < N; i++){ cin >> inorder[i]; places[inorder[i]] = i; }
    recurseIt(0, 0, N);
    for(int i = 0; i < N; i++) cout << postorder[i] << (i == N-1 ? '\n' : ' ');
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
