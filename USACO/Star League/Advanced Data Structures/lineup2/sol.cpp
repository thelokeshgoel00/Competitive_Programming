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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, K, ret = 0;
long long powa [35], cumSum [35], curHash;
unordered_map<long long, int> hashPos;

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    powa[0] = 1ll; for(int i = 1; i < 35; i++) powa[i] = powa[i-1]*1000003ll;
    cin >> N >> K; curHash = 0ll;
    for(int i = 0; i < K; i++){
        cumSum[i] = 0ll;
        if(i != 0) curHash = 1000003ll*curHash+100000;
    }
    hashPos[curHash] = 0ll;
    for(int i = 1; i <= N; i++){
        long long x; cin >> x; curHash = 0ll;
        for(int j = 0; j < K; j++){
            cumSum[j] += ((x&(1<<j)) > 0);
            if(j != 0) curHash = 1000003ll*curHash+(100000+cumSum[j]-cumSum[j-1]);
        }
        if(hashPos.find(curHash) == hashPos.end()) hashPos[curHash] = i;
        else ret = max(ret, i-hashPos[curHash]);
    }
    cout << ret << '\n';
    return 0;
}
