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
#include <sstream>
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, C, L, flag;
double instructions [60][60], arr [60][60];

int nextVar(int i, int curVar) {
    for(int j = curVar; j < C; j++)
        for(int k = i; k < N; k++)
            if(abs(arr[k][j]) > epsilon)
                return j;
    return C;
}

int maxRow(int row, int var){
    int res = row;
    for(int i = row+1; i < N; i++)
        if(abs(arr[i][var]) > abs(arr[res][var]))
            res = i;
    return res;
}

void reduce(int i, int j, int curVar) {
    double fac = arr[j][curVar]/arr[i][curVar];
    for(int k = curVar; k <= C; k++) arr[j][k] -= fac*arr[i][k];
}

bool checkIt(){
    int curVar = 0;
    for(int i = 0; i < N-1; i++){
        curVar = nextVar(i, curVar);
        if(curVar == C) break;
        swap(arr[i], arr[maxRow(i, curVar)]);
        for(int j = i+1; j < N; j++) reduce(i, j, curVar);
        curVar++;
    }
    for(int i = 0; i < N; i++){
        bool zero = true;
        for(int j = 0; j < C; j++)
            if(abs(arr[i][j]) > epsilon){
                zero = false;
                break;
            }
        if(zero && abs(arr[i][C]) > epsilon) return false;
    }
    return true;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> N >> C >> L;
    for(int j = 0; j < C; j++)
        for(int i = 0; i < N; i++)
            cin >> instructions[i][j];
    for(int q = 0; q < L; q++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < C; j++) arr[i][j] = instructions[i][j];
            cin >> arr[i][C];
        }
        cout << (checkIt() ? "YES" : "NO") << '\n';
    }
    return 0;
}
