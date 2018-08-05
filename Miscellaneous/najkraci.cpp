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

using namespace std;

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

int N, M, a [5010], b [5010], c [5010];
vector<int> adjacency [1510];
priority_queue<pair<pair<int, int>, int>> pq;
vector<int> consider;
vector<int> parents [1510];
multiset<int> children [1510];
queue<int> q;
bool visited [1510];
long long tos [1510], froms [1510], ret [5010];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(9);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--; adjacency[a[i]].pb(i);
    }
    for(int st = 0; st < N; st++){
        consider = vector<int>();
        for(int i = 0; i < N; i++){
            parents[i] = vector<int>();
            tos[i] = 0; froms[i] = 0; visited[i] = false;
        }
        visited[st] = true; tos[st] = 1;
        for(int x : adjacency[st]) pq.push(mp(mp(-c[x], b[x]), x));
        while(pq.size() > 0){
            vector<pair<pair<int, int>, int>> now; now.pb(pq.top()); pq.pop();
            while(pq.size() > 0 && pq.top().f == now[0].f){ now.pb(pq.top()); pq.pop(); }
            int curr = now[0].f.s;
            if(visited[curr]) continue;
            visited[curr] = true;
            for(pair<pair<int, int>, int> state : now){
                int prevy = a[state.s];
                tos[curr] += tos[prevy]; consider.pb(state.s);
                parents[curr].pb(prevy); children[prevy].insert(curr);
            }
            for(int x: adjacency[curr])
                if(!visited[b[x]])
                    pq.push(mp(mp(now[0].f.f-c[x], b[x]), x));
        }
        for(int i = 0; i < N; i++)
            if(children[i].size() == 0)
                q.push(i);
        while(q.size() > 0){
            int curr = q.front(); q.pop();
            froms[curr]++;
            for(int nexty : parents[curr]){
                froms[nexty] += froms[curr];
                children[nexty].erase(children[nexty].find(curr));
                if(children[nexty].size() == 0) q.push(nexty);
            }
        }
        for(int x : consider) ret[x] = (ret[x]+(tos[a[x]]*froms[b[x]])%MOD)%MOD;
    }
    for(int i = 0; i < M; i++) cout << ret[i] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
