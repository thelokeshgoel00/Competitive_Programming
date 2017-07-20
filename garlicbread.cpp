#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>

using namespace std;

int n, dp [1001], ret = 1;
long long slope, ratings [1001];

int main(){
    cin >> n >> slope;
    for(int i = 0; i < n; i++) cin >> ratings[i];
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(ratings[i]-ratings[j] >= (long long)(i-j)*slope)
                dp[i] = max(dp[i], 1+dp[j]);
        ret = max(ret, dp[i]);
    }
    cout << ret << '\n';
    return 0;
}
