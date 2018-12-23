/*
ID: vamaddu1
PROG: betsy
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

int N, dx [] = {-1, 1, 0, 0}, dy [] = {0, 0, -1, 1};
bool visited [10][10];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < N && y < N; }

bool isDeadEnd(int x, int y){
    if((!inBounds(x+1, y) || visited[x+1][y]) && (!inBounds(x-1, y) || visited[x-1][y]))
        if(inBounds(x, y+1) && !visited[x][y+1] && inBounds(x, y-1) && !visited[x][y-1])
            return true;
    if((!inBounds(x, y+1) || visited[x][y+1]) && (!inBounds(x, y-1) || visited[x][y-1]))
        if(inBounds(x+1, y) && !visited[x+1][y] && inBounds(x-1, y) && !visited[x-1][y])
            return true;
    return false;
}

int getOutdegree(int x, int y){
    int deg = 0;
    for(int i = 0; i < 4; i++){
        int nr = x+dx[i], nc = y+dy[i];
        deg += inBounds(nr, nc) && !visited[nr][nc];
    }
    return deg;
}

int solveIt(int x, int y, int num){
    if(num == N*N) return x == N-1 && y == 0;
    if(x == N-1 && y == 0) return 0;
    if(isDeadEnd(x, y)) return 0;
    int ret = 0, cnt = 0, idx = -1; visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nr = x+dx[i], nc = y+dy[i];
        if(inBounds(nr, nc) && !visited[nr][nc] && getOutdegree(nr, nc) == 1){
            if(nr == N-1 && nc == 0) continue;
            idx = i; cnt++;
        }
    }
    if(cnt == 1) ret += solveIt(x+dx[idx], y+dy[idx], num+1);
    else{
        for(int i = 0; i < 4; i++){
            int nr = x+dx[i], nc = y+dy[i];
            if(inBounds(nr, nc) && !visited[nr][nc]) ret += solveIt(nr, nc, num+1);
        }
    }
    visited[x][y] = false;
    return ret;
}

int main(){
    freopen("betsy.in", "r", stdin); freopen("betsy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    cout << solveIt(0, 0, 1) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
