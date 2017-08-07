#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

int numCows, best = 0, area = 0;
vector<pair<pair<int, int>, bool>> cows; //(x, y) and isHolstein
set<int> tempHori;
vector<int> horizontal;

int main(){
    freopen("cowrect.in", "r", stdin); freopen("cowrect.out", "w", stdout);
    cin >> numCows;
    for(int i = 0; i < numCows; i++){
        cows.push_back(make_pair(make_pair(-1, -1), false));
        string c; cin >> cows[i].first.first >> cows[i].first.second >> c;
        cows[i].second = c.compare("H") == 0;
        tempHori.insert(cows[i].first.second);
    }
    sort(cows.begin(), cows.end());
    for(int i : tempHori) horizontal.push_back(i);
    for(int i = 0; i < horizontal.size(); i++)
        for(int j = i+1; j < horizontal.size(); j++){
            bool ok = false; int lastX = -1, curSize = 0, start = 0;
            while(start < numCows){
                int fin = start, hol = 0, gur = 0;
                while(fin < numCows && cows[start].first.first == cows[fin].first.first){
                    if(cows[fin].first.second >= horizontal[i] && cows[fin].first.second <= horizontal[j]){
                        if(cows[fin].second) hol++;
                        else gur++;
                    }
                    fin++;
                }
                if(gur > 0){
                    ok = false;
                    curSize = 0;
                }
                else if(hol > 0){
                    if(!ok){
                        ok = true;
                        lastX = cows[start].first.first;
                    }
                    curSize += hol;
                    int curArea = (horizontal[j]-horizontal[i])*(cows[start].first.first-lastX);
                    if(curSize > best || (curSize == best && curArea < area)){
                        best = curSize;
                        area = curArea;
                    }
                }
                start = fin;
            }
        }
    cout << best << '\n' << area << '\n';
    return 0;
}
