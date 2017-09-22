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

int N, arr [100010], firstSeen [100010], lastSeen [100010], ret = 0;
stack<int> stuff;

int main(){
    freopen("art2.in", "r", stdin); freopen("art2.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill(firstSeen, firstSeen+100010, 100010); fill(lastSeen, lastSeen+100010, -1);
    cin >> N; arr[0] = arr[N+1] = 0;
    for(int i = 0; i <= N+1; i++){
        if(i > 0 && i < N+1) cin >> arr[i];
        firstSeen[arr[i]] = min(firstSeen[arr[i]], i);
        lastSeen[arr[i]] = max(lastSeen[arr[i]], i);
    }
    for(int i = 0; i <= N+1; i++){
        if(firstSeen[arr[i]] == i){ stuff.push(arr[i]); ret = max(ret, (int)stuff.size()); }
        if(stuff.top() != arr[i]){ cout << "-1\n"; return 0; }
        if(lastSeen[arr[i]] == i) stuff.pop();
    }
    cout << ret-1 << '\n';
    return 0;
}
