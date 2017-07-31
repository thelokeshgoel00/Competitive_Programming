/*
ID: vamaddu1
PROG: milk4
LANG: C++11
*/

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

int Q, P;
vector<int> pails;
set<int> needed [20001];
bool reachable [20001];

int main(){
    freopen("milk4.in", "r", stdin); freopen("milk4.out", "w", stdout);
    cin >> Q >> P; memset(reachable, false, sizeof(reachable)); reachable[0] = true;
    for(int i = 0; i < P; i++){
        int x; cin >> x;
        pails.push_back(x);
    }
    sort(pails.begin(), pails.end());
    for(int i = 0; i < P; i++)
        for(int j = 0; j <= Q-pails[i]; j++){
            if(!reachable[j]) continue;
            if(!reachable[j+pails[i]] || (reachable[j+pails[i]] && needed[j].size()+1 < needed[j+pails[i]].size())){
                needed[j+pails[i]].clear();
                for(int x : needed[j]) needed[j+pails[i]].insert(x);
                needed[j+pails[i]].insert(pails[i]);
            }
            reachable[j+pails[i]] = true;
        }
    cout << needed[Q].size();
    for(int i : needed[Q]) cout << " " << i;
    cout << '\n';
    return 0;
}
