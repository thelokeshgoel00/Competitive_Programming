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
#include <sstream>
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, lo, hi, ret;
double C, arr [20], probs [1<<20], mult [1<<20];

double fastPow(double base, int expo){
    if(expo == 0) return 1.0;
    double res = pow(fastPow(base, expo/2), 2.0);
    if(expo%2) res *= base;
    return res;
}

bool checkIt(int cards){
    double p = 0.0;
    for(int mask = 0; mask < (1<<N); mask++) p += fastPow(probs[mask], cards)*mult[mask];
    return p >= C;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> N >> C; lo = N; hi = 1000000;
    for(int i = 0; i < N; i++){
        double a, b; cin >> a >> b;
        arr[i] = a/b;
    }
    for(int mask = 0; mask < (1<<N); mask++){
        probs[mask] = 1.0; mult[mask] = 1.0;
        for(int i = 0; i < N; i++)
            if(mask&(1<<i)){
                probs[mask] -= arr[i];
                mult[mask] *= -1.0;
            }
    }
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(checkIt(mid)){ hi = mid-1; ret = mid; }
        else lo = mid+1;
    }
    cout << ret << '\n';
    return 0;
}
