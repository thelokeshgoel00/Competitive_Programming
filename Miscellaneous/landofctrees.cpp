// My Own Method
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
#define INF 5000000000000000000
#define MOD 1000000007

int N, Q, block = 1200, root [100010], xo [100010];
unordered_map<int, int> adjacency [100010], nexty [100010], rootAdjacency [100010];
unordered_set<int> consider;

void genRoot(int curr, int val, int ori){
    root[curr] = ori; xo[curr] = val;
     for(pair<int, int> edge : nexty[curr])
        if(root[edge.first] == 0)
            genRoot(edge.first, val^edge.second, ori);
}

void insertIt(int a, int b, int c){
    adjacency[a][b] = adjacency[b][a] = c;
    rootAdjacency[root[a]][root[b]] = rootAdjacency[root[b]][root[a]] = xo[a]^xo[b]^c;
}

void deleteIt(int a, int b){
    adjacency[a].erase(b), adjacency[b].erase(a);
    rootAdjacency[root[a]].erase(root[b]), rootAdjacency[root[b]].erase(root[a]);
}

bool dfs(int curr, int prevy, int &val, int dest){
    if(curr == dest) return true;
    for(pair<int, int> edge : rootAdjacency[curr]){
        if(edge.first == prevy) continue;
        bool ok = dfs(edge.first, curr, val, dest);
        if(ok){
            val ^= edge.second;
            return true;
        }
    }
    return false;
}

void processIt(int L, int R){
    vector<pair<char, vector<int>>> queries;
    for(int i = 1; i <= N; i++){
        nexty[i] = adjacency[i]; rootAdjacency[i].clear();
        root[i] = 0; xo[i] = 0;
    }
    consider.clear();
    for(int i = L; i < R; i++){
        char c; int x, y, z; cin >> c >> x >> y;
        vector<int> lol; lol.push_back(x); lol.push_back(y);
        if(c == 'A'){ cin >> z; lol.push_back(z); }
        else if(c == 'R'){ nexty[x].erase(y); nexty[y].erase(x); }
        queries.push_back(make_pair(c, lol));
        consider.insert(x); consider.insert(y);
    }
    for(int i : consider)
        if(root[i] == 0)
            genRoot(i, 0, i);
    for(int i = 1; i <= N; i++)
        for(pair<int, int> edge : adjacency[i])
            if(root[i] != root[edge.first] && root[i] > 0 && root[edge.first] > 0)
                insertIt(i, edge.first, edge.second);
    for(pair<char, vector<int>> now : queries){
        if(now.first == 'A') insertIt(now.second[0], now.second[1], now.second[2]);
        else if(now.first == 'R') deleteIt(now.second[0], now.second[1]);
        else{
            int ret = 0; 
            bool good = dfs(root[now.second[0]], 0, ret, root[now.second[1]]);
            if(!good) cout << "-1\n";
            else cout << (ret^xo[now.second[0]]^xo[now.second[1]]) << '\n';
        }
    }
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i = 1; i < N; i++){
        int a, b, c; cin >> a >> b >> c;
        adjacency[a][b] = c; adjacency[b][a] = c;
    }
    for(int i = 0; i < (Q+block-1)/block; i++) processIt(i*block, min((i+1)*block, Q));
    return 0;
}
// Faster Method
/*
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
#define INF 5000000000000000000
#define MOD 1000000007

int N, Q, block = 1200, root [100010], xo [100010];
unordered_map<int, int> adjacency [100010], rootAdjacency [100010];
bool consider [100010];

void genRoot(int curr, int val, int prevy, int ori){
    root[curr] = ori; xo[curr] = val;
    if(consider[curr]){
        ori = curr;
        val = 0;
    }
     for(pair<int, int> edge : adjacency[curr])
        if(root[edge.first] == -1)
            genRoot(edge.first, val^edge.second, curr, ori);
}

void insertIt(int a, int b, int c){
    adjacency[a][b] = adjacency[b][a] = c;
    rootAdjacency[a][b] = rootAdjacency[b][a] = c;
}

void deleteIt(int a, int b){
    adjacency[a].erase(b), adjacency[b].erase(a);
    rootAdjacency[a].erase(b), rootAdjacency[b].erase(a);
}

bool dfs(int curr, int prevy, int &val, int dest){
    if(curr == dest) return true;
    for(pair<int, int> edge : rootAdjacency[curr])
        if(edge.first != prevy && dfs(edge.first, curr, val, dest)){
            val ^= edge.second;
            return true;
        }
    return false;
}

void processIt(int L, int R){
    vector<pair<char, vector<int>>> queries;
    for(int i = 1; i <= N; i++){
        rootAdjacency[i].clear();
        root[i] = -1; xo[i] = 0; consider[i] = false;
    }
    for(int i = L; i < R; i++){
        char c; int x, y, z; cin >> c >> x >> y;
        vector<int> lol; lol.push_back(x); lol.push_back(y);
        if(c == 'A'){ cin >> z; lol.push_back(z); }
        queries.push_back(make_pair(c, lol));
        consider[x] = consider[y] = true;
    }
    for(int i = 1; i <= N; i++)
        if(consider[i] && root[i] == -1)
            genRoot(i, 0, 0, -2);
    for(int i = 1; i <= N; i++)
        if(consider[i] && root[i] > 0)
            rootAdjacency[i][root[i]] = rootAdjacency[root[i]][i] = xo[i];
    for(pair<char, vector<int>> now : queries){
        if(now.first == 'A') insertIt(now.second[0], now.second[1], now.second[2]);
        else if(now.first == 'R') deleteIt(now.second[0], now.second[1]);
        else{
            int ret = 0; bool good = dfs(now.second[0], -1, ret, now.second[1]);
            if(!good) cout << "-1\n";
            else cout << ret << '\n';
        }
    }
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i = 1; i < N; i++){
        int a, b, c; cin >> a >> b >> c;
        adjacency[a][b] = c; adjacency[b][a] = c;
    }
    for(int i = 0; i < (Q+block-1)/block; i++) processIt(i*block, min((i+1)*block, Q));
    return 0;
}
*/
