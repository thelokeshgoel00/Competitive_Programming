#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5e18
#define MOD 1000000007
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
int kase, N, subtreeSizes [100010], dists [100010], prevs [100010];
vector<int> adjacency [100010], centers [2];
vector<long long> vals [2];
long long powa [200010];
 
void resetIt(){ for(int i = 1; i <= N; i++) adjacency[i] = vector<int>(); }
 
int getFarthest(int st){
    for(int i = 1; i <= N; i++) dists[i] = prevs[i] = -1; dists[st] = 0;
    queue<int> q; q.push(st);
    while(q.size() > 0){
        int curr = q.front(); q.pop();
        for(int nexty : adjacency[curr])
            if(dists[nexty] == -1){
                dists[nexty] = dists[curr]+1; prevs[nexty] = curr;
                q.push(nexty);
            }
    }
    return max_element(dists+1, dists+N+1)-dists;
}
 
void getCenters(int k){
    int endy = getFarthest(getFarthest(1)), diameter = dists[endy];
    //cout << "HAI " << diameter << ' ' << dists[1] << ' ' << dists[2] << ' ' << dists[3] << endl;
    for(int i = diameter, j = endy; i > 0; i--, j = prevs[j])
        if(i == diameter/2 || i == (diameter+1)/2)
            centers[k].pb(j);
}
 
long long dfs(int curr, int prevy){
    subtreeSizes[curr] = 1;
    if(adjacency[curr].size() == 1 && prevy) return 2;
    long long hashy = 0; vector<pair<long long, int>> children;
    for(int nexty : adjacency[curr]){
        if(nexty == prevy) continue;
        children.pb(mp(dfs(nexty, curr), subtreeSizes[nexty]));
        subtreeSizes[curr] += subtreeSizes[nexty];
    }
    sort(children.begin(), children.end());
    for(pair<long long, int> lol : children){
        hashy *= powa[lol.s*2]; hashy %= MOD;
        hashy += lol.f; hashy %= MOD;
    }
    hashy *= 2; hashy %= MOD; hashy += powa[2*subtreeSizes[curr]-1]; hashy %= MOD;
    return hashy;
}
 
int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    powa[0] = 1; for(int i = 1; i < 200010; i++) powa[i] = (powa[i-1]*2)%MOD;
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N;
        for(int k = 0; k < 2; k++){
            resetIt(); centers[k] = vector<int>(); vals[k] = vector<long long>();
            for(int i = 1; i < N; i++){
                int a, b; cin >> a >> b;
                adjacency[a].pb(b); adjacency[b].pb(a);
            }
            getCenters(k);
            for(int x : centers[k]) vals[k].pb(dfs(x, 0));
        }
        //cout << centers[0].size() << ' ' << centers[1].size() << '\n';
        if(centers[0].size() != centers[1].size()) cout << "NO\n";
        else if(centers[0].size() >= 1 && vals[0][0] == vals[1][0]) cout << "YES\n";
        else if(centers[0].size() >= 2 && vals[0][0] == vals[1][1]) cout << "YES\n";
        else cout << "NO\n";
        assert(centers[0].size() >= 1 && centers[0].size() <= 2);
        assert(centers[1].size() >= 1 && centers[1].size() <= 2);
    }
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
