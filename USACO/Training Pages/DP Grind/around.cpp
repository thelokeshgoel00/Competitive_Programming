/*
ID: vamaddu1
LANG: C++11
TASK: around
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

int N, M, arr [5010];
vector<int> adjacency [5010];
unordered_set<int> visited [5010];
queue<pair<pair<int, int>, int>> q;

int dist(int a, int b){
    if(arr[b] > arr[a]){
        if(arr[b]-arr[a] < 180) return arr[b]-arr[a];
        else return -(360-(arr[b]-arr[a]));
    }
    else{
        if(arr[a]-arr[b] < 180) return -(arr[a]-arr[b]);
        else return (360-(arr[a]-arr[b]));
    }
}

int main(){
    freopen("around.in", "r", stdin); freopen("around.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M; q.push(mp(mp(1, 0), 0));
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        adjacency[a].pb(b); adjacency[b].pb(a);
    }
    while(q.size() > 0){
        pair<pair<int, int>, int> now = q.front(); q.pop();
        if(visited[now.f.f].find(now.f.s) != visited[now.f.f].end()) continue;
        visited[now.f.f].insert(now.f.s);
        if(abs(now.f.s)%360 == 0 && now.f.s != 0 && now.f.f == 1){
            cout << now.s << '\n';
            return 0;
        }
        for(int nexty : adjacency[now.f.f]){
            int d = now.f.s+dist(now.f.f, nexty);
            if(visited[nexty].find(d) == visited[nexty].end())
              q.push(mp(mp(nexty, d), now.s+1));
        }
    }
    cout << "-1\n";
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
