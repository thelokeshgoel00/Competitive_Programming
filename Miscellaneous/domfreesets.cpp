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
#define INF 1000000000000
#define MOD 1000000007

int N;
pair<int, int> points [100010];
long long ret = 0ll, tree [100010];

void add(int pos, long long x){
    while(pos < 100010){
        tree[pos] = (tree[pos]+x)%MOD;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long sum = 0ll;
    while(pos > 0){
        sum = (sum+tree[pos])%MOD;
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    scanf("%d", &N); memset(tree, 0ll, sizeof(tree));
    for(int i = 0; i < N; i++) scanf("%d %d", &points[i].first, &points[i].second);
    sort(points, points+N); add(100005, 1ll);
    for(int i = 0; i < N; i++){
        long long addend = (query(100008)-query(points[i].second)+MOD)%MOD;
        add(points[i].second, addend); ret = (ret+addend)%MOD;
    }
    cout << ret << '\n';
}
