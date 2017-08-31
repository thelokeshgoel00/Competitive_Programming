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

int N;
long long M, ret = 0ll;
vector<long long> starts, fins;

int main(){
    freopen("taxi.in", "r", stdin); freopen("taxi.out", "w", stdout);
    scanf("%d %lld", &N, &M);
    for(int i = 0; i < N; i++){
        long long x, y; scanf("%lld %lld", &x, &y);
        ret += abs(x-y);
        starts.push_back(x); fins.push_back(y);
    }
    starts.push_back(M); fins.push_back(0);
    sort(starts.begin(), starts.end()); sort(fins.begin(), fins.end());
    for(int i = 0; i < N+1; i++) ret += abs(starts[i]-fins[i]);
    printf("%lld\n", ret);
    return 0;
}
