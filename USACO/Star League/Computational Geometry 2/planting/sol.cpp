/*
ID: vamaddu1
LANG: C++11
TASK: planting
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
    int freq, sum, total;
    Node(){ freq = sum = total = 0; }
};

int N;
pair<pair<int, int>, pair<int, int>> rectangles [1010], events [2010];
vector<int> uniques;
unordered_map<int, int> mappy;
Node tree [8010];
long long ret = 0;

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        tree[p].total = uniques[L+1]-uniques[L];
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].total = tree[li].total+tree[ri].total;
}

void update(int p, int L, int R, int i, int j, int val){
    if(i > R || j < L) return;
    if(L >= i && R <= j){
        tree[p].freq += val;
        return;
    }
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
    tree[p].sum = (tree[li].freq ? tree[li].total : tree[li].sum)+(tree[ri].freq ? tree[ri].total : tree[ri].sum);
}

int main(){
    //freopen("planting.in", "r", stdin); freopen("planting.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b, c, d; cin >> a >> b >> c >> d; swap(b, d);
        uniques.pb(b); uniques.pb(d);
        rectangles[i] = mp(mp(a, b), mp(c, d));
        events[2*i] = mp(mp(a, 1), mp(b, d));
        events[2*i+1] = mp(mp(c, -1), mp(b, d));
    }
    sort(uniques.begin(), uniques.end()); sort(events, events+2*N);
    uniques.resize(unique(uniques.begin(), uniques.end())-uniques.begin());
    build(1, 0, uniques.size()-1);
    for(int i = 0; i < uniques.size(); i++) mappy[uniques[i]] = i;
    for(int i = 0, lasty = 0; i < 2*N; lasty = events[i].f.f, i++){
        ret += (long long)(events[i].f.f-lasty)*(long long)(tree[1].freq ? tree[1].total : tree[1].sum);
        int lo = mappy[events[i].s.f], hi = mappy[events[i].s.s]-1;
        update(1, 0, uniques.size()-1, lo, hi, events[i].f.s);
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
