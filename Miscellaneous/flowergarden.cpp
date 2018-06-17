#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
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
#include <bitset>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int kase, N, cnt, ret;
double D, currX, currY, used, x [20010], y [20010];
bool isPrime [20010];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    memset(isPrime, true, sizeof(isPrime)); isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < 20010; i++){
        if(!isPrime[i]) continue;
        for(int j = 2*i; j < 20010; j += i) isPrime[j] = false;
    }
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N >> D; currX = currY = used = 0; cnt = ret = 0;
        for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
        while(cnt < N){
            used += sqrt((currX-x[cnt])*(currX-x[cnt]) + (currY-y[cnt])*(currY-y[cnt]));
            if(used > D) break;
            currX = x[cnt]; currY = y[cnt]; cnt++;
            if(isPrime[cnt]) ret = cnt;
        }
        cout << ret << '\n';
    }
    return 0;
}
