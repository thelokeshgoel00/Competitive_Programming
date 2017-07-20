#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>

using namespace std;

int n, ret = 15;
set<int> positions;

int checkMask(int mask){
    vector<pair<int, int>> startPos; int numBits = 0;
    set<int> covered;
    for(int i = 0; i < 8; i++) startPos.push_back(make_pair(0, i));
    for(int i = 1; i < 8; i++) startPos.push_back(make_pair(i, 0));
    for(int i = 0; i < 15; i++){
        if((mask&(1<<i)) == 0) continue;
        numBits++;
        int x = startPos[i].first, y = startPos[i].second, dx = 1, dy = 1;
        while(x > -1 && y > -1 && x < 8 && y < 8){
            int temp = x*100+y;
            if(positions.find(temp) != positions.end()) covered.insert(temp);
            x += dx; y += dy;
        }
    }
    if(covered.size() == positions.size()) return numBits;
    return -1;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        positions.insert(a*100+b-101);
    }
    for(int i = 0; i < (1<<15); i++){
        int gg = checkMask(i);
        if(gg != -1) ret = min(ret, gg);
    }
    cout << ret << '\n';
    return 0;
}
