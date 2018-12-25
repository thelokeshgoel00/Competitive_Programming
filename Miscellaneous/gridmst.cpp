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

int N, indices [100010], curr [100010][3], parents [100010], heights [100010], ret = 0;
pair<int, int> ori [100010];
map<int, pair<int, int>> mappy;
vector<pair<int, pair<int, int>>> edges;

void update(int a, pair<int, int> b){
    auto it = mappy.lb(a);
    if(it != mappy.end() && it->s <= b) return;
    mappy[a] =  b; it = mappy.find(a);
    while(it != mappy.begin() && prev(it)->s >= b) mappy.erase(prev(it));
}

pair<int, int> query(int y){
    auto it = mappy.ub(y);
    if(it == mappy.end()) return mp(MOD, MOD);
    return it->s;
}

void addEdges(){
    sort(indices, indices+N, [](int a, int b){ return curr[a][0] > curr[b][0]; });
    mappy = map<int, pair<int, int>>();
    int nexty = 0;
    for(int i = 0; i < N; i++){
        int x = indices[i];
        while(nexty < N && curr[indices[nexty]][0] >= curr[x][0]){
            int b = indices[nexty++];
            update(curr[b][1], mp(curr[b][2], b));
        }
        pair<int, int> t = query(curr[x][1]);
        if(t.s != MOD) edges.pb(mp(t.f-curr[x][2], mp(x, t.s)));
    }
}

int findParent(int x){
    if(x == parents[x]) return x;
    parents[x] = findParent(parents[x]);
    return parents[x];
}

bool combine(int x, int y){
    int a = findParent(x); int b = findParent(y);
    if(a == b) return false;
    if(heights[b] < heights[a]) parents[b] = a;
    else if(heights[a] < heights[b]) parents[a] = b;
    else{
        parents[b] = a;
        heights[a]++;
    }
    return true;
}

int main(){
    //freopen("fence4.in", "r", stdin); freopen("fence4.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ori[i].f >> ori[i].s;
        indices[i] = i; parents[i] = i; heights[i] = 0;
    }
    sort(indices, indices+N, [](int a, int b){ return ori[a] < ori[b]; });
    for(int i = 0; i < N-1; i++)
        if(ori[indices[i]] == ori[indices[i+1]])
            edges.pb(mp(0, mp(indices[i], indices[i+1])));
    for(int a = 0; a < 4; a++){
        for(int i = 0; i < N; i++) curr[i][2] = ori[i].f+ori[i].s;
        for(int i = 0; i < N; i++){
            curr[i][0] = ori[i].f-ori[i].s;
            curr[i][1] = ori[i].s;
        }
        addEdges();
        for(int i = 0; i < N; i++){
            curr[i][0] = ori[i].f;
            curr[i][1] = ori[i].s-ori[i].f;
        }
        addEdges();
        for(int i = 0; i < N; i++) ori[i] = mp(ori[i].s, -ori[i].f);
    }
    sort(edges.begin(), edges.end());
    for(int i = 0, used = 0; used < N-1; i++){
        //cout << edges[i].s.f << ' ' << edges[i].s.s << ' ' << edges[i].f << endl;
        if(!combine(edges[i].s.f, edges[i].s.s)) continue;
        ret += edges[i].f; used++;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
