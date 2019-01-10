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

struct Node{
    int nexty, frequent, reach;
    Node(){ nexty = -1; frequent = -1; reach = MOD; }
};

int N, M, idx = 1, curr, lastWord, maxReach, edges, ret;
Node trie [1000010][26];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s; cin >> s; curr = 0;
        for(int j = 0; j < s.length(); j++){
            int letter = s[j]-'a';
            if(trie[curr][letter].nexty == -1){
                trie[curr][letter].nexty = idx++;
                trie[curr][letter].frequent = i;
                trie[curr][letter].reach = s.length();
            }
            curr = trie[curr][letter].nexty;
        }
    }
    for(int i = 0; i < M; i++){
        string s; cin >> s;
        curr = 0; lastWord = -1; maxReach = MOD; edges = ret = 0;
        for(int j = 0; j < s.length(); j++){
            int letter = s[j]-'a';
            if(lastWord != trie[curr][letter].frequent){
                ret += min(edges, maxReach-j+1)+1; edges = 0;
                lastWord = trie[curr][letter].frequent;
                maxReach = trie[curr][letter].reach;
            }
            else edges++;
            curr = trie[curr][letter].nexty;
            if(curr == -1){
                ret += s.length()-j-1;
                break;
            }
        }
        if(edges > 0) ret += min(edges, maxReach-(int)s.length()+1);
        cout << ret << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
