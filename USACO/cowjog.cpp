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

int N, length = 1;
long long tiempo, arr [100010];
vector<long long> stuff;

int main(){
    freopen("cowjog.in", "r", stdin); freopen("cowjog.out", "w", stdout);
    scanf("%d %lld", &N, &tiempo);
    for(int i = 0; i < N; i++){
        long long a, b; scanf("%lld %lld", &a, &b);
        arr[i] = a+b*tiempo;
    }
    stuff.push_back(arr[N-1]);
    for(int i = N-2; i > -1; i--){
        if(stuff.back() <= arr[i]) stuff.push_back(arr[i]);
        else{
            auto it = upper_bound(stuff.begin(), stuff.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout << stuff.size() << '\n';
    return 0;
}
