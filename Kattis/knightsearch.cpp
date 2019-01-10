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

int N, dx [] = {2, 2, -2, -2, 1, 1, -1, -1}, dy [] = {1, -1, 1, -1, 2, -2, 2, -2};
string s, check = "ICPCASIASG";
char grid [110][110];
bool visited [110][110][10];
priority_queue<pair<int, pair<int, int>>> pq;

bool inBounds(int x, int y){ return min(x, y) > -1 && max(x, y) < N; }

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> s;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            grid[i][j] = s[i*N+j];
            if(grid[i][j] == check[0]) pq.push(mp(0, mp(i, j)));
        }
    while(pq.size() > 0){
        pair<int, pair<int, int>> now = pq.top(); pq.pop();
        if(now.f == 9){
            cout << "YES\n";
            return 0;
        }
        if(visited[now.s.f][now.s.s][now.f]) continue;
        visited[now.s.f][now.s.s][now.f] = true;
        for(int i = 0; i < 8; i++){
            int nr = now.s.f+dx[i], nc = now.s.s+dy[i];
            if(inBounds(nr, nc) && grid[nr][nc] == check[now.f+1] && !visited[nr][nc][now.f+1])
                pq.push(mp(now.f+1, mp(nr, nc)));
        }
    }
    cout << "NO\n";
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
