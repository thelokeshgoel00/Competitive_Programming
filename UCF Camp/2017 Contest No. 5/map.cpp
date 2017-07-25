#define __USE_MINGW_ANSI_STDIO 0
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

int n, q, num, a, b;
long long tree [100001], total = 0, ret;

void add(int pos, long long val){
    while(pos <= n){
        tree[pos] += val;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    cin >> n >> q; memset(tree, 0, sizeof(tree));
    for(int i = 0; i < q; i++){
        cin >> num >> a >> b;
        if(num == 1){ total += b; add(a, b); continue; }
        ret = query(b)-query(a-1);
        if(a > b) ret += total;
        cout << ret << '\n';
    }
    return 0;
}
