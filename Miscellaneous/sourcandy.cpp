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

int N, arr [100010], indexOfVal [100010], dp [100010], tree [100010], tree2 [100010], best = 1, lo, hi;
unordered_map<int, int> intToVal;

void add(int pos, int x){
    while(pos < 100010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int ret = 0;
    while(pos > 0){
        ret += tree[pos];
        pos -= (pos&-pos);
    }
    return ret;
}

void add2(int pos, int x){
    while(pos < 100010){
        tree2[pos] += x;
        pos += (pos&-pos);
    }
}

int query2(int pos){
    int ret = 0;
    while(pos > 0){
        ret += tree2[pos];
        pos -= (pos&-pos);
    }
    return ret;
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d", &N); indexOfVal[0] = 100010; dp[0] = 0;
    memset(tree, 0, sizeof(tree)); memset(tree2, 0, sizeof(tree2));
    for(int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    for(int i = 1; i <= N; i++){
        int x; scanf("%d", &x);
        intToVal[x] = i; indexOfVal[i] = 100010;
    }
    for(int i = 1; i <= N; i++){
        arr[i] = intToVal[arr[i]]; indexOfVal[arr[i]] = i; dp[i] = 1;
        if(indexOfVal[arr[i]-1] < i) dp[i] += dp[indexOfVal[arr[i]-1]];
        if(dp[i] > dp[best]) best = i;
    }
    cout << N-dp[best] << '\n';
    hi = arr[best]; lo = hi-dp[best]+1;
    for(int i = lo-1; i >= 1; i--){
        cout << "F " << indexOfVal[i]+query(100005)-query(indexOfVal[i]) << '\n';
        add(indexOfVal[i], 1);
    }
    for(int i = hi+1; i <= N; i++){
        cout << "B " << indexOfVal[i]+query(100005)-query(indexOfVal[i])+query2(indexOfVal[i]) << '\n';
        add2(indexOfVal[i], -1);
    }
    return 0;
}
