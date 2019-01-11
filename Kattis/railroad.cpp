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
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int kase, N, M;
vector<pair<int, int>> adjacency [40010];
bool visited [40010];
vector<pair<pair<int, int>, int>> ret;

pair<int, int> recurseIt(int curr, int prevy){
    if(adjacency[curr].size() != 2) return make_pair(curr, 0);
    visited[curr] = true;
    for(pair<int, int> e : adjacency[curr]){
        if(e.first == prevy) continue;
        pair<int, int> ret = recurseIt(e.first, curr);
        ret.second += e.second;
        return ret;
    }
    return make_pair(0, 0);
}

int main(){
    //freopen("greedy.in", "r", stdin); freopen("greedy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N >> M; ret.clear();
        for(int i = 0; i < 40010; i++){ adjacency[i].clear(); visited[i] = false; }
        for(int i = 0; i < M; i++){
            int a, b, c; cin >> a >> b >> c; N++;
            adjacency[a].push_back(make_pair(N, c)); adjacency[b].push_back(make_pair(N, c));
            adjacency[N].push_back(make_pair(a, c)); adjacency[N].push_back(make_pair(b, c));
        }
        for(int i = 1; i <= N; i++)
            if(!visited[i] && adjacency[i].size() == 2){
                visited[i] = true;
                pair<int, int> a = recurseIt(adjacency[i][0].first, i), b = recurseIt(adjacency[i][1].first, i);
                ret.push_back(make_pair(make_pair(min(a.first, b.first), max(a.first, b.first)),
                        a.second+b.second+adjacency[i][0].second+adjacency[i][1].second));
            }
        cout << ret.size() << '\n'; sort(ret.begin(), ret.end());
        for(int i = 0; i < ret.size(); i++)
            cout << ret[i].first.first << ' ' << ret[i].first.second << ' ' << ret[i].second/2 << '\n';
        cout << '\n';
    }
    return 0;
}
