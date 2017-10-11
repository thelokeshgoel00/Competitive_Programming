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

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N;
priority_queue<long long> planks;
long long ret = 0ll;

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        long long x; cin >> x;
        planks.push(-x);
    }
    for(int i = 1; i < N; i++){
        long long a = -planks.top(); planks.pop();
        long long b = -planks.top(); planks.pop();
        ret += a+b; planks.push(-(a+b));
    }
    cout << ret << '\n';
    return 0;
}
