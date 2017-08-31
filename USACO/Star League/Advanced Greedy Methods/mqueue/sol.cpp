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

struct Cow{
    int a, b;
    Cow(){ a = -1; b = -1; }
    bool operator<(const Cow &other) const{
        return max(other.a+other.b+b, other.a+a+b) > max(a+b+other.b, a+other.a+other.b);
    }
};

int N, times [25010], ret = 0;
Cow cows [25010];

int main(){
    //freopen("partition.in", "r", stdin); freopen("partition.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d %d", &cows[i].a, &cows[i].b);
    sort(cows, cows+N); times[0] = cows[0].a;
    for(int i = 1; i < N; i++) times[i] = times[i-1]+cows[i].a;
    for(int i = 0; i < N; i++){
        ret = max(ret, times[i]);
        ret += cows[i].b;
    }
    cout << ret << '\n';
    return 0;
}
