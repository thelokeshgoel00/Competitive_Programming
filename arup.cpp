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

int n;
pair<int, int> otherLoc [101];
int dist [101], retx = -205, rety = -205;
set<int> hashes;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> otherLoc[i].first >> otherLoc[i].second >> dist[i];
        if(dist[i] == 0){ cout << "Error\n"; return 0; }
        int now = otherLoc[i].first*1000+otherLoc[i].second;
        if(hashes.find(now) != hashes.end()){ cout << "Error\n"; return 0; }
    }
    for(int i = -200; i < 201; i++)
        for(int j = -201; j < 201; j++){
            bool flag = true;
            for(int k = 0; k < n; k++)
                if(max(abs(i-otherLoc[k].first), abs(j-otherLoc[k].second)) != dist[k]){
                    flag = false;
                    break;
                }
            int now = i*1000+j;
            if(hashes.find(now) != hashes.end()) continue;
            if(flag && retx == -205){ retx = i; rety = j; }
            else if(flag && retx != -205){ cout << "Multiple\n"; return 0; }
        }
    if(retx == -205){ cout << "Error\n"; return 0; }
    cout << retx << " " << rety << '\n';
    return 0;
}
