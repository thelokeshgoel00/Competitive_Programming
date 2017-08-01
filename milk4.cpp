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

int Q, P, minUse;
vector<int> pails;
set<int> used;
bool dp [20010];

int recurse(int curr){
    if(minUse == used.size()){
        memset(dp, false, sizeof(dp)); dp[0] = true;
        for(int i : used)
            for(int j = i; j <= Q; j++)
                dp[j] = dp[j] || dp[j-i];
        return dp[Q];
    }
    if(curr == P) return false;
    used.insert(pails[curr]);
    if(recurse(curr+1)) return true;
    used.erase(pails[curr]);
    if(recurse(curr+1)) return true;
    return false;
}

int main(){
    //freopen("milk4.in", "r", stdin); freopen("milk4.out", "w", stdout);
    cin >> Q >> P;
    for(int i = 0; i < P; i++){
        int x; cin >> x;
        used.insert(x);
    }
    for(int i : used) pails.push_back(i);
    sort(pails.begin(), pails.end());
    P = pails.size(); used.clear();
    for(minUse = 1; minUse < P+1; minUse++)
        if(recurse(0)) break;
    cout << minUse;
    for(int i : used) cout << " " << i;
    cout << '\n';
    return 0;
}
