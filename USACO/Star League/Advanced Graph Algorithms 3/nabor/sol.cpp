/*
ID: vamaddu1
LANG: C++11
TASK: nabor
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

int N;
long long C;
pair<pair<long long, long long>, int> points [100010];
set<pair<long long, int>> process;
vector<int> adjacency [100010];
bool visited [100010];
pair<int, int> ret = mp(0, 0);

int main(){
    freopen("nabor.in", "r", stdin); freopen("nabor.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        long long x, y; cin >> x >> y;
        points[i].f = mp(x+y, x-y);
        points[i].s = i;
    }
    sort(points, points+N);
    for(int i = 0, idx = 0; i < N; i++){
        //cout << points[i].f.f << ' ' << points[i].f.s << endl;
        while(points[idx].f.f+C < points[i].f.f){
            process.erase(process.find(mp(points[idx].f.s, points[idx].s)));
            idx++;
        }
        auto it = process.lb(mp(points[i].f.s, 0));
        if(it != process.end() && points[i].f.s+C >= (*it).f){
            int other = (*it).s;
            adjacency[points[i].s].pb(other); adjacency[other].pb(points[i].s);
        }
        if(i > idx && it != process.begin()){
            it--;
            if(points[i].f.s-C <= (*it).f){
                int other = (*it).s;
                adjacency[points[i].s].pb(other); adjacency[other].pb(points[i].s);
            }
        }
        process.insert(mp(points[i].f.s, points[i].s));
    }
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        int cnt = 1; queue<int> q; visited[i] = true; q.push(i);
        while(q.size() > 0){
            int now = q.front(); q.pop();
            //cout << i << ' ' << now << endl;
            for(int nexty : adjacency[now])
                if(!visited[nexty]){
                    visited[nexty] = true; cnt++;
                    q.push(nexty);
                }
        }
        ret.f++; ret.s = max(ret.s, cnt);
    }
    cout << ret.f << ' ' << ret.s << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
