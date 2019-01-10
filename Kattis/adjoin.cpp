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

int N, M;
vector<int> adjacency [100010], diameters;
bool visited [100010];

pair<int, int> getFurthest(int start){
    queue<int> q; q.push(start); visited[start] = true;
    unordered_map<int, int> dists; dists[start] = 0;
    pair<int, int> best = mp(0, start);
    while(q.size() > 0){
        int curr = q.front(); q.pop();
        for(int nexty : adjacency[curr])
            if(dists.count(nexty) == 0){
                q.push(nexty); visited[nexty] = true;
                dists[nexty] = dists[curr]+1;
                best = max(best, mp(dists[nexty], nexty));
            }
    }
    return best;
}

int getDiameter(int curr){ return getFurthest(getFurthest(curr).s).f; }

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        adjacency[a].pb(b); adjacency[b].pb(a);
    }
    for(int i = 0; i < N; i++)
        if(!visited[i])
            diameters.pb(getDiameter(i));
    sort(diameters.begin(), diameters.end());
    for(int i = diameters.size()-2; i > -1; i--)
        diameters[i] = max((diameters[i+1]+1)/2+(diameters[i]+1)/2+1,
                           max(diameters[i], diameters[i+1]));
    cout << diameters[0] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
