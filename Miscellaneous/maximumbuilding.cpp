#define __USE_MINGW_ANSI_STDIO 0

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

struct DSU{
    int parents [1010], heights [1010], compSizes [1010];
    DSU(){ for(int i = 0; i < 1010; i++){ parents[i] = -1; compSizes[i] = 1; } }
    int findParent(int x){
        if(x == parents[x]) return x;
        parents[x] = findParent(parents[x]);
        return parents[x];
    }

    bool combine(int x, int y){
        int a = findParent(x); int b = findParent(y);
        if(a == b) return false;
        if(heights[b] < heights[a]){
            parents[b] = a;
            compSizes[a] += compSizes[b];
        }
        else if(heights[a] < heights[b]){
            parents[a] = b;
            compSizes[b] += compSizes[a];
        }
        else{
            parents[b] = a; heights[a]++;
            compSizes[a] += compSizes[b];
        }
        return true;
    }
};

int N, M, lastSeen [1010], ret = 0;
char grid [1010][1010];
DSU dsu;

void processCol(int j){
    vector<int> nexts [1010];
    for(int i = 0; i < N; i++) nexts[lastSeen[i]-j].pb(i);
    dsu = DSU();
    for(int i = M; i > 0; i--)
        for(int a : nexts[i]){
            dsu.parents[a] = a;
            if(a > 0 && dsu.parents[a-1] != -1) dsu.combine(a-1, a);
            if(a < N-1 && dsu.parents[a+1] != -1) dsu.combine(a, a+1);
            ret = max(ret, i*dsu.compSizes[dsu.findParent(a)]);
        }
}

int main(){
    //freopen("leapfrog_ch_.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 0; i < N; i++){ cin >> grid[i]; lastSeen[i] = M; }
    for(int j = M-1; j > -1; j--){
        for(int i = 0; i < N; i++)
            if(grid[i][j] == '*')
                lastSeen[i] = j;
        processCol(j);
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
