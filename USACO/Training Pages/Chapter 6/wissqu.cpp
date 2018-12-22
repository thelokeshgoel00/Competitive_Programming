/*
ID: vamaddu1
PROG: wissqu
LANG: C++11
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

int remain [] = {3, 3, 3, 4, 3}, grid [4][4], ret = 0;
bool done [4][4], seen [16];
pair<char, pair<int, int>> instructions [16];

bool inBounds(int x, int y){ return min(x, y) > -1 && max(x, y) < 4; }

bool checkIt(int x, int y, int k){
    if(done[x][y]) return false;
    for(int a = -1; a < 2; a++)
        for(int b = -1; b < 2; b++)
            if(inBounds(x+a, y+b) && grid[x+a][y+b] == k)
                return false;
    return true;
}

bool recurseIt(int curr, int letter, int x, int y){
    bool found = false; int temp = grid[x][y];
    grid[x][y] = letter; done[x][y] = true; remain[letter]--;
    if(curr == 15){
        found = true; ret++;
        if(!seen[curr]){
            instructions[curr] = mp(char('A'+letter), mp(x+1, y+1));
            seen[curr] = true;
        }
    }
    for(int k = 0; k < 5; k++){
        if(remain[k] == 0) continue;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++){
                if(!checkIt(i, j, k)) continue;
                bool good = recurseIt(curr+1, k, i, j);
                if(good && !seen[curr]){
                    instructions[curr] = mp(char('A'+letter), mp(x+1, y+1));
                    seen[curr] = true; found = true;
                }
            }
    }
    grid[x][y] = temp; done[x][y] = false; remain[letter]++;
    return found;
}

int main(){
    freopen("wissqu.in", "r", stdin); freopen("wissqu.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            char c; cin >> c;
            grid[i][j] = c-'A';
        }
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(checkIt(i, j, 3))
                recurseIt(0, 3, i, j);
    for(int i = 0; i < 16; i++) cout << instructions[i].f << ' ' << instructions[i].s.f << ' ' << instructions[i].s.s << '\n';
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
