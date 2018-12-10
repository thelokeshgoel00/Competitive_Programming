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

int Q, idx = 1, depths [100010], parents [20][100010];
pair<int, int> endpoints [100010];

void buildLCA(){
    for(int i = 1; i < 20; i++)
        parents[i][idx] = parents[i-1][parents[i-1][idx]];
}

int findLCA(int p, int q){
    if(depths[p] < depths[q]) swap(p, q);
    for(int i = 19; i > -1; i--)
        if(depths[p]-(1<<i) >= depths[q])
            p = parents[i][p];
    if(p == q) return p;
    for(int i = 19; i > -1; i--)
        if(parents[i][p] != parents[i][q]){
            p = parents[i][p];
            q = parents[i][q];
        }
    return parents[0][p];
}

int getDist(int p, int q){ return depths[p]+depths[q]-2*depths[findLCA(p, q)]; }

void testNewEndpoint(){
    int root = parents[19][idx];
    pair<int, pair<int, int>> best = mp(getDist(endpoints[root].f, endpoints[root].s), endpoints[root]);
    best = max(best, mp(getDist(endpoints[root].f, idx), mp(endpoints[root].f, idx)));
    best = max(best, mp(getDist(endpoints[root].s, idx), mp(endpoints[root].s, idx)));
    endpoints[root] = best.s;
}

int solveIt(int num){
    int root = parents[19][num];
    return max(getDist(num, endpoints[root].f), getDist(num, endpoints[root].s));
}

int main(){
    freopen("newbarn.in", "r", stdin); freopen("newbarn.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> Q;
    for(int qq = 0; qq < Q; qq++){
        char c; int num; cin >> c >> num;
        if(c == 'B'){
            if(num == -1){ parents[0][idx] = idx; depths[idx] = 0; endpoints[idx] = mp(idx, idx); }
            else{ parents[0][idx] = num; depths[idx] = depths[num]+1; }
            buildLCA(); testNewEndpoint();
            idx++;
        }
        else cout << solveIt(num) << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
