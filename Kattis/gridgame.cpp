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

int N, grid [80][80], graph [80][80], prevs [80], lo = 1, hi = 1000000, ret;

bool bfs(int source, int sink){
    queue<int> q; q.push(source);
    while(q.size() > 0){
        int curr = q.front(); q.pop();
        for(int i = 0; i < 2*N+2; i++)
            if(graph[curr][i] > 0 && prevs[i] == -1){
                prevs[i] = curr;
                if(i == sink) return true;
                q.push(i);
            }
    }
    return false;
}

int EdmondsKarp(int source, int sink){
    int flowy = 0;
    while(true){
        for(int i = 0; i < 2*N+2; i++) prevs[i] = -1;
        if(!bfs(source, sink)) break;
        int add = MOD;
        for(int i = sink; i != source; i = prevs[i]) add = min(add, graph[prevs[i]][i]);
        flowy += add;
        for(int i = sink; i != source; i = prevs[i]){
            graph[prevs[i]][i] -= add;
            graph[i][prevs[i]] += add;
        }
    }
    return flowy;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];
    while(lo <= hi){
        int mid = (lo+hi)/2; memset(graph, 0, sizeof(graph));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                graph[i][j+N] = grid[i][j] >= mid;
        for(int i = 0; i < N; i++) graph[2*N][i] = 1;
        for(int j = 0; j < N; j++) graph[j+N][2*N+1] = 1;
        if(EdmondsKarp(2*N, 2*N+1) == N){ lo = mid+1; ret = mid; }
        else hi = mid-1;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
