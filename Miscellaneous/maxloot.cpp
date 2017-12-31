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

int kase, N, C, totalVal, vals [65], costs [65], dp [2][(1<<20)+1], ret;
vector<pair<int, int>> L;
set<pair<int, int>> li;

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N >> C; totalVal = ret = 0;
        for(int i = 0; i < N; i++){ cin >> vals[i]; totalVal += vals[i]; }
        for(int i = 0; i < N; i++) cin >> costs[i];
        if(N < 35){
            L = vector<pair<int, int>>(); li = set<pair<int, int>>();
            for(int mask = 0; mask < (1<<(N/2)); mask++){
                int tc = 0, tv = 0;
                for(int i = 0; i < N/2; i++)
                    if((mask&(1<<i)) > 0){
                        tc += costs[i];
                        tv += vals[i];
                    }
                if(tc < C+1){ L.push_back(make_pair(tc, tv)); ret = max(ret, tv); }
            }
            sort(L.begin(), L.end()); li.insert(L[0]);
            for(int i = 1; i < L.size(); i++){ L[i].second = max(L[i].second, L[i-1].second); li.insert(L[i]); }
            for(int mask = 0; mask < (1<<(N-N/2)); mask++){
                int tc = 0, tv = 0;
                for(int i = 0; i < N-N/2; i++)
                    if((mask&(1<<i)) > 0){
                        tc += costs[N/2+i];
                        tv += vals[N/2+i];
                    }
                if(tc > C) continue;
                auto it = li.lower_bound(make_pair(C+1-tc, 0));
                while(it == li.end() || (*it).first+tc > C) it--;
                ret = max(ret, (*it).second+tv);
            }
        }
        else{
            dp[0][0] = 0; for(int j = 1; j <= totalVal; j++) dp[0][j] = C+1;
            for(int i = 1; i <= N; i++)
                for(int j = 0; j <= totalVal; j++){
                    dp[i%2][j] = dp[(i-1)%2][j];
                    if(j >= vals[i-1]) dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j-vals[i-1]]+costs[i-1]);
                    if(dp[i%2][j] < C+1) ret = max(ret, j);
                }
        }
        cout << ret << '\n';
    }
    return 0;
}
