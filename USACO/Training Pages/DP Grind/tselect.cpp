/*
ID: vamaddu1
LANG: C++11
TASK: tselect
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

int N, X, arr [510], dp [510][2][510], aux [2][510], ret = -1;
vector<int> adjacency [510];

void solveIt(int i){
    int add = (i != 0);
    dp[i][0][0] = 0; dp[i][1][0] = arr[i];
    for(int a = 1; a < N; a++) dp[i][0][a] = dp[i][1][a] = -MOD;
    for(int j : adjacency[i]){
        solveIt(j); memcpy(aux, dp[i], sizeof(dp[i]));
        for(int a = 0; a < N; a++)
            for(int b = 0; a+b < N; b++){
                dp[i][0][a+b] = max(dp[i][0][a+b], aux[0][a]+max(dp[j][0][b], dp[j][1][b]));
                dp[i][1][a+b] = max(dp[i][1][a+b], aux[1][a]+dp[j][0][b]);
                if(a+b+add < N) dp[i][1][a+b+add] = max(dp[i][1][a+b+add], aux[1][a]+dp[j][1][b]);
            }
    }
}

int main(){
    freopen("tselect.in", "r", stdin); freopen("tselect.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> X;
    for(int i = 1; i <= N; i++){
        int p; cin >> arr[i] >> p;
        adjacency[p].pb(i);
    }
    solveIt(0);
    for(int i = 0; i < N; i++)
        if(dp[0][0][i] >= X || dp[0][1][i] >= X)
            ret = i;
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
