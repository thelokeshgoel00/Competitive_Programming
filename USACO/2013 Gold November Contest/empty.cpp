#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int N, K, X, Y, total = 0;
long long A, B;
int arr [3000000];

int main(){
    freopen("empty.in", "r", stdin); freopen("empty.out", "w", stdout);
    scanf("%d %d", &N, &K);
    for(int i = 0; i < K; i++){
        scanf("%d %d %lld %lld", &X, &Y, &A, &B);
        for(int j = 1; j <= Y; j++) arr[int((A*(long long)j+B)%N)] += X;
    }
    for(int i = 0; i < N; i++){
        total += arr[i];
        if(total > 0) total--;
    }
    for(int i = 0; i < N; i++){
        total += arr[i];
        if(total > 0) total--;
        else{
            cout << i << endl;
            break;
        }
    }
    return 0;
}
