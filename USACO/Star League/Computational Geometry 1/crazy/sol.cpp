#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, C, groupNum = 0, curRun = 0, ret = 0;
vector<int> groups [1010];
pair<pair<int, int>, pair<int, int>> fences [1010];
map<pair<int, int>, vector<int>> adjacency;
bool visited [1010];
vector<string> masks;

long long cross(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    return (long long)(b.first-a.first)*(long long)(c.second-a.second)-(long long)(b.second-a.second)*(long long)(c.first-a.first);
}

bool inside(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    return c.first >= min(a.first, b.first) && c.first <= max(a.first, b.first) &&
    c.second >= min(a.second, b.second) && c.second <= max(a.second, b.second);
}

bool intersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d){
    long long abc = cross(a, b, c);
    long long abd = cross(a, b, d);
    long long cda = cross(c, d, a);
    long long cdb = cross(c, d, b);
    if (((abc > 0 && abd < 0) || (abc < 0 && abd > 0)) && ((cda > 0 && cdb < 0) || (cda < 0 && cdb > 0))) return true;
    if(abc == 0ll && inside(a, b, c)) return true;
    if(abd == 0ll && inside(a, b, d)) return true;
    if(cda == 0ll && inside(c, d, a)) return true;
    return cdb == 0ll && inside(c, d, b);
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d %d", &N, &C); memset(visited, false, sizeof(visited));
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d", &fences[i].first.first, &fences[i].first.second, &fences[i].second.first, &fences[i].second.second);
        adjacency[fences[i].first].push_back(i); adjacency[fences[i].second].push_back(i);
    }
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        vector<int> temp; queue<int> q; q.push(i);
        while(q.size() > 0){
           int curr = q.front(); q.pop();
           if(visited[curr]) continue;
           visited[curr] = true; temp.push_back(curr);
           for(int nexty : adjacency[fences[curr].first])
                if(!visited[nexty])
                    q.push(nexty);
           for(int nexty : adjacency[fences[curr].second])
                if(!visited[nexty])
                    q.push(nexty);
        }
        groups[groupNum] = temp; groupNum++;
    }
    for(int k = 0; k < C; k++){
        pair<int, int> cow; scanf("%d %d", &cow.first, &cow.second);
        string s = ""; for(int i = 0; i < groupNum; i++) s += '0';
        for(int j = 0; j < groupNum; j++){
            int numHit = 0;
            for(int seg : groups[j])
                if(intersect(cow, make_pair(cow.first+1, cow.second+1000000000), fences[seg].first, fences[seg].second))
                    numHit++;
            s[j] = (char)((int)'0'+numHit%2);
        }
        masks.push_back(s);
    }
    sort(masks.begin(), masks.end());
    for(int i = 0; i < C; i++){
        if(i == 0 || masks[i].compare(masks[i-1]) != 0) curRun = 0;
        curRun++; ret = max(ret, curRun);
    }
    cout << ret << '\n';
    return 0;
}
