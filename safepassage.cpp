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

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, arr [20];

int solveIt(int endPos){
    if(endPos < 2) return arr[endPos];
    if(endPos == 2) return arr[0]+arr[1]+arr[2];
    return min(arr[0]+2*arr[1]+arr[endPos], 2*arr[0]+arr[endPos-1]+arr[endPos])+solveIt(endPos-2);
}

int main(){
    //freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N);
    cout << solveIt(N-1) << '\n';
    return 0;
}
