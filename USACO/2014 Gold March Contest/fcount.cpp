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

int N, degree [510], total = 0, cumSum [510];
vector<int> ret, inUse;

// Functions Based on Use of Theorem: https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Gallai_theorem

int helpIt(int curr){
    int sum = 0;
    for(int i = curr; i <= N; i++) sum += min(curr-1, inUse[i]);
    return sum;
}

bool checkIt(int toRemove){
    inUse.clear();
    for(int i = 0; i < N+1; i++)
        if(i != toRemove)
            inUse.push_back(degree[i]);
    sort(inUse.begin(), inUse.end()); inUse.push_back(0);
    reverse(inUse.begin(), inUse.end());
    cumSum[0] = 0;
    for(int i = 1; i <= N; i++) cumSum[i] = cumSum[i-1]+inUse[i];
    for(int i = 1; i <= N; i++)
        if(cumSum[i] > i*(i-1)+helpIt(i+1))
            return false;
    return true;
}

int main(){
    freopen("fcount.in", "r", stdin); freopen("fcount.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(3);
    cin >> N;
    for(int i = 0; i < N+1; i++){
        cin >> degree[i];
        total += degree[i];
    }
    for(int i = 0; i < N+1; i++)
        if((total-degree[i])%2 == 0 && checkIt(i))
            ret.push_back(i+1);
    cout << ret.size() << endl;
    for(int i = 0; i < ret.size(); i++) cout << ret[i] << '\n';
    return 0;
}
