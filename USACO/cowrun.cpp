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

int N, M, K, cards [150], curPos = 0;
string bessieMoves;

int calcIt(int y, int x, int a, int b){ return (1ll*x*(cards[8*y+4*a+2*b]+1)+cards[8*y+4*a+2*b+1])%M; }

bool solveAnd(int y, int x, bool a);

bool solveOr(int y, int x){
    if(y == N) return x <= K || x+K >= M;
    bool shuffle = rand()&1;
    return solveAnd(y, x, shuffle) || solveAnd(y, x, !shuffle);
}

bool solveAnd(int y, int x, bool a){
    bool shuffle = rand()&1;
    return solveOr(y+1, calcIt(y, x, a, shuffle)) && solveOr(y+1, calcIt(y, x, a, !shuffle));
}

int main(){
    freopen("cowrun.in", "r", stdin); freopen("cowrun.out", "w", stdout);
    cin >> N >> M >> K >> bessieMoves;
    for(int i = 0; i < 8*N; i++) cin >> cards[i];
    for(int i = 0; i < N; i++){
        if(solveAnd(i, curPos, true)){
            cout << 'B';
            curPos = calcIt(i, curPos, true, bessieMoves[i] == 'B');
        }
        else{
            cout << 'T';
            curPos = calcIt(i, curPos, false, bessieMoves[i] == 'B');
        }
    }
    cout << '\n';
    return 0;
}
