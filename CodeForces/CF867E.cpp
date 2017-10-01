#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N;
priority_queue<long long> pq;
long long ret = 0ll;

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        long long x; scanf("%I64d", &x);
        pq.push(-x);
        int toBuy = -pq.top();
        if(x <= toBuy) continue;
        ret += x-toBuy; pq.pop(); pq.push(-x);
    }
    cout << ret << '\n';
    return 0;
}
