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


int N, M, idx = 1, trie [200010][27], counts [200010][27], endies [200010];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M; memset(trie, -1, sizeof(trie));
    for(int a = 0; a < N; a++){
        string s; cin >> s;
        int curr = 0;
        for(int i = 0; i < s.length(); i++){
            int letter = s[i]-'a'+1;
            if(trie[curr][letter] == -1) trie[curr][letter] = idx++;
            counts[curr][letter]++; curr = trie[curr][letter];
        }
        endies[curr]++;
    }
    for(int i = 0; i < idx; i++)
        for(int j = 1; j < 27; j++)
            counts[i][j] += counts[i][j-1];
    for(int a = 0; a < M; a++){
        string s; cin >> s;
        int curr = 0, ret = 0;
        for(int i = 0; i < s.length(); i++){
            int letter = s[i]-'a'+1;
            ret += counts[curr][letter-1];
            curr = trie[curr][letter];
            if(curr == -1) break;
            else ret += endies[curr];
        }
        cout << ret << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
