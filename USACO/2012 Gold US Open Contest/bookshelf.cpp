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

int N, pt = 0;
long long L, a [100010], b [100010], sum = 0, dp [100010];
deque<long long> dq, indices;
multiset<long long> active;

int main(){
    freopen("bookshelf.in", "r", stdin); freopen("bookshelf.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> L; dq.push_back(INF); indices.push_back(0);
    for(int i = 1; i <= N; i++){
        cin >> a[i] >> b[i]; sum += b[i];
        while(sum > L){
            if(indices.size() > 0 && indices.front() == pt){
                if(dq.size() > 1) active.erase(active.find(dp[indices.front()]+dq[1]));
                dq.pop_front(); indices.pop_front();
            }
            pt++; sum -= b[pt];
        }
        while(dq.size() > 0 && dq.back() < a[i]){
            if(dq.size() > 1) active.erase(active.find(dp[indices[indices.size()-2]]+dq.back()));
            dq.pop_back(); indices.pop_back();
        }
        if(indices.size() > 0) active.insert(dp[indices.back()]+a[i]);
        dq.push_back(a[i]); indices.push_back(i);
        dp[i] = dp[pt]+dq.front();
        if(active.size() > 0) dp[i] = min(dp[i], *active.begin());
    }
    cout << dp[N] << '\n';
    return 0;
}
