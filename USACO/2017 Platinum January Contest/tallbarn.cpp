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

int N;
long long K, arr [100010], workersUsed = 0;
double loBenefit = 0.0, hiBenefit = INF, totalTime = 0.0;

long long calcIt(double x){
    long long sum = 0ll;
    for(int i = 0; i < N; i++) sum += (long long)((sqrt(1.0+4.0*(double)arr[i]/x)-1)/2.0);
    return sum;
}

int main(){
    freopen("tallbarn.in", "r", stdin); freopen("tallbarn.out", "w", stdout);
    scanf("%d %lld", &N, &K); K -= N;
    for(int i = 0; i < N; i++) scanf("%lld", &arr[i]);
    while(loBenefit+epsilon < hiBenefit){
        double mid = (loBenefit+hiBenefit)/2.0;
        if(calcIt(mid) >= K) loBenefit = mid;
        else hiBenefit = mid;
    }
    for(int i = 0; i < N; i++){
        long long temp = (long long)((sqrt(1.0+4.0*(double)arr[i]/loBenefit)-1)/2.0);
        totalTime += (double)arr[i]/(double)(temp+1ll); workersUsed += temp;
    }
    cout << (long long)round(totalTime-(K-workersUsed)*loBenefit) << '\n';
    return 0;
}
