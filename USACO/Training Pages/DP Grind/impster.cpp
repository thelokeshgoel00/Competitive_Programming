/*
ID: vamaddu1
LANG: C++11
TASK: impster
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
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int B, E, arr [110], dists [1<<16];
queue<int> q;
pair<int, pair<int, int>> ret = mp(MOD, mp(MOD, MOD));

string getBinary(int now){
    string temp = "";
    for(int i = 0; i < B; i++){
        char c = char('0'+(now%2));
        temp = c+temp; now = now/2;
    }
    return temp;
}

int main(){
    freopen("impster.in", "r", stdin); freopen("impster.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(0);
    cin >> B >> E; memset(dists, 63, sizeof(dists));
    for(int i = 0; i <= E; i++){
        string s; cin >> s;
        for(int j = 0; j < B; j++) arr[i] = 2*arr[i]+(s[j]-'0');
        if(i != 0){ dists[arr[i]] = 0; q.push(arr[i]); }
    }
    while(q.size() > 0){
        int now = q.front(); q.pop();
        ret = min(ret, mp(__builtin_popcount(now^arr[0]), mp(dists[now], now)));
        for(int i = 1; i <= E; i++){
            int nexty = now^arr[i];
            if(dists[nexty] > dists[now]+1){
                dists[nexty] = dists[now]+1;
                q.push(nexty);
            }
        }
    }
    if(ret.s.f == 0) ret.s.f = 2;
    cout << ret.s.f << '\n' << getBinary(ret.s.s) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
