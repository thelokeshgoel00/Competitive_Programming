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

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

struct Point{
    int id;
    long long x, y, z;
    Point(){ x = y = z = 0; id = -1; }
};

int N, numEdges = 0;
Point points [100010];
vector<pair<long long, pair<int, int>>> adjacency [100010];
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
bool used [100010];
long long ret = 0;

bool compX(Point a, Point b){ return a.x < b.x; }
bool compY(Point a, Point b){ return a.y < b.y; }
bool compZ(Point a, Point b){ return a.z < b.z; }

long long dist(Point a, Point b){ return min(abs(a.x-b.x), min(abs(a.y-b.y), abs(a.z-b.z))); }

int main(){
    //freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){ cin >> points[i].x >> points[i].y >> points[i].z; points[i].id = i; }
    sort(points, points+N, compX);
    for(int i = 1; i < N; i++){
        long long d = dist(points[i-1], points[i]);
        adjacency[points[i].id].push_back(make_pair(d, make_pair(points[i].id, points[i-1].id)));
        adjacency[points[i-1].id].push_back(make_pair(d, make_pair(points[i-1].id, points[i].id)));
    }
    sort(points, points+N, compY);
    for(int i = 1; i < N; i++){
        long long d = dist(points[i-1], points[i]);
        adjacency[points[i].id].push_back(make_pair(d, make_pair(points[i].id, points[i-1].id)));
        adjacency[points[i-1].id].push_back(make_pair(d, make_pair(points[i-1].id, points[i].id)));
    }
    sort(points, points+N, compZ);
    for(int i = 1; i < N; i++){
        long long d = dist(points[i-1], points[i]);
        adjacency[points[i].id].push_back(make_pair(d, make_pair(points[i].id, points[i-1].id)));
        adjacency[points[i-1].id].push_back(make_pair(d, make_pair(points[i-1].id, points[i].id)));
    }
    memset(used, false, sizeof(false)); used[0] = true;
    for(pair<long long, pair<int, int>> e : adjacency[0]) pq.push(e);
    while(numEdges < N-1){
        if(pq.size() == 0) break;
        pair<long long, pair<int, int>> now = pq.top(); pq.pop();
        if(used[now.second.first] && used[now.second.second]) continue;
        if(!used[now.second.first]){
            used[now.second.first] = true;
            for(pair<long long, pair<int, int>> e : adjacency[now.second.first]) pq.push(e);
        }
        else if(!used[now.second.second]){
            used[now.second.second] = true;
            for(pair<long long, pair<int, int>> e : adjacency[now.second.second]) pq.push(e);
        }
        ret += now.first; numEdges++;
    }
    if(numEdges < N-1) ret = -1;
    cout << ret << '\n';
    return 0;
}
