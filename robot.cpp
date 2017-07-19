#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

int N;
double dp [1010], penalties [1010];
pair<double, double> checkpts [1010];

double dist(int a, int b){
    return sqrt(pow(checkpts[a].first-checkpts[b].first, 2)+pow(checkpts[a].second-checkpts[b].second, 2));
}

int main(){
    checkpts[1] = make_pair(0.0, 0.0); penalties[1] = 0.0; dp[1] = 0.0;
    while(true){
        cin >> N;
        if(N == 0) break;
        for(int i = 2; i <= N+1; i++){
            cin >> checkpts[i].first >> checkpts[i].second >> penalties[i];
            penalties[i] += penalties[i-1];
        }
        checkpts[N+2] = make_pair(100.0, 100.0); penalties[N+2] = penalties[N-1];
        for(int i = 2; i <= N+2; i++){
            dp[i] = 10000000.0;
            for(int last = 1; last < i; last++) dp[i] = min(dp[i], dp[last]+1+dist(i, last)+penalties[i-1]-penalties[last]);
        }
        printf("%.3lf\n", dp[N+2]);
    }
    return 0;
}
