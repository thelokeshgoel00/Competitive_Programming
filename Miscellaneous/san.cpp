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

int N, LSize = 0, RSize = 0;
long long K, ret = 0;
pair<int, long long> L [25], R [25];
vector<long long> firstHalf [25];

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K;
    for(int i = 0; i < N/2; i++){ cin >> L[i].first >> L[i].second; LSize++; }
    for(int i = N/2; i < N; i++){ cin >> R[i-N/2].first >> R[i-N/2].second; RSize++; }
    for(int mask = 1; mask < (1<<LSize); mask++){
        bool isValid = true; int lasty = -1;
        long long sum = 0;
        for(int i = 0; i < LSize; i++){
            if((mask&(1<<i)) == 0) continue;
            if(lasty != -1 && L[i].first < L[lasty].first){
                isValid = false;
                break;
            }
            lasty = i; sum += L[i].second;
        }
        if(isValid){
            firstHalf[lasty].push_back(sum);
            if(sum >= K) ret++;
        }
    }
    for(int i = 0; i < 25; i++) sort(firstHalf[i].begin(), firstHalf[i].end());
    for(int mask = 1; mask < (1<<RSize); mask++){
        bool isValid = true; int firsty = 25, lasty = -1;
        long long sum = 0;
        for(int i = 0; i < RSize; i++){
            if((mask&(1<<i)) == 0) continue;
            if(lasty != -1 && R[i].first < R[lasty].first){
                isValid = false;
                break;
            }
            firsty = min(firsty, i); lasty = i;
            sum += R[i].second;
        }
        if(!isValid) continue;
        if(sum >= K) ret++;
        for(int i = 0; i < LSize; i++)
            if(R[firsty].first >= L[i].first)
                ret += (firstHalf[i].end()-lower_bound(firstHalf[i].begin(), firstHalf[i].end(), K-sum));
    }
    cout << ret << '\n';
    return 0;
}
