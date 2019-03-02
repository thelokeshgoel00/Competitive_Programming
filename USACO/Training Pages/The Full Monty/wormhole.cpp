/*
ID: vamaddu1
PROG: wormhole2
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

int F, N, M, W, dists [510];
vector<pair<pair<int, int>, int>> edges;
bool ok;

int main(){
    freopen("wormhole2.in", "r", stdin); freopen("wormhole2.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> F;
    for(int ff = 1; ff <= F; ff++){
        cin >> N >> M >> W; fill(dists+1, dists+N+1, 0);
        edges = vector<pair<pair<int, int>, int>>(); ok = false;
        for(int i = 0; i < M; i++){
            int a, b, c; cin >> a >> b >> c;
            edges.pb(mp(mp(a, b), c)); edges.pb(mp(mp(b, a), c));
        }
        for(int i = 0; i < W; i++){
            int a, b, c; cin >> a >> b >> c;
            edges.pb(mp(mp(a, b), -c));
        }
        for(int a = 0; a < N; a++)
            for(pair<pair<int, int>, int> edge : edges)
                dists[edge.f.s] = min(dists[edge.f.s], dists[edge.f.f]+edge.s);
        for(pair<pair<int, int>, int> edge : edges)
            if(dists[edge.f.s] > dists[edge.f.f]+edge.s)
                ok = true;
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
