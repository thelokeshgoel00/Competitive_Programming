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

#define MOD 1000000007

int n, k, arr [2010], pow2 [] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
long long dp [2010][4096];

int transformIt(int mask, int next){
    if(next > (mask&-mask)) return next;
    return mask+next;
}

long long recurse(int pos, int mask){
    if(dp[pos][mask] != -1) return dp[pos][mask];
    if(pos == n) return dp[pos][mask] = mask >= k;
    if(mask >= k) return dp[pos][mask] = arr[pos] == 0 ? (2ll*recurse(pos+1, mask))%MOD : recurse(pos+1, mask);
    dp[pos][mask] = 0;
    if(arr[pos] != 2) dp[pos][mask] = (dp[pos][mask]+recurse(pos+1, transformIt(mask, 4)))%MOD;
    if(arr[pos] != 4) dp[pos][mask] = (dp[pos][mask]+recurse(pos+1, transformIt(mask, 2)))%MOD;
    return dp[pos][mask];
}

int main() {
    scanf("%d %d", &n, &k); k = 1<<k;
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    memset(dp, -1, sizeof(dp));
    cout << recurse(0, 0) << '\n';
    return 0;
}
