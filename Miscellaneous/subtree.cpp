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
long long M, down [100010], up [100010], pref [100010], suf [100010];
vector<int> adjacency [100010];
 
void dfsDown(int curr, int prevy){
    down[curr] = 1;
    for(int nexty : adjacency[curr]){
        if(nexty == prevy) continue;
        dfsDown(nexty, curr);
        down[curr] *= (down[nexty]+1)%M; down[curr] %= M;
    }
}
 
void dfsUp(int curr, int prevy){
    pref[0] = 1;
    for(int i = 0; i < adjacency[curr].size(); i++){
        int nexty = adjacency[curr][i]; pref[i+1] = pref[i];
        if(nexty == prevy) continue;
        pref[i+1] *= (down[nexty]+1)%M; pref[i+1] %= M;
    }
    suf[adjacency[curr].size()+1] = 1;
    for(int i = adjacency[curr].size()-1; i > -1; i--){
        int nexty = adjacency[curr][i]; suf[i+1] = suf[i+2];
        if(nexty == prevy) continue;
        suf[i+1] *= (down[nexty]+1)%M; suf[i+1] %= M;
    }
    for(int i = 0; i < adjacency[curr].size(); i++){
        int nexty = adjacency[curr][i];
        if(nexty == prevy) continue;
        up[nexty] = (((pref[i]*suf[i+2])%M)*((up[curr]+1)%M))%M;
        down[nexty] *= (up[nexty]+1)%M; down[nexty] %= M;
    }
    for(int nexty : adjacency[curr])
        if(nexty != prevy)
            dfsUp(nexty, curr);
}
 
int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        adjacency[a].pb(b); adjacency[b].pb(a);
    }
    dfsDown(1, 0); dfsUp(1, 0);
    for(int i = 1; i <= N; i++) cout << down[i] << '\n';
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
