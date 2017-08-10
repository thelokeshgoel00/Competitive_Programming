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

int N, K, comboLen [30], contains [30][30], attach [30][30], dp [1010][30], ret = 0;
char combos [30][30];

bool isMatch(int a, int b, int offset){ //Last "offset" characters of "a" match the first "offset" characters of "b"
    int aLen = comboLen[a], bLen = comboLen[b], aStart = aLen-(bLen-offset);
    return strncmp(combos[a]+aStart, combos[b], bLen-offset) == 0;
}

int main(){
    freopen("combos.in", "r", stdin); freopen("combos.out", "w", stdout);
    scanf("%d %d", &N, &K);
    memset(contains, 0, sizeof(contains)); memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++){
        scanf("%s", &combos[i]);
        comboLen[i] = strlen(combos[i]);
    }
    for(int i = 0; i < N; i++){
        int fin = comboLen[i], offset = 0;
        while(fin > -1){
            int freq = 0;
            for(int j = 0; j < N; j++)
                if(fin >= comboLen[j] && strncmp(combos[i]+fin-comboLen[j], combos[j], comboLen[j]) == 0)
                    freq++;
            contains[i][offset+1] = contains[i][offset]+freq;
            fin--; offset++;
        }
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int len = max(1, comboLen[j]-comboLen[i]); len <= comboLen[j]; len++)
                if(isMatch(i, j, len)){
                    attach[i][j] = len;
                    break;
                }
    for(int i = 0; i < N; i++) dp[comboLen[i]][i] = contains[i][comboLen[i]];
    for(int k = 0; k <= K; k++)
        for(int i = 0; i < N; i++){
            if(dp[k][i] < 0) continue;
            ret = max(ret, dp[k][i]);
            for(int j = 0; j < N; j++){
                int next = k+attach[i][j];
                if(next <= K) dp[next][j] = max(dp[next][j], dp[k][i]+contains[j][attach[i][j]]);
            }
        }
    cout << ret << '\n';
    return 0;
}
