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
#define INF 5000000000000000000
#define MOD 1000000007

int N, Q, arr [200010], blockNum [200010], nexts [200010], blockSum [200010];

int query(int x){
    int ret = 0;
    while(x < N){
        ret += blockSum[x];
        x = nexts[x];
    }
    return ret;
}

void update(int x, int v){
    arr[x] = v;
    for(int i = x; i > -1 && blockNum[i] == blockNum[x]; i--){
        if(i+arr[i] >= N || blockNum[i+arr[i]] != blockNum[x]){
            blockSum[i] = 1;
            nexts[i] = i+arr[i];
        }
        else{
            blockSum[i] = blockSum[i+arr[i]]+1;
            nexts[i] = nexts[i+arr[i]];
        }
    }
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){ cin >> arr[i]; blockNum[i] = i/(int)(sqrt(N)); }
    for(int i = N-1; i > -1; i--){
        if(i+arr[i] >= N || blockNum[i+arr[i]] != blockNum[i]){
            blockSum[i] = 1;
            nexts[i] = i+arr[i];
        }
        else{
            blockSum[i] = blockSum[i+arr[i]]+1;
            nexts[i] = nexts[i+arr[i]];
        }
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int q, x, v; cin >> q >> x;
        if(q == 1) cout << query(x) << '\n';
        else{ cin >> v; update(x, v); }
    }
    return 0;
}
