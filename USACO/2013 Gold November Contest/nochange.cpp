#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

using namespace std;

int K, N, coins [16], cumSum [100001], dp [1<<16], ret = -1, temp;

int main(){
    freopen("nochange.in", "r", stdin); freopen("nochange.out", "w", stdout);
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; i++){ scanf("%d", &temp); coins[i] = temp; }
    for(int i = 1; i <= N; i++){ scanf("%d", &temp); cumSum[i] = cumSum[i-1]+temp; }
    for(int mask = 1; mask < (1<<K); mask++){
        int rem = 0;
        for(int i = 0; i < K; i++){
            int x = 1<<i;
            if((mask&x) == 0){ rem += coins[i]; continue; }
            int past = dp[mask^x]; int paid = cumSum[past];
            int lo = past; int hi = N; int pos = lo;
            while(lo <= hi){
                int mid = (lo+hi)/2;
                if(paid+coins[i] >= cumSum[mid]){ pos = mid; lo = mid+1; }
                else hi = mid-1;
            }
            dp[mask] = max(dp[mask], pos);
        }
        if(dp[mask] == N) ret = max(ret, rem);
    }
    cout << ret << endl;
    return 0;
}
