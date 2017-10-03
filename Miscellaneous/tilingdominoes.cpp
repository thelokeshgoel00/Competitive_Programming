#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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

int N, M;
vector<int> nextMask [1050];
long long dp [110][1050];

void generateIt(int oldMask, int index, int curMask){
    if(index == M){
        nextMask[oldMask].push_back(curMask);
        return;
    }
    if((oldMask&(1<<index)) > 0) generateIt(oldMask, index+1, curMask);
    else{
        generateIt(oldMask, index+1, curMask|(1<<index));
        if(index < M-1 && (oldMask&(1<<(index+1))) == 0) generateIt(oldMask, index+2, curMask);
    }
}

long long solveIt(int row, int mask){
    if(dp[row][mask] != -1) return dp[row][mask];
    if(row == N) return dp[row][mask] = mask == 0;
    dp[row][mask] = 0ll;
    for(int lolMask : nextMask[mask]) dp[row][mask] += solveIt(row+1, lolMask);
    return dp[row][mask];
}

int main(){
    while(scanf("%d %d", &N, &M) == 2){
        if((N*M)%2 == 1){ printf("0\n"); continue; }
        if(N < M) swap(N, M);
        memset(dp, -1ll, sizeof(dp));
        for(int i = 0; i < (1<<M); i++){
            nextMask[i].clear();
            generateIt(i, 0, 0);
        }
        printf("%lld\n", solveIt(0, 0));
    }
    return 0;
}
