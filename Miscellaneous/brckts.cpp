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
    int opening, closing;
    Node(){ opening = closing = 0; }
};

int kase = 10, N, M;
string s;
Node tree [120010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        if(s[L] == '('){ tree[p].opening = 1; tree[p].closing = 0; }
        else{ tree[p].opening = 0; tree[p].closing = 1; }
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    int completes = min(tree[li].opening, tree[ri].closing);
    tree[p].opening = tree[li].opening+tree[ri].opening-completes;
    tree[p].closing = tree[li].closing+tree[ri].closing-completes;
}

void update(int p, int L, int R, int pos){
    if(L == R){
        if(s[L] == ')'){ s[L] = '('; tree[p].opening = 1; tree[p].closing = 0; }
        else{ s[L] = ')'; tree[p].opening = 0; tree[p].closing = 1; }
        return;
    }
    int li = left(p), ri = right(p);
    if(pos <= (L+R)/2) update(li, L, (L+R)/2, pos);
    else update(ri, (L+R)/2+1, R, pos);
    int completes = min(tree[li].opening, tree[ri].closing);
    tree[p].opening = tree[li].opening+tree[ri].opening-completes;
    tree[p].closing = tree[li].closing+tree[ri].closing-completes;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    for(int kk = 1; kk <= kase; kk++){
        cin >> N >> s >> M;
        build(1, 0, N-1);
        cout << "Test " << kk << ":\n";
        for(int m = 0; m < M; m++){
            int x; cin >> x;
            if(x == 0) cout << (max(tree[1].opening, tree[1].closing) == 0 ? "YES" : "NO") << '\n';
            else update(1, 0, N-1, x-1);
        }
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
