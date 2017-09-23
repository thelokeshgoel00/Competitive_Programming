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

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, K;
long long arr [200010], currSum = 0, ret = 0;
deque<pair<long long, long long>> dq;

int main(){
    //freopen("art2.in", "r", stdin); freopen("art2.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++){ cin >> arr[i]; arr[i+N] = arr[i]; }
    for(int i = 0; i < 2*N; i++){
        currSum += arr[i];
        if(dq.size() == 0) ret = max(ret, currSum);
        else{
            while(dq.size() > 0 && i-dq.front().second > K) dq.pop_front();
            ret = max(ret, currSum-dq.front().first);
            while(dq.size() > 0 && dq.back().first >= currSum) dq.pop_back();
        }
        dq.push_back({currSum, i});
    }
    cout << ret << '\n';
    return 0;
}
