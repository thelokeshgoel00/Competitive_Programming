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
double lo = 0, hi = 1000000, ret;
vector<pair<int, pair<double, double>>> adjacency [1010];
bool used [1010];

bool testIt(double mult){
    double sum = 0; int numEdges = 0; fill(used, used+N, false); used[0] = true;
    priority_queue<pair<double, pair<int, int>>> pq;
    for(pair<int, pair<double, double>> e : adjacency[0]) pq.push(mp(e.s.f*mult-e.s.s, mp(0, e.f)));
    while(numEdges < N-1){
        if(pq.size() == 0) break;
        pair<double, pair<int, int>> now = pq.top(); pq.pop();
        if(used[now.s.f] && used[now.s.s]) continue;
        if(!used[now.s.f]){
            used[now.s.f] = true;
            for(pair<int, pair<double, double>> e : adjacency[now.s.f]) pq.push(mp(e.s.f*mult-e.s.s, mp(now.s.f, e.f)));
        }
        else if(!used[now.s.s]){
            used[now.s.s] = true;
            for(pair<int, pair<double, double>> e : adjacency[now.s.s]) pq.push(mp(e.s.f*mult-e.s.s, mp(now.s.s, e.f)));
        }
        sum += now.f; numEdges++;
    }
    return sum > -epsilon;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c, d; cin >> a >> b >> c >> d; a--; b--;
        adjacency[a].pb(mp(b, mp(c, d))); adjacency[b].pb(mp(a, mp(c, d)));
    }
    for(int iter = 0; iter < 50 && hi > lo+10.0*epsilon; iter++){
        double mid = (lo+hi)/2;
        if(testIt(mid)){ hi = mid; ret = mid; }
        else lo = mid;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
