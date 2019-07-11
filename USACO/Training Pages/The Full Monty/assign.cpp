/*
ID: vamaddu1
LANG: C++11
TASK: assign
*/

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

int N, limate [160], rimate [160];
long long costs [160][160], ret = 0;

void generateSol(){
    for(int i = 0; i < N; i++) limate[i] = rimate[i] = -1;
    vector<long long> u(N), v(N);
    for(int i = 0; i < N; i++){
        u[i] = costs[i][0];
        for(int j = 1; j < N; j++) u[i] = min(u[i], costs[i][j]);
    }
    for(int j = 0; j < N; j++){
        v[j] = costs[0][j]-u[0];
        for(int i = 1; i < N; i++) v[j] = min(v[j], costs[i][j]-u[i]);
    }
    int mated = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(rimate[j] != -1) continue;
            if(costs[i][j] == u[i]+v[j]){
                limate[i] = j; rimate[j] = i;
                mated++; break;
            }
        }
    vector<long long> dists(N); vector<int> parents(N); vector<bool> seen(N);
    while(mated < N){
        int s = 0, j = -1;
        while(limate[s] != -1) s++;
        for(int i = 0; i < N; i++){
            parents[i] = -1; seen[i] = false;
            dists[i] = costs[s][i]-u[s]-v[i];
        }
        while(true){
            j = -1;
            for(int i = 0; i < N; i++){
                if(seen[i]) continue;
                if(j == -1 || dists[i] < dists[j]) j = i;
            }
            seen[j] = true;
            if(rimate[j] == -1) break;
            int i = rimate[j];
            for(int k = 0; k < N; k++){
                if(seen[k]) continue;
                long long newDist = dists[j]+costs[i][k]-u[i]-v[k];
                if(dists[k] > newDist){
                    dists[k] = newDist;
                    parents[k] = j;
                }
            }
        }
        for(int k = 0; k < N; k++){
            if(k == j || !seen[k]) continue;
            int i = rimate[k];
            v[k] += dists[k]-dists[j];
            u[i] -= dists[k]-dists[j];
        }
        u[s] += dists[j];
        while(parents[j] > -1) {
            int p = parents[j];
            rimate[j] = rimate[p];
            limate[rimate[j]] = j;
            j = p;
        }
        rimate[j] = s; limate[s] = j;
        mated++;
    }
}

int main(){
    freopen("assign.in", "r", stdin); freopen("assign.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> costs[i][j];
    generateSol();
    for(int i = 0; i < N; i++) ret += costs[i][limate[i]];
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
