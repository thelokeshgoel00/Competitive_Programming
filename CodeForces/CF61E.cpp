#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int N, arr [1000001], tree [1<<22];
pair<int, int> original [1000001];
long long ret = 0;

int left(int p){ return 1<<p; }
int right(int p){ return (1<<p)+1; }

void update(int p, int val){
    tree[p+=N] = val;
    while(p > 1){
        tree[p>>1] = tree[p]+tree[p^1];
        p = p>>1;
    }
}

int query(int L, int R){
    int sum = 0; L += N; R += N;
    while(L < R){
        if(L&1) sum += tree[L++];
        if(R&1) sum += tree[--R];
        L = L>>1; R = R>>1;
    }
    return sum;
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        int x; scanf("%d", &x);
        original[i] = make_pair(x, i);
    }
    sort(original+1, original+N+1);
    for(int i = 1; i <= N; i++) arr[original[i].second] = i;
    for(int i = 1; i <= N; i++){
        update(arr[i], 1);
        long long a = (long long)(query(arr[i]+1, N+1));
        long long b = (long long)(arr[i]-1-query(1, arr[i]));
        ret += a*b;
    }
    cout << ret << endl;
    return 0;
}
