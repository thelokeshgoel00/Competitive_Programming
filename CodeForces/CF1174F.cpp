#define __USE_MINGW_ANSI_STDIO 0
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

int N, parents [200010], depths [200010], depthx, subtreeSizes [200010], ret = -1;
vector<int> adjacency [200010];
bool visited [200010];

void predfs(int curr, int prevy){
    for(int nexty : adjacency[curr]){
        if(nexty == prevy) continue;
        depths[nexty] = depths[curr]+1;
        parents[nexty] = curr;
        predfs(nexty, curr);
    }
}

int askDist(int curr){
    cout << "d " << curr << endl;
    int x; cin >> x;
    return x;
}

int askSecond(int curr){
    cout << "s " << curr << endl;
    int x; cin >> x;
    return x;
}

void findSubtreeSizes(int curr, int prevy){
    subtreeSizes[curr] = 1;
    for(int nexty : adjacency[curr]){
        if(visited[nexty] || nexty == prevy) continue;
        findSubtreeSizes(nexty, curr);
        subtreeSizes[curr] += subtreeSizes[nexty];
    }
}

int getCentroid(int curr){
    findSubtreeSizes(curr, 0);
    int sz = subtreeSizes[curr], prevy = 0;
    while(true){
        pair<int, int> maxi = mp(0, 0);
        for(int nexty : adjacency[curr]){
            if(visited[nexty] || nexty == prevy) continue;
            maxi = max(maxi, mp(subtreeSizes[nexty], nexty));
        }
        if(maxi.first*2 > sz){ prevy = curr; curr = maxi.second; }
        else return curr;
    }
    return -1;
}

void solveIt(int curr){
    curr = getCentroid(curr); assert(curr > 0); visited[curr] = true;
    int dist = askDist(curr);
    if(dist == 0){ ret = curr; return; }
    if(depths[curr]+dist == depthx) solveIt(askSecond(curr));
    else solveIt(parents[curr]);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        adjacency[a].pb(b); adjacency[b].pb(a);
    }
    predfs(1, 0); depthx = askDist(1);
    solveIt(1); assert(ret > 0);
    cout << "! " << ret << endl;
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
