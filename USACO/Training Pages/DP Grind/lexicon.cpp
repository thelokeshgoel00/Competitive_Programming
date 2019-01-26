/*
ID: vamaddu1
LANG: C++11
TASK: lexicon
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

int W, L, dp [1610], nexts [1610][26];
string text, words [1010];

int main(){
    freopen("lexicon.in", "r", stdin); freopen("lexicon.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> W >> L >> text; text = "#"+text;
    for(int i = 0; i < W; i++) cin >> words[i];
    for(int j = 0; j < 26; j++) nexts[L][j] = -1;
    for(int i = L-1; i > -1; i--){
        for(int j = 0; j < 26; j++) nexts[i][j] = nexts[i+1][j];
        nexts[i][text[i+1]-'a'] = i+1; dp[i+1] = MOD;
    }
    for(int i = 0; i <= L; i++){
        for(int j = 0; j < i; j++) dp[i] = min(dp[i], dp[j]+i-j);
        for(int j = 0; j < W; j++){
            bool ok = true; int curr = i;
            for(int k = 0; k < words[j].length(); k++){
                if(nexts[curr][words[j][k]-'a'] == -1){
                    ok = false;
                    break;
                }
                curr = nexts[curr][words[j][k]-'a'];
            }
            if(ok) dp[curr] = min(dp[curr], dp[i]+curr-i-(int)words[j].length());
        }
    }
    cout << dp[L] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
