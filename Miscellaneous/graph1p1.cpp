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

int N, K, ori [110][110], ret [110][110], summy = 0;

void matrixMult(int a [110][110], int b [110][110], int c [110][110]){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                c[i][j] += (a[i][k]*b[k][j]);
}

void matrixExpo(int expo){
    int temp [110][110];
    for(int i = 8; i > -1; i--){
        memset(temp, 0, sizeof(temp));
        matrixMult(ret, ret, temp);
        for(int a = 0; a < N; a++)
            for(int b = 0; b < N; b++)
                ret[a][b] = temp[a][b];
        if((expo&(1<<i)) > 0){
            memset(temp, 0, sizeof(temp));
            matrixMult(ret, ori, temp);
            for(int a = 0; a < N; a++)
                for(int b = 0; b < N; b++)
                    ret[a][b] = temp[a][b];
        }
    }
}

// Alternative Approach to the Above: http://wcipeg.com/submissions/src/327471

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d %d", &N, &K); memset(ret, 0, sizeof(ret));
    for(int i = 0; i < N; i++){
        ret[i][i] = 1;
        for(int j = 0; j < N; j++) scanf("%d", &ori[i][j]);
    }
    matrixExpo(K);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            summy += ret[i][j];
    cout << summy << '\n';
    return 0;
}
