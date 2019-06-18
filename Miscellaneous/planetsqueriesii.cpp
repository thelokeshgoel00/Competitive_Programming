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

int N, Q, cycleID = 0, tablex [200010][18], degree [200010], cycleNum [200010], cyclePos [200010], cycleSize [200010];
queue<int> process;

pair<int, pair<int, int>> distUntilCycle(int a){
    int ret = 0;
    for(int i = 17; i > -1; i--)
        if(cycleNum[tablex[a][i]] == -1){
            ret += (1<<i);
            a = tablex[a][i];
        }
    return mp(ret+1, mp(cycleNum[tablex[a][0]], cyclePos[tablex[a][0]]));
}

int solveIt(int a, int b){
    if(cycleNum[a] != -1 && cycleNum[b] == -1) return -1;
    if(cycleNum[a] != -1 && cycleNum[b] != -1){
        if(cycleNum[a] != cycleNum[b]) return -1;
        return (cyclePos[b]-cyclePos[a]+cycleSize[cycleNum[a]])%cycleSize[cycleNum[a]];
    }
    if(cycleNum[a] == -1 && cycleNum[b] == -1){
        pair<int, pair<int, int>> x = distUntilCycle(a), y = distUntilCycle(b);
        if(x.f < y.f || x.s.f != y.s.f) return -1;
        for(int i = 17; i > -1; i--)
            if((x.f-y.f)&(1<<i))
                a = tablex[a][i];
        if(a != b) return -1;
        return x.f-y.f;
    }
    pair<int, pair<int, int>> x = distUntilCycle(a);
    if(x.s.f != cycleNum[b]) return -1;
    return x.f+(cyclePos[b]-x.s.s+cycleSize[cycleNum[b]])%cycleSize[cycleNum[b]];
}

int main(){
    //freopen("leapfrog_ch_.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(6);
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> tablex[i][0]; cycleNum[i] = cyclePos[i] = -1;
        degree[tablex[i][0]]++;
    }
    for(int i = 1; i <= N; i++)
        if(degree[i] == 0)
            process.push(i);
    while(process.size() > 0){
        int curr = process.front(); process.pop();
        degree[tablex[curr][0]]--;
        if(degree[tablex[curr][0]] == 0) process.push(tablex[curr][0]);
    }
    for(int i = 1; i <= N; i++){
        if(degree[i] == 0 || cycleNum[i] != -1) continue;
        cycleNum[i] = cycleID; cyclePos[i] = 0; cycleSize[cycleID] = 1;
        for(int j = 1, curr = tablex[i][0]; curr != i; j++, curr = tablex[curr][0]){
            cycleNum[curr] = cycleID;
            cyclePos[curr] = j;
            cycleSize[cycleID]++;
        }
        cycleID++;
    }
    for(int j = 1; j < 18; j++)
        for(int i = 1; i <= N; i++)
            tablex[i][j] = tablex[tablex[i][j-1]][j-1];
    for(int i = 1; i <= Q; i++){
        int a, b; cin >> a >> b;
        cout << solveIt(a, b) << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
