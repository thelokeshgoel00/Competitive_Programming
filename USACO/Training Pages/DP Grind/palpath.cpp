/*
ID: vamaddu1
LANG: C++11
TASK: palpath
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

int N, L, grid [25][25], dx [] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy [] = {0, -1, 0, 1, 1, -1, 1, -1};
int dp [2][25][25][25][25], ret = 0;

bool inBounds(int x, int y){ return min(x, y) > -1 && max(x, y) < N; }

void resetIt(int nlen){
    for(int a = 0; a < N; a++)
    for(int b = 0; b < N; b++)
        for(int c = 0; c < N; c++)
        for(int d = 0; d < N; d++)
            dp[nlen][a][b][c][d] = 0;
}

int main(){
    freopen("palpath.in", "r", stdin); freopen("palpath.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> L;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];
    if(L%2 == 0){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 0; k < 8; k++){
                    int nr = i+dx[k], nc = j+dy[k];
                    if(inBounds(nr, nc) && grid[i][j] == grid[nr][nc])
                        dp[1][i][j][nr][nc] = 1;
                }
        L = L/2;
    }
    else{
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dp[1][i][j][i][j] = 1;
        L = (L+1)/2;
    }
    for(int len = 1; len < L; len++){
        int clen = len&1, nlen = clen^1; resetIt(nlen);
        for(int a = 0; a < N; a++)
        for(int b = 0; b < N; b++)
            for(int c = 0; c < N; c++)
            for(int d = 0; d < N; d++)
                    for(int i = 0; i < 8; i++)
                        for(int j = 0; j < 8; j++){
                            int nr1 = a+dx[i], nc1 = b+dy[i];
                            int nr2 = c+dx[j], nc2 = d+dy[j];
                            if(!inBounds(nr1, nc1) || !inBounds(nr2, nc2)) continue;
                            if(grid[nr1][nc1] == grid[nr2][nc2])
                                dp[nlen][nr1][nc1][nr2][nc2] += dp[clen][a][b][c][d];
                        }
    }
    for(int a = 0; a < N; a++)
        for(int b = 0; b < N; b++)
            for(int c = 0; c < N; c++)
                for(int d = 0; d < N; d++)
                    ret += dp[L&1][a][b][c][d];
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
