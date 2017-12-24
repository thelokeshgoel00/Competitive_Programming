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

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, newPos [100010], lo, hi, minStuck;

bool checkIt(int mid){
    vector<int> temp;
    for(int i = 0; i < mid; i++) temp.push_back(newPos[i]);
    sort(temp.begin(), temp.end());
    for(int i = mid; i > 0; i--)
        if(temp[i-1] < i)
            return true;
    return false;
}

int main(){
    freopen("greedy.in", "r", stdin); freopen("greedy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; lo = 1; hi = N;
    for(int i = 0; i < N; i++){
        cin >> newPos[i];
        newPos[i] = N-1-newPos[i];
    }
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(checkIt(mid)){
            hi = mid-1;
            minStuck = mid;
        }
        else lo = mid+1;
    }
    cout << N-minStuck << '\n';
    return 0;
}
