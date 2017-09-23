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

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, S, mysteryLevels [20], dp [1<<12][20];
set<pair<int, int>> states [1<<12];

void generateIt(int index, int oriMask, int takenMask){
    if(index == N){
        if(__builtin_popcount(takenMask)%2 == 1){
            int otherMask = oriMask&(~takenMask);
            states[oriMask].insert({takenMask, otherMask});
        }
        return;
    }
    if((oriMask&(1<<index)) > 0) generateIt(index+1, oriMask, takenMask|(1<<index));
    generateIt(index+1, oriMask, takenMask);
}

int solveIt(int mask, int sparklers){
    if(dp[mask][sparklers] != -1) return dp[mask][sparklers];
    dp[mask][sparklers] = 0;
    for(int i = 0; i < N; i++){
        if((mask&(1<<i)) == 0) continue;
        if((mask^(1<<i)) == 0){
            dp[mask][sparklers] = (mysteryLevels[i]+sparklers)*(mysteryLevels[i]+sparklers)+sparklers;
            break;
        }
        for(pair<int, int> p : states[mask^(1<<i)])
            for(int a = 0; a <= sparklers; a++)
                for(int b = 0; b <= sparklers-a; b++){
                    int c = sparklers-a-b;
                    dp[mask][sparklers] = max(dp[mask][sparklers], min((mysteryLevels[i]+c)*(mysteryLevels[i]+c),
                                            solveIt(p.first, a)*solveIt(p.second, b))+c);
                }
    }
    return dp[mask][sparklers];
}

int main(){
    //freopen("art2.in", "r", stdin); freopen("art2.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> S; memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++) cin >> mysteryLevels[i];
    for(int i = 0; i < (1<<N); i++) generateIt(0, i, 0);
    cout << solveIt((1<<N)-1, S) << '\n';
    return 0;
}
