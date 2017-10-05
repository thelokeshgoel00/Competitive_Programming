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

int N, D, lo = 0, hi = 0, ret = 10000000;
pair<int, int> points [100010];
multiset<int> tiempos;

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d %d", &N, &D);
    for(int i = 0; i < N; i++) scanf("%d %d", &points[i].first, &points[i].second);
    sort(points, points+N);
    tiempos.insert(points[0].second);
    while(true){
        int curLen = *tiempos.rbegin()-*tiempos.begin();
        if(curLen < D){
            hi++; if(hi == N) break;
            tiempos.insert(points[hi].second);
        }
        else{
            ret = min(ret, points[hi].first-points[lo].first);
            auto it = tiempos.find(points[lo].second); tiempos.erase(it); lo++;
        }
    }
    if(ret == 10000000) ret = -1;
    printf("%d\n", ret);
    return 0;
}
