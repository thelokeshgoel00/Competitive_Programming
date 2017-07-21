#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>

using namespace std;

int n, arr [100001], dp [100001][5][2];

int recurse(int index, int chompsTaken, int lastTaken){
    if(dp[index][chompsTaken][lastTaken] != -1) return dp[index][chompsTaken][lastTaken];
    if(index == n || chompsTaken == 4) return dp[index][chompsTaken][lastTaken] = 0;
    int ret = 0;
    if(lastTaken == 1) ret = max(recurse(index+1, chompsTaken, 1)+arr[index], recurse(index+1, chompsTaken+1, 0));
    else ret = max(recurse(index+1, chompsTaken, 1)+arr[index], recurse(index+1, chompsTaken, 0));
    return dp[index][chompsTaken][lastTaken] = ret;
}

int main(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << recurse(0, 0, 0) << '\n';
    return 0;
}
