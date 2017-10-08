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

int N;
pair<int, int> observer, vertices [210];
bool visited [210];
vector<pair<pair<int, int>, pair<int, int>>> ret;

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
    scanf("%d %d %d", &N, &observer.first, &observer.second);
    for(int i = 0; i < N; i++) scanf("%d %d", &vertices[i].first, &vertices[i].second);
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(i == j || (i+1)%N == j || i == (j+1)%N) continue;
            if(intersect(vertices[i], vertices[(i+1)%N], vertices[j], vertices[(j+1)%N])){
                cout << "NOFENCE\n";
                return 0;
            }
        }
    for(int i = 0; i < N; i++){
        pair<int, int> temp = vertices[i]; temp.first *= 500; temp.second *= 500;
        int dx = vertices[(i+1)%N].first-vertices[i].first, dy = vertices[(i+1)%N].second-vertices[i].second;
        temp.first -= dx; temp.second -= dy;
        for(int j = 0; j < 501; j++){
            temp.first += dx; temp.second += dy;
            bool isCovered = false;
            for(int k = 0; k < N; k++){
                if(i == k) continue;
                pair<int, int> a = make_pair(observer.first*500, observer.second*500),
                c = make_pair(vertices[k].first*500, vertices[k].second*500),
                d = make_pair(vertices[(k+1)%N].first*500, vertices[(k+1)%N].second*500);
                if(intersect(a, temp, c, d)){
                    isCovered = true;
                    break;
                }
            }
            if(!isCovered) {
                visited[i] = true;
                break;
            }
        }
    }
    for(int i = 0; i < N-2; i++)
        if(visited[i] && cross(observer, vertices[i], vertices[i+1]) != 0)
            ret.push_back(make_pair(vertices[i], vertices[i + 1]));
    if(visited[N-1] && cross(observer, vertices[N-1], vertices[0]) != 0)
        ret.push_back(make_pair(vertices[0], vertices[N - 1]));
    if(visited[N-2] && cross(observer, vertices[N-2], vertices[N-1]) != 0)
        ret.push_back(make_pair(vertices[N-2], vertices[N-1]));
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i].first.first << " " << ret[i].first.second <<
        " " << ret[i].second.first << " " << ret[i].second.second << '\n';
    return 0;
}
