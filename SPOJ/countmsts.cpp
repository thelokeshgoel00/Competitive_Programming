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
//template <class T>
//using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

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

int N, M, parents [110], heights [110], tempID, ids [110], adj [110][110], n;
int inv3 [] = {0, 1, 2}, inv10337 [10337], arr [110][110], mult, ret3 = 1, ret10337 = 1;
vector<pair<int, pair<int, int>>> edges;
vector<int> tempGraph [110];
bool involved [110], visited [110];

int findParent(int x){
    if(x == parents[x]) return x;
    parents[x] = findParent(parents[x]);
    return parents[x];
}

bool combine(int x, int y){
    int a = findParent(x); int b = findParent(y);
    if(a == b) return false;
    if(heights[b] < heights[a]) parents[b] = a;
    else if(heights[b] > heights[a]) parents[a] = b;
    else{
        parents[b] = a;
        heights[a]++;
    }
    return true;
}

void bfs(int curr){
    visited[curr] = true; ids[curr] = tempID++;
    for(int nexty : tempGraph[curr]){
        if(!visited[nexty]){
            bfs(nexty);
            combine(curr, nexty);
        }
        adj[ids[curr]][ids[nexty]]--;
    }
    adj[ids[curr]][ids[curr]] = tempGraph[curr].size();
}

int nextVar(int i, int curVar) {
    for(int j = curVar; j < n; j++)
        for(int k = i; k < n; k++)
            if(abs(arr[k][j]) > 0)
                return j;
    return n;
}

int maxRow(int row, int var){
    int res = row;
    for(int i = row+1; i < n; i++)
        if(abs(arr[i][var]) > abs(arr[res][var]))
            res = i;
    return res;
}

void reduce(int i, int j, int curVar, int m) {
    int fac = (arr[j][curVar]*(m == 3 ? inv3[arr[i][curVar]] : inv10337[arr[i][curVar]]))%m;
    for(int k = curVar; k < n; k++) arr[j][k] = (arr[j][k]-(fac*arr[i][k])%m+m)%m;
}

void gaussIt(int m){
    int curVar = 0;
    for(int i = 0; i < n-1; i++){
        curVar = nextVar(i, curVar);
        if(curVar == n) break;
        int mr = maxRow(i, curVar);
        if(i != mr){
            swap(arr[i], arr[mr]);
            mult *= -1;
        }
        for(int j = i+1; j < n; j++) reduce(i, j, curVar, m);
        curVar++;
    }
}

int modInverse(int a, int m){
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    while(a > 1){
        q = a/m; t = m;
        m = a%m, a = t;
        t = x0; x0 = x1-q*x0;
        x1 = t;
    }
    if(x1 < 0) x1 += m0;
    return x1;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M; inv10337[0] = 0;
    for(int i = 1; i < 10337; i++) inv10337[i] = modInverse(i, 10337);
    for(int i = 0; i < N; i++){ parents[i] = i; heights[i] = 0; }
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c; a--; b--;
        edges.pb(mp(c, mp(a, b)));
    }
    sort(edges.begin(), edges.end());
    for(int idx = 0; idx < M;){
        for(int x = 0; x < N; x++){
            involved[x] = visited[x] = false;
            tempGraph[x] = vector<int>();
        }
        int same = idx;
        while(idx < M && edges[idx].f == edges[same].f){
            int a = findParent(edges[idx].s.f), b = findParent(edges[idx].s.s);
            if(a != b){
                involved[a] = involved[b] = true;
                tempGraph[a].pb(b); tempGraph[b].pb(a);
            }
            idx++;
        }
        for(int x = 0; x < N; x++){
            if(!involved[x] || visited[x]) continue;
            memset(adj, 0, sizeof(adj));
            tempID = 0; bfs(x); n = tempID-1;

            for(int i = 1; i < tempID; i++)
                for(int j = 1; j < tempID; j++)
                    arr[i-1][j-1] = (adj[i][j]%3+3)%3;
            mult = 1; gaussIt(3); ret3 *= mult;
            while(ret3 < 0) ret3 += 3;
            for(int i = 0; i < n; i++) ret3 = (ret3*arr[i][i])%3;

            for(int i = 1; i < tempID; i++)
                for(int j = 1; j < tempID; j++)
                    arr[i-1][j-1] = (adj[i][j]%10337+10337)%10337;
            mult = 1; gaussIt(10337); ret10337 *= mult;
            while(ret10337 < 0) ret10337 += 10337;
            for(int i = 0; i < n; i++) ret10337 = (ret10337*arr[i][i])%10337;
        }
    }
    for(int i = 0; i < 31011; i++)
        if(i%3 == ret3 && i%10337 == ret10337)
            cout << i << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
