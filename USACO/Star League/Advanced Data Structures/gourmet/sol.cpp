#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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

int N, M, grassPtr;
pair<long long, long long> cows [100010], grasses [100010];
set<pair<long long, int>> used;
long long ret = 0ll;

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> cows[i].second >> cows[i].first;
    for(int i = 0; i < M; i++) cin >> grasses[i].second >> grasses[i].first;
    sort(cows, cows+N); sort(grasses, grasses+M); grassPtr = M-1;
    for(int i = N-1; i > -1; i--){
        while(grassPtr > -1 && grasses[grassPtr].first >= cows[i].first){
            used.insert(make_pair(grasses[grassPtr].second, grassPtr));
            grassPtr--;
        }
        auto it = used.lower_bound(make_pair(cows[i].second, -1));
        if(it == used.end()){ ret = -1ll; break; }
        ret += (*it).first; used.erase(it);
    }
    cout << ret << '\n';
    return 0;
}
