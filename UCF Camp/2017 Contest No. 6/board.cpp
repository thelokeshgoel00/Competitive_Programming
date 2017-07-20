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

int n, ret;
pair<int, int> stuff [80];
map<int, int> hashToIndex;
bool used [80];

int main(){
    cin >> n; ret = n; memset(used, false, sizeof(used));
    for(int i = 0; i < n; i++){
        cin >> stuff[i].first >> stuff[i].second;
        stuff[i].first--; stuff[i].second--;
        hashToIndex[stuff[i].first*100+stuff[i].second] = i;
    }
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        used[i] = true;
        int rightd = 0, leftd = 0, x = stuff[i].first+1, y = stuff[i].second+1, dx = 1, dy = 1;
        while(x < 8 && y < 8){
            if(hashToIndex.find(100*x+y) != hashToIndex.end() && !used[hashToIndex.find(100*x+y)->second]){
                rightd++;
                used[hashToIndex.find(100*x+y)->second] = true;
            }
            x += dx; y += dy;
        }
        x = stuff[i].first-1, y = stuff[i].second-1, dx = -1, dy = -1;
        while(x > -1 && y > -1){
            if(hashToIndex.find(100*x+y) != hashToIndex.end() && !used[hashToIndex.find(100*x+y)->second]){
                rightd++;
                used[hashToIndex.find(100*x+y)->second] = true;
            }
            x += dx; y += dy;
        }
        if(rightd > 0){ ret -= rightd; continue; }
        x = stuff[i].first+1, y = stuff[i].second-1, dx = 1, dy = -1;
        while(x < 8 && y > -1){
            if(hashToIndex.find(100*x+y) != hashToIndex.end() && !used[hashToIndex.find(100*x+y)->second]){
                leftd++;
                used[hashToIndex.find(100*x+y)->second] = true;
            }
            x += dx; y += dy;
        }
        x = stuff[i].first-1, y = stuff[i].second+1, dx = -1, dy = 1;
        while(x > -1 && y < 8){
            if(hashToIndex.find(100*x+y) != hashToIndex.end() && !used[hashToIndex.find(100*x+y)->second]){
                leftd++;
                used[hashToIndex.find(100*x+y)->second] = true;
            }
            x += dx; y += dy;
        }
        ret -= leftd;
    }
    cout << ret << '\n';
    return 0;
}
