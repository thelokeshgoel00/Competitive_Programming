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

int N, idx = 0;
double arr [1010];
unordered_map<string, int> nameToIdx;
vector<int> children [1010];
pair<int, double> dp [1010][2];
bool visited [1010][2];

pair<int, double> solveIt(int curr, int taken){
    if(visited[curr][taken]) return dp[curr][taken];
    visited[curr][taken] = true;
    pair<int, double> sum = mp(0, 0);
    for(int nexty : children[curr]){
        pair<int, double> lol = solveIt(nexty, 0);
        sum.f += lol.f; sum.s += lol.s;
    }
    dp[curr][taken] = sum;
    if(!taken){
        for(int nexty : children[curr]){
            pair<int, double> lol = solveIt(nexty, 1); lol.s += min(arr[curr], arr[nexty]);
            pair<int, double> oof = mp(sum.f, sum.s);
            oof.f -= solveIt(nexty, 0).f; oof.s -= solveIt(nexty, 0).s;
            oof.f += lol.f+1; oof.s += lol.s;
            dp[curr][taken] = max(dp[curr][taken], oof);
        }
    }
    return dp[curr][taken];
}

int main(){
    //freopen("moofest.in", "r", stdin); freopen("moofest.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N; nameToIdx["CEO"] = idx++;
    for(int i = 1; i <= N; i++){
        string s, t; double x; cin >> s >> x >> t;
        if(nameToIdx.find(s) == nameToIdx.end()) nameToIdx[s] = idx++;
        if(nameToIdx.find(t) == nameToIdx.end()) nameToIdx[t] = idx++;
        int a = nameToIdx[s], b = nameToIdx[t];
        children[b].pb(a); arr[a] = x;
    }
    cout << solveIt(0, 1).f << ' ' << solveIt(0, 1).s/solveIt(0, 1).f << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
