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

int N, maxClique = 0;
double K;
long long adjacency [50];

void recurse(long long mask, int curSize){
    if(mask == 0){
        maxClique = max(maxClique, curSize);
        return;
    }
    while(mask > 0){
        if(__builtin_popcountll(mask)+curSize <= maxClique) return;
        long long nexty = __builtin_ffsll(mask)-1;
        mask ^= (1ll<<nexty);
        recurse(mask&adjacency[nexty], curSize+1);
    }
}

int main(){
    scanf("%d %lf", &N, &K); memset(adjacency, 0ll, sizeof(adjacency));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            int x; scanf("%d", &x);
            if(x == 1) adjacency[i] |= (1ll<<j);
        }
    recurse((1ll<<N)-1ll, 0);
    printf("%.18lf\n", K*K*(double)(maxClique-1)/(2.0*(double)maxClique));
    return 0;
}
