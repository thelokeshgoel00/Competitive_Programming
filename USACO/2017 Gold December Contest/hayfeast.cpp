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
#define INF 1000000000000000000
#define MOD 1000000007

int N, idx = 0;
long long M, totalFlavor = 0, ret = INF;
pair<long long, long long> haybales [100010];
multiset<long long> spiciness;

int main(){
    freopen("hayfeast.in", "r", stdin); freopen("hayfeast.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> haybales[i].first >> haybales[i].second;
        totalFlavor += haybales[i].first; spiciness.insert(haybales[i].second);
        while(totalFlavor-haybales[idx].first >= M){
            totalFlavor -= haybales[idx].first;
            auto it = spiciness.find(haybales[idx].second);
            spiciness.erase(it); idx++;
        }
        if(totalFlavor >= M) ret = min(ret, *spiciness.rbegin());
    }
    cout << ret << '\n';
    return 0;
}
