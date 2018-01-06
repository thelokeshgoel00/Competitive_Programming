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

int N, M, prevs [200010], nexts [200010];
set<int> stuff;
long long cap [200010], water [200010];

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 1; i <= N+1; i++){
        if(i != N+1) cin >> cap[i];
        else cap[i] = INF;
        stuff.insert(i); prevs[i] = i-1; nexts[i] = i+1;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        int q, k; cin >> q >> k;
        if(q == 1){
            long long x; cin >> x;
            k = *stuff.lower_bound(k);
            while(x > 0){
                long long used = min(x, cap[k]-water[k]);
                x -= used; water[k] += used;
                if(water[k] == cap[k]){
                    nexts[prevs[k]] = nexts[k];
                    prevs[nexts[k]] = prevs[k];
                    stuff.erase(k); k = nexts[k];
                }
            }
        }
        else cout << water[k] << '\n';
    }
    return 0;
}
