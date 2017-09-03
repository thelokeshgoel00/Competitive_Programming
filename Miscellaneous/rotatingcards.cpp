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

int kase, n, indices [100010], topIndex;
long long tree [100010], ret, total;

void add(int pos, long long x){
    while(pos < 100010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long sum = 0ll;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    //freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d", &kase);
    for(int kk = 1; kk <= kase; kk++){
        memset(tree, 0ll, sizeof(tree)); ret = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            int x; scanf("%d", &x);
            indices[x] = i; total += x;
            add(i, x);
        }
        long long temp = query(indices[1]-1);
        ret += min(temp, total-temp); add(indices[1], -1); topIndex = indices[1]; total--;
        for(int i = 2; i <= n; i++){
            long long takeTop, takeBot;
            if(indices[i] > topIndex){
                takeTop = query(indices[i]-1)-query(topIndex);
                takeBot = total-query(indices[i]-1)+query(topIndex);
            }
            else{
                takeTop = total-query(topIndex-1)+query(indices[i]-1);
                takeBot = query(topIndex)-query(indices[i]-1);
            }
            ret += min(takeBot, takeTop); add(indices[i], -i); topIndex = indices[i];
            total -= i;
        }
        printf("%lld\n", ret);
    }
    return 0;
}
