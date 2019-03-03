/*
ID: vamaddu1
LANG: C++11
TASK: fliptile
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

int N, M, ori [20][20], base [20], solution [20], grid [20], trying [20], best = MOD;

void flipIt(int x, int y){
	grid[x] ^= (1<<y);
	if(x > 0) grid[x-1] ^= (1<<y);
	if(y > 0) grid[x] ^= (1<<(y-1));
	if(x < N-1) grid[x+1] ^= (1<<y);
	if(y < M-1) grid[x] ^= (1<<(y+1));
}

int checkIt(int mask){
    int cnt = 0;
    for(int i = 0; i < N; i++){ grid[i] = base[i]; trying[i] = 0; }
    for(int j = 0; j < M; j++)
        if(mask&(1<<j)){
            flipIt(0, j);
            cnt++;
        }
    trying[0] = mask;
    for(int i = 1; i < N; i++)
        for(int j = 0; j < M; j++)
            if(grid[i-1]&(1<<j)){
                flipIt(i, j); cnt++;
                trying[i] ^= (1<<j);
            }
    if(grid[N-1] != 0) return MOD;
    return cnt;
}

void recurseIt(int curr, int mask){
    if(curr == M){
        int val = checkIt(mask);
        if(val >= best) return;
        else best = val;
        for(int i = 0; i < N; i++) solution[i] = trying[i];
        return;
    }
    recurseIt(curr+1, mask);
    recurseIt(curr+1, mask+(1<<curr));
}

int main(){
    freopen("fliptile.in", "r", stdin); freopen("fliptile.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> ori[i][j];
    for(int i = 0; i < N; i++)
        for(int j = M-1; j > -1; j--)
            base[i] = base[i]*2+ori[i][j];
    recurseIt(0, 0);
    if(best == MOD) cout << "IMPOSSIBLE\n";
    else{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M-1; j++) cout << ((solution[i]&(1<<j)) > 0) << ' ';
            cout << ((solution[i]&(1<<(M-1))) > 0) << '\n';
        }
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
