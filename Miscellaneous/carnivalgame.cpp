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

int N, M, T;
vector<vector<double>> graph, powered;
vector<pair<int, double>> adjacency [210];
double ret = -INF;

vector<vector<double>> matrixMult(vector<vector<double>> a, vector<vector<double>> b){
    vector<vector<double>> c(a.size(), vector<double>(b[0].size()));
    for(int i = 0; i < c.size(); i++)
        for(int j = 0; j < c[0].size(); j++)
            for(int k = 0; k < a[0].size(); k++)
                c[i][j] += (a[i][k]*b[k][j]);
    return c;
}

vector<vector<double>> matrixExpo(vector<vector<double>> mat, long long x){
    if(x == 1) return mat;
    vector<vector<double>> half = matrixExpo(mat, x/2);
    vector<vector<double>> ans = matrixMult(half, half);
    if(x%2 == 1) return matrixMult(mat, ans);
    else return ans;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> M >> T; graph = vector<vector<double>>(N+1, vector<double>(N+1, 0)); graph[N][N] = 1;
    for(int i = 0 ; i < M; i++){
        int a, b; double c; cin >> a >> b >> c; a--; b--;
        adjacency[a].pb(mp(b, c));
    }
    for(int i = 0; i < N; i++){
        for(pair<int, double> edge : adjacency[i]){
            graph[i][edge.f] = 1.0/adjacency[i].size();
            graph[i][N] += edge.s;
        }
        graph[i][N] /= adjacency[i].size();
    }
    powered = matrixExpo(graph, T);
    for(int i = 0; i < N; i++) ret = max(ret, powered[i][N]);
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
