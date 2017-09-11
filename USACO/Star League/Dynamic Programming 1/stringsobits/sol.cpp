/*
ID: vamaddu1
LANG: C++11
TASK: kimbits
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

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000
#define MOD 1000000007

int N, L;
long long combo [32][32], I;
string ret = "";

int main(){
    freopen("kimbits.in", "r", stdin); freopen("kimbits.out", "w", stdout);
    scanf("%d %d %lld", &N, &L, &I); memset(combo, 0ll, sizeof(combo));
    for(int i = 0; i < 32; i++) combo[i][0] = combo[0][i] = 1;
    for(int i = 1; i < 32; i++)
        for(int j = 1; j < 32; j++)
            combo[i][j] = combo[i-1][j]+combo[i-1][j-1];
    for(int i = 0; i < N; i++){
        if(combo[N-1-i][L] < I){
            I -= combo[N-1-i][L]; L--;
            ret += "1";
        }
        else ret += "0";
    }
    cout << ret << '\n';
    return 0;
}
