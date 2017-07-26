#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

int kase, num, x, y;
vector<pair<int, int>> bois;

int main(){
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> num; bois.clear();
        for(int i = 0; i < num+1; i++){
            cin >> x >> y;
            bois.push_back(make_pair(x, y));
        }
        for(int i = 1; i < 3000000; i++){
            bool good = true;
            for(int j = 0; j < num+1; j++)
                if(i%(bois[j].first+bois[j].second) < bois[j].first){
                    good = false; break;
                }
            if(good){ cout << i << '\n'; break; }
        }
    }
}
