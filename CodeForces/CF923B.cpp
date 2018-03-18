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
long long piles [100010], curLevel = 0;
multiset<long long> active;

int main(){
    //freopen("dirtraverse.in", "r", stdin); freopen("dirtraverse.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> piles[i];
    for(int i = 0; i < N; i++){
        long long temp, ret = 0; cin >> temp;
        active.insert(piles[i]+curLevel); curLevel += temp;
        while(active.size() > 0 && *active.begin() <= curLevel){
            ret += temp-(curLevel-*active.begin());
            active.erase(active.begin());
        }
        ret += temp*(long long)active.size();
        if(i != N-1) cout << ret << ' ';
        else cout << ret << '\n';
    }
    return 0;
}
