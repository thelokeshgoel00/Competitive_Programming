#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int N, numQueries;
bool start;
long long tree [1<<20], arr [1<<20];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1) + 1; }

void build(int p, int L, int R, bool isOR){
    if(L == R) tree[p] = arr[L];
    else{
        build(left(p), L, (L+R)/2, !isOR); build(right(p), (L+R)/2+1, R, !isOR);
        if(isOR) tree[p] = tree[left(p)] | tree[right(p)];
        else tree[p] = tree[left(p)] ^ tree[right(p)];
    }
}
void update(int p, int L, int R, bool isOR, int place, long long val){
    if(L > R || L > place || R < place) return;
    if(L == R && L == place){
        tree[p] = val;
        return;
    }
    update(left(p), L, (L+R)/2, !isOR, place, val); update(right(p), (L+R)/2+1, R, !isOR, place, val);
    if(isOR) tree[p] = tree[left(p)] | tree[right(p)];
    else tree[p] = tree[left(p)] ^ tree[right(p)];
}

int main(){
    scanf("%d %d", &N, &numQueries); start = N%2 == 1; N = 1<<N;
    for(int i = 1; i <= N; i++){
        int temp; scanf("%d", &temp);
        arr[i] = (long long)temp;
    }
    build(1, 1, N, start);
    for(int i = 0; i < numQueries; i++){
        int x; int y; scanf("%d %d", &x, &y);
        update(1, 1, N, start, x, (long long)y);
        cout << tree[1] << endl;
    }
    return 0;
}
