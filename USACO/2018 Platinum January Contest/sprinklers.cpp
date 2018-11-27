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

int N, idx = 0;
long long heights [100010], mini [100010], maxi, ret = 0;
vector<pair<long long, long long>> localMaxi;

int main(){
    freopen("sprinklers.in", "r", stdin); freopen("sprinklers.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        heights[x] = y;
    }
    mini[0] = heights[0]; maxi = heights[N-1];
    for(int i = 1; i < N; i++) mini[i] = min(mini[i-1], heights[i]);
    localMaxi.pb(mp(N-1, maxi));
    for(int i = N-2; i > -1; i--)
        if(heights[i] > maxi){
            maxi = heights[i];
            localMaxi.pb(mp(i, maxi));
        }
    reverse(localMaxi.begin(), localMaxi.end());
    for(int i = 0; i < N-1; i++){
        while(idx < localMaxi.size() && localMaxi[idx].f <= i) idx++;
        if(idx == localMaxi.size()) break;
        for(int j = idx; j < localMaxi.size(); j++){
            long long h = localMaxi[j].s-mini[i], range = localMaxi[j].f-i;
            if(h <= 0) break;
            ret = (ret+(range*h*(h+1)/2)%MOD)%MOD;
            if(j > idx){
                long long over = localMaxi[j-1].f-i;
                ret = (ret-(over*h*(h+1)/2)%MOD+MOD)%MOD;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
