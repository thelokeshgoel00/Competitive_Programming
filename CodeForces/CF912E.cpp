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
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N;
vector<long long> li, ri, masterone, mastertwo;
long long K, lo = 1, hi = INF/5;

void generateIt(vector<long long> &primes, vector<long long> &addTo, int idx = 0, long long curr = 1, long long maxi = INF/5){
    if(idx == primes.size()){ addTo.push_back(curr); return; }
    while(maxi > 0){
        generateIt(primes, addTo, idx+1, curr, maxi);
        curr *= primes[idx]; maxi /= primes[idx];
    }
}

long long checkIt(long long mid){
    long long idx = mastertwo.size()-1, ret = 0;
    for(int i = 0; i < masterone.size(); i++){
        while(idx > -1 && masterone[i] > mid/mastertwo[idx]) idx--;
        ret += idx+1;
    }
    return ret;
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){
        long long primer; cin >> primer;
        if(i%2 == 0) li.push_back(primer);
        else ri.push_back(primer);
    }
    cin >> K;
    generateIt(li, masterone); generateIt(ri, mastertwo);
    sort(masterone.begin(), masterone.end()); sort(mastertwo.begin(), mastertwo.end());
    while(lo < hi){
        long long mid = (lo+hi)/2;
        if(checkIt(mid) >= K) hi = mid;
        else lo = mid+1;
    }
    cout << lo << '\n';
    return 0;
}
