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

int N, G, B, D, nextCheapest [50010];
pair<int, long long> stations [50010]; // first = pos, second = cost
stack<int> stacky;
long long ret = 0ll;

int main(){
    freopen("fuel.in", "r", stdin); freopen("fuel.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> G >> B >> D;
    for(int i = 0; i < N; i++) cin >> stations[i].first >> stations[i].second;
    sort(stations, stations+N);
    for(int i = N-1; i > -1; i--){
        while(stacky.size() > 0 && stations[stacky.top()].second >= stations[i].second) stacky.pop();
        nextCheapest[i] = stacky.size() == 0 ? -1 : stacky.top();
        stacky.push(i);
    }
    B -= stations[0].first;
    for(int i = 0; i < N; i++){
        if(B < 0){ ret = -1; break; }
        int gasNeeded = min(G, (nextCheapest[i] == -1 ? D : stations[nextCheapest[i]].first)-stations[i].first);
        if(gasNeeded > B){
            ret += (long long)(gasNeeded-B)*stations[i].second;
            B = gasNeeded;
        }
        B -= (i == N-1 ? D : stations[i+1].first)-stations[i].first;
    }
    if(B < 0) ret = -1;
    cout << ret << '\n';
    return 0;
}
