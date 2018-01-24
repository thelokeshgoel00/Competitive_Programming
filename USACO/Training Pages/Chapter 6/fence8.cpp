/*
ID: vamaddu1
PROG: fence8
LANG: C++11
*/

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
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, R, boards [60], boardSum = 0, shifty = -1, rails [1050], cumSum [1050], lo, hi, mid, ret;

bool searchIt(int boardNum, int railNum, int curWasted){
    if(railNum == 0) return true;
    if(curWasted > boardSum-cumSum[mid]) return false;
    if(boardNum != 0 && rails[railNum] != rails[railNum+1]) boardNum = 0;
    for(int i = boardNum; i < N; i++){
        if(boards[i] < rails[railNum]) continue;
        boards[i] -= rails[railNum];
        int nWasted = curWasted;
        if(boards[i] < rails[1]) nWasted += boards[i];
        bool good = searchIt(i, railNum-1, nWasted);
        boards[i] += rails[railNum];
        if(good) return true;
    }
    return false;
}

int main(){
    freopen("fence8.in", "r", stdin); freopen("fence8.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){ cin >> boards[i]; boardSum += boards[i]; }
    cin >> R; lo = 0; hi = R; cumSum[0] = 0;
    for(int i = 1; i <= R; i++) cin >> rails[i];
    sort(boards, boards+N); sort(rails+1, rails+R+1);
    for(int i = 1; i <= R; i++) cumSum[i] = cumSum[i-1]+rails[i];
    for(int i = 0; i < N; i++){
        if(boards[i] < rails[1]){ boardSum -= boards[i]; continue; }
        if(shifty == -1) shifty = i;
        boards[i-shifty] = boards[i];
    }
    if(shifty == -1){
        cout << "0\n";
        return 0;
    }
    N -= shifty;
    while(cumSum[hi] > boardSum) hi--;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(searchIt(0, mid, 0)){
            lo = mid+1;
            ret = mid;
        }
        else hi = mid-1;
    }
    cout << ret << '\n';
    return 0;
}
