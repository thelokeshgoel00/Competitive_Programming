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

int N, bx, by, ret = 0, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, tree [100010];
map<int, vector<pair<int, char>>> xCols;
map<int, vector<pair<int, char>>> yRows;
vector<pair<int, int>> pathFromLaser, pathFromBarn;
vector<pair<int, pair<int, int>>> vertLaser, vertBarn, horiLaser, horiBarn;

void add(int pos, int x){
    while(pos < 100010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

pair<pair<int, int>, char> getNext(int x, int y, int dir){
    bool vertMove = (dir%2 == 0);
    int a = vertMove ? x : y, b = vertMove ? y : x, db = vertMove ? dy[dir] : dx[dir];
    vector<pair<int, char>> &arr = (vertMove ? xCols : yRows)[a];
    int id = lower_bound(arr.begin(), arr.end(), make_pair(b, (char)0))-arr.begin();
    id += db;
    char ch = '?';
    if(id < 0) b = -1000000001;
    else if(id == arr.size()) b = 1000000001;
    else{
        b = arr[id].first;
        ch = arr[id].second;
    }
    return make_pair(vertMove ? make_pair(a, b) : make_pair(b, a), ch);
}

vector<pair<int, int>> findPath(int x, int y, int dir) {
    pair<int, int> curr = make_pair(x, y);
    vector<pair<int, int>> path; path.push_back(curr);
    while(true){
        pair<pair<int, int>, char> nexty = getNext(curr.first, curr.second, dir);
        curr = nexty.first; path.push_back(curr);
        if(nexty.second == '/') dir = (dir+(dir%2 != 0 ? 3 : 1))%4;
        else if(nexty.second == '\\') dir = (dir+(dir%2 != 0 ? 1 : 3))%4;
        else break;
    }
    return path;
}

vector<pair<int, pair<int, int>>> getVertSegs(vector<pair<int, int>> path){
    vector<pair<int, pair<int, int>>> segs;
    for(int i = 0; i < path.size()-1; i++)
        if(path[i].first == path[i+1].first){
            segs.push_back(make_pair(path[i].first, make_pair(path[i].second, path[i+1].second)));
            if(segs.back().second.second < segs.back().second.first) swap(segs.back().second.first, segs.back().second.second);
        }
    return segs;
}

vector<pair<int, pair<int, int>>> getHoriSegs(vector<pair<int, int>> path){
    vector<pair<int, pair<int, int>>> segs;
    for(int i = 0; i < path.size()-1; i++)
        if(path[i].second == path[i+1].second){
            segs.push_back(make_pair(path[i].second, make_pair(path[i].first, path[i+1].first)));
            if(segs.back().second.second < segs.back().second.first) swap(segs.back().second.first, segs.back().second.second);
        }
    return segs;
}

int getIntersections(vector<pair<int, pair<int, int>>> verts, vector<pair<int, pair<int, int>>> horis){
    int sum = 0, eindex = 0, vindex = 0;
    vector<int> ys; vector<pair<pair<int, int>, int>> events;
    for(int i = 0; i < verts.size(); i++){
        ys.push_back(verts[i].second.first);
        ys.push_back(verts[i].second.second);
    }
    for(int i = 0; i < horis.size(); i++) ys.push_back(horis[i].first);
    sort(ys.begin(), ys.end()); ys.resize(unique(ys.begin(), ys.end())-ys.begin());
    for(int i = 0; i < verts.size(); i++){
        verts[i].second.first = lower_bound(ys.begin(), ys.end(), verts[i].second.first)-ys.begin()+1;
        verts[i].second.second = lower_bound(ys.begin(), ys.end(), verts[i].second.second)-ys.begin()+1;
    }
    for(int i = 0; i < horis.size(); i++) horis[i].first = lower_bound(ys.begin(), ys.end(), horis[i].first)-ys.begin()+1;
    sort(verts.begin(), verts.end());
    for(int i = 0; i < horis.size(); i++) {
        events.push_back(make_pair(make_pair(horis[i].second.first, horis[i].first), 1));
        events.push_back(make_pair(make_pair(horis[i].second.second, horis[i].first), -1));
    }
    sort(events.begin(), events.end()); memset(tree, 0, sizeof(tree));
    while(eindex < events.size()){
        while(vindex < verts.size() && verts[vindex].first < events[eindex].first.first){
            sum += query(verts[vindex].second.second-1)-query(verts[vindex].second.first);
            vindex++;
        }
        add(events[eindex].first.second, events[eindex].second); eindex++;
    }
    return sum;
}

int main(){
    freopen("optics.in", "r", stdin); freopen("optics.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> bx >> by;
    xCols[0].push_back(make_pair(0, 'S')); yRows[0].push_back(make_pair(0, 'S'));
    xCols[bx].push_back(make_pair(by, 'B')); yRows[by].push_back(make_pair(bx, 'B'));
    for(int i = 0; i < N; i++){
        int x, y; string mirror; cin >> x >> y >> mirror;
        xCols[x].push_back(make_pair(y, mirror[0])); yRows[y].push_back(make_pair(x, mirror[0]));
    }
    for(auto it = xCols.begin(); it != xCols.end(); it++) sort(it->second.begin(), it->second.end());
    for(auto it = yRows.begin(); it != yRows.end(); it++) sort(it->second.begin(), it->second.end());
    pathFromLaser = findPath(0, 0, 0); vertLaser = getVertSegs(pathFromLaser); horiLaser = getHoriSegs(pathFromLaser);
    for(int i = 0; i < 4; i++){
        pathFromBarn = findPath(bx, by, i); vertBarn = getVertSegs(pathFromBarn); horiBarn = getHoriSegs(pathFromBarn);
        int add = getIntersections(vertLaser, horiBarn)+getIntersections(vertBarn, horiLaser);
        if(pathFromBarn[0] == pathFromBarn.back()) ret += add/2;
        else ret += add;
    }
    cout << ret << '\n';
    return 0;
}
