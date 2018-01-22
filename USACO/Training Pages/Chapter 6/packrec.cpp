/*
ID: vamaddu1
PROG: packrec
LANG: C++11
*/

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
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int pos [4];
pair<int, int> rects [4];
bool used [4];
set<pair<int, int>> ret;

void processIt(int w, int h){
    if(w > h) swap(w, h);
    int curMin = (*ret.begin()).first*(*ret.begin()).second;
    if(w*h < curMin) ret.clear();
    if(w*h <= curMin) ret.insert(make_pair(w, h));
}

void tryRectangle(){
    processIt(rects[pos[0]].first+rects[pos[1]].first+rects[pos[2]].first+rects[pos[3]].first,
              max(max(rects[pos[0]].second, rects[pos[1]].second), max(rects[pos[2]].second, rects[pos[3]].second)));
    processIt(max(rects[pos[0]].first+rects[pos[1]].first+rects[pos[2]].first, rects[pos[3]].first),
              max(max(rects[pos[0]].second, rects[pos[1]].second), rects[pos[2]].second)+rects[pos[3]].second);
    processIt(max(rects[pos[0]].first+rects[pos[1]].first, rects[pos[2]].first)+rects[pos[3]].first,
              max(max(rects[pos[0]].second, rects[pos[1]].second)+rects[pos[2]].second, rects[pos[3]].second));
    processIt(rects[pos[0]].first+max(rects[pos[1]].first, rects[pos[2]].first)+rects[pos[3]].first,
              max(max(rects[pos[0]].second, rects[pos[3]].second), rects[pos[1]].second+rects[pos[2]].second));
    if(rects[pos[3]].second >= rects[pos[1]].second && rects[pos[0]].first <= rects[pos[1]].first)
        processIt(max(rects[pos[0]].first+rects[pos[2]].first, rects[pos[1]].first+rects[pos[3]].first),
                  max(rects[pos[0]].second+rects[pos[1]].second, rects[pos[2]].second+rects[pos[3]].second));
}

void generateIt(int idx){
    if(idx == 4){
        tryRectangle();
        return;
    }
    for(int i = 0; i < 4; i++){
        if(used[i]) continue;
        pos[idx] = i; used[i] = true;
        generateIt(idx+1);
        used[i] = false;
    }
}

int main(){
    freopen("packrec.in", "r", stdin); freopen("packrec.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    for(int i = 0; i < 4; i++){ cin >> rects[i].first >> rects[i].second; used[i] = false; }
    ret.insert(make_pair(200, 200));
    for(int mask = 0; mask < 16; mask++){
        for(int i = 0; i < 4; i++)
            if((mask&(1<<i)) > 0)
                swap(rects[i].first, rects[i].second);
        generateIt(0);
        for(int i = 0; i < 4; i++)
            if((mask&(1<<i)) > 0)
                swap(rects[i].first, rects[i].second);
    }
    cout << (*ret.begin()).first*(*ret.begin()).second << '\n';
    for(auto it = ret.begin(); it != ret.end(); it++) cout << (*it).first << ' ' << (*it).second << '\n';
    return 0;
}
