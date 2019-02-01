/*
ID: vamaddu1
LANG: C++11
TASK: zoo
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

int N, C, dp [2][32][32], ret = 0;
vector<vector<bool>> fears [10010], loves [10010];

void resetIt(int curr){
    for(int i = 0; i < 32; i++)
        fill(dp[curr][i], dp[curr][i]+32, -MOD);
}

int calcSatisfied(int a, int mask){
    int num = 0;
    for(int i = 0; i < fears[a].size(); i++){
        bool add = false;
        for(int j = 0; j < 5; j++)
            if(((mask&(1<<j)) && loves[a][i][j]) || (!(mask&(1<<j)) && fears[a][i][j])){
                add = true;
                break;
            }
        num += add;
    }
    return num;
}

int main(){
    freopen("zoo.in", "r", stdin); freopen("zoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> C; resetIt(0);
    for(int a = 0; a < C; a++){
        int eo, fear, love; cin >> eo >> fear >> love; eo--;
        vector<bool> fof(5, false), lol(5, false);
        for(int i = 0; i < fear; i++){
            int x; cin >> x; x--;
            fof[(x+N-eo)%N] = true;
        }
        for(int i = 0; i < love; i++){
            int x; cin >> x; x--;
            lol[(x+N-eo)%N] = true;
        }
        fears[eo].pb(fof); loves[eo].pb(lol);
    }
    for(int orimask = 0; orimask < 32; orimask++){
        dp[0][orimask][orimask] = calcSatisfied(0, orimask);
        ret = max(ret, dp[0][orimask][orimask]);
    }
    for(int a = 0; a < N-1; a++){
        int curr = a&1, nexty = curr^1; resetIt(nexty);
        for(int mask = 0; mask < 32; mask++)
            for(int orimask = 0; orimask < 32; orimask++){
                if(dp[curr][mask][orimask] < 0) continue;
                if(a+5 < N){
                    dp[nexty][mask/2][orimask] = max(dp[nexty][mask/2][orimask], dp[curr][mask][orimask]+calcSatisfied(a+1, mask/2));
                    dp[nexty][mask/2+16][orimask] = max(dp[nexty][mask/2+16][orimask], dp[curr][mask][orimask]+calcSatisfied(a+1, mask/2+16));
                    ret = max(ret, max(dp[nexty][mask/2][orimask], dp[nexty][mask/2+16][orimask]));
                }
                else{
                    int nmask = mask/2;
                    if(orimask&(1<<((a+5)%N))) nmask += 16;
                    dp[nexty][nmask][orimask] = max(dp[nexty][nmask][orimask], dp[curr][mask][orimask]+calcSatisfied(a+1, nmask));
                    ret = max(ret, dp[nexty][nmask][orimask]);
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
