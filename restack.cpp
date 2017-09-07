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
#define INF 1000000000000000000
#define MOD 1000000007

int N, original [100010], desired [100010], moves [100010];
long long ret = 0ll;

int main(){
    freopen("restack.in", "r", stdin); freopen("restack.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d %d", &original[i], &desired[i]);
    moves[0] = original[0]-desired[0];
    for(int i = 1; i < N; i++) moves[i] = moves[i-1]+original[i]-desired[i];
    sort(moves, moves+N);
    for(int i = 0; i < N; i++) ret += abs(moves[i]-moves[N/2]);
    cout << ret << '\n';
    return 0;
}
