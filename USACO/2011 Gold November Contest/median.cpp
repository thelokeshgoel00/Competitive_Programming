#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

int numCows, goal, curr = 100003;
long long tree [200010], ret = 0ll;

void add(int pos, long long x){
    while(pos < 200010){
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
    freopen("median.in", "r", stdin); freopen("median.out", "w", stdout);
    scanf("%d %d", &numCows, &goal);
    add(curr, 1ll);
    for(int i = 1; i <= numCows; i++){
        int x; scanf("%d", &x);
        if(x < goal) curr--;
        else curr++;
        ret += query(curr); add(curr, 1ll);
    }
    cout << ret << endl;
    return 0;
}
