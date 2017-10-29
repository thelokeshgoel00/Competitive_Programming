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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, arr [100010], cumSum [100010];
long long tree [100010], curr = 0ll, ret = 0ll;
map<int, int> sumToIndex;

void add(int pos, long long x){
    while(pos < 100010){
        tree[pos] = (tree[pos]+x)%(MOD+2ll);
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long sum = 0ll;
    while(pos > 0){
        sum = (sum+tree[pos])%(MOD+2ll);
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(tree, 0ll, sizeof(tree)); cumSum[0] = 0;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        cumSum[i] = arr[i]+cumSum[i-1];
    }
    sort(cumSum, cumSum+N+1);
    for(int i = 0, id = 1; i <= N; i++)
        if(sumToIndex.find(cumSum[i]) == sumToIndex.end())
            sumToIndex[cumSum[i]] = id++;
    add(sumToIndex[0], 1ll);
    for(int i = 1; i <= N; i++){
        curr += arr[i];
        int idx = sumToIndex[curr];
        ret = query(idx); add(idx, ret);
    }
    cout << ret << '\n';
    return 0;
}
