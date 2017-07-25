#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

struct BIT{
    int maxi;
    long long tree [200002];
    BIT(int m): maxi(m) {}
    void add(int pos, long long x){
        while(pos <= maxi){
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
};

int numCows, goal, curr = 100001;
long long ret = 0;

int main(){
    freopen("median.in", "r", stdin); freopen("median.out", "w", stdout);
    scanf("%d %d", &numCows, &goal);
    BIT fenwick(200001); fenwick.add(curr, 1);
    for(int i = 1; i <= numCows; i++){
        int x; scanf("%d", &x);
        if(x < goal) curr--;
        else curr++;
        ret += fenwick.query(curr); fenwick.add(curr, 1);
    }
    cout << ret << endl;
    return 0;
}
