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

int N, K, lo, hi, ret = -1;
long long arr [100010], powa [100010];
unordered_map<long long, int> hashFreq;

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    powa[0] = 1ll; for(int i = 1; i < 100010; i++) powa[i] = powa[i-1]*1000003ll;
    scanf("%d %d", &N, &K); lo = 1; hi = N;
    for(int i = 0; i < N; i++) scanf("%lld", &arr[i]);
    while(lo <= hi){
        int mid = (lo+hi)/2; bool good = false; hashFreq.clear();
        long long curHash = 0ll;
        for(int i = 0; i < mid; i++) curHash = curHash*1000003ll+arr[i];
        hashFreq[curHash]++;
        for(int i = mid; i < N; i++){
            curHash = curHash*1000003ll-powa[mid]*arr[i-mid]+arr[i];
            if(++hashFreq[curHash] >= K) { good = true; break; }
        }
        if(good){ lo = mid+1; ret = mid; }
        else hi = mid-1;
    }
    printf("%d\n", ret);
    return 0;
}
