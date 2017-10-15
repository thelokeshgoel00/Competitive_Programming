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

int N;
vector<long long> jumps [100010];
long long K, baseCost = 0ll, minJump [100010], lo = 0ll, hi = 0ll, totalCount, savings = 0ll, ret;

void searchIt(int partNum, long long budget){
    if(totalCount >= K) return;
    if(partNum != -1 && budget < jumps[partNum][0]) partNum = (upper_bound(minJump, minJump+partNum, budget)-minJump)-1;
    if(partNum == -1){ totalCount++; return; }
    searchIt(partNum-1, budget);
    for(int i = 0; i < jumps[partNum].size() && jumps[partNum][i] <= budget; i++)
        searchIt(partNum-1, budget-jumps[partNum][i]);
}

void findSavings(int partNum, long long budget){
    if(partNum != -1 && budget < jumps[partNum][0]) partNum = (upper_bound(minJump, minJump+partNum, budget)-minJump)-1;
    if(partNum == -1){ savings += budget+1; return; }
    findSavings(partNum-1, budget);
    for(int i = 0; i < jumps[partNum].size() && jumps[partNum][i] <= budget; i++)
        findSavings(partNum-1, budget-jumps[partNum][i]);
}

int main(){
    freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int variants; vector<int> parts; cin >> variants;
        for(int j = 0; j < variants; j++){
            long long x; cin >> x;
            parts.push_back(x);
        }
        sort(parts.begin(), parts.end()); baseCost += parts[0];
        if(variants == 1){ N--; i--; continue; }
        for(int j = 1; j < variants; j++) jumps[i].push_back(parts[j]-parts[0]);
        hi += jumps[i].back();
    }
    sort(jumps, jumps+N); for(int i = 0; i < N; i++) minJump[i] = jumps[i][0];
    while(lo < hi){
        long long mid = (lo+hi)/2; totalCount = 0;
        searchIt(N-1, mid);
        if(totalCount < K) lo = mid+1ll;
        else hi = mid;
    }
    findSavings(N-1, lo-1ll); ret = (baseCost+lo)*K-savings;
    cout << ret << '\n';
    return 0;
}
