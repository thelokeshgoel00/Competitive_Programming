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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, isError [100010], subtreeSizes [100010], dp [100010][2], mini = 0, maxi = 0;
vector<int> children [100010], roots;

void findSubtreeSizes(int curr){
    subtreeSizes[curr] = 1;
    for(int i : children[curr]){
        findSubtreeSizes(i);
        subtreeSizes[curr] += subtreeSizes[i];
    }
}

int solveIt(int curr, int tryMaxi){
    if(dp[curr][tryMaxi] != -1) return dp[curr][tryMaxi];
    int correct = 0, wrong = 0;
    if(isError[curr] != 0) wrong++;
    for(int i : children[curr]){
        correct += solveIt(i, tryMaxi);
        wrong += subtreeSizes[i]-solveIt(i, 1-tryMaxi);
    }
    if(isError[curr] == 1) dp[curr][tryMaxi] = wrong;
    else if(isError[curr] == 0) dp[curr][tryMaxi] = correct;
    else{
        if(tryMaxi == 1) dp[curr][tryMaxi] = max(wrong, correct);
        else dp[curr][tryMaxi] = min(wrong, correct);
    }
    return dp[curr][tryMaxi];
}

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(subtreeSizes, 0, sizeof(subtreeSizes)); memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= N; i++){
        char c; int x; string s; cin >> c;
        if(c == 'C'){ cin >> s; roots.push_back(i); }
        else{ cin >> x >> s; children[x].push_back(i); }
        if(s.compare("AC") == 0) isError[i] = 0;
        else if(s.compare("WA") == 0) isError[i] = 1;
        else isError[i] = -1;
    }
    for(int i = 0; i < roots.size(); i++){
        findSubtreeSizes(roots[i]);
        mini += solveIt(roots[i], 0);
        maxi += solveIt(roots[i], 1);
    }
    cout << mini << " " << maxi << '\n';
    return 0;
}
