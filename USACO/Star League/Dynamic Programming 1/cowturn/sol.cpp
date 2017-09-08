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

int N, changes [5010], testIt [5010], retK = 1, retMoves = 5010;
char cur = 'F';

int checkIt(int num){
    for(int i = 0; i < N; i++) testIt[i] = changes[i];
    int numero = 0;
    for(int i = 0; i < N-num+1; i++){
        numero += testIt[i];
        testIt[i+num] ^= testIt[i];
    }
    for(int i = N-num+1; i < N; i++)
        if(testIt[i] == 1)
            return 5010;
    return numero;
}

int main(){
    //freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        char c [2]; scanf("%s", &c);
        if(cur != c[0]){ changes[i] = 1; cur = c[0]; }
        else changes[i] = 0;
    }
    for(int i = 1; i <= N; i++){
        int temp = checkIt(i);
        if(temp < retMoves){ retMoves = temp; retK = i; }
    }
    cout << retK << " " << retMoves << '\n';
    return 0;
}
