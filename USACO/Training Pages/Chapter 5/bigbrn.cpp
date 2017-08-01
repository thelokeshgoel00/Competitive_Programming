/*
ID: vamaddu1
PROG: bigbrn
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

int len, numTrees, dp [1010][1010], ret = 0;
set<int> trees;

int main(){
    freopen("bigbrn.in", "r", stdin); freopen("bigbrn.out", "w", stdout);
    cin >> len >> numTrees; 
    for(int i = 1; i <= len; i++)
      for(int j = 1; j <= len; j++)
        dp[i][j]= 1;
    for(int i = 0; i < numTrees; i++){
        int a, b; cin >> a >> b;
        dp[a][b] = 0;
        trees.insert(a*2000+b);
    }
    for(int i = len; i > 0; i--)
        for(int j = len; j > 0; j--){
            if(trees.find(i*2000+j) != trees.end()) continue;
            dp[i][j] = min(dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j]))+1;
            ret = max(ret, dp[i][j]);
        }
    cout << ret << '\n';
    return 0;
}
