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
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, M;
vector<pair<long long, long long>> good [110], delay [110];
long long ret = -1;

void compress(vector<pair<long long, long long>> &e){
    int idx = 0;
    for(int i = 0; i < e.size(); i++){
        while(idx > 0 and e[i].s <= e[idx-1].s) idx--;
        if(idx == 0 or e[i].f > e[idx-1].f) e[idx++] = e[i];
    }
    e.resize(idx);
}

long long testIt(vector<pair<long long, long long>> arr [110], int curr, long long tiempo){
    while(curr < N-1){
        auto it = lower_bound(arr[curr].begin(), arr[curr].end(), mp(tiempo, tiempo));
        if(it == arr[curr].end()) return INF;
        tiempo = (*it).s; curr++;
    }
    return tiempo;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int x; long long s, t, l; cin >> x >> s >> t >> l; x--;
        good[x].push_back(mp(s, t)); delay[x].push_back(mp(s+l, t+l));
    }
    for(int i = 0; i < N; i++){
        sort(good[i].begin(), good[i].end()); sort(delay[i].begin(), delay[i].end());
        if(i > 0) compress(good[i]);
        compress(delay[i]);
    }
    for(pair<long long, long long> lol : good[0])
        if(testIt(good, 1, lol.s)+1800 <= testIt(delay, 0, lol.f)){
            ret = lol.f;
            break;
        }
    if(ret > -1) cout << ret << '\n';
    else cout << "impossible\n";
    return 0;
}
