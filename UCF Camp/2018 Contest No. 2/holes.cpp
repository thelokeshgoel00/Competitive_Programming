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

int N, M, powers [100010], blockNum [100010], blockSum [100010], nexts [100010], lastSeen [100010];

void update(int pos, int val){
    powers[pos] = val;
    for(int i = pos; i > -1 && blockNum[i] == blockNum[pos]; i--){
        if(i+powers[i] >= N || blockNum[i+powers[i]] != blockNum[i]){
            blockSum[i] = 1; nexts[i] = i+powers[i];
            lastSeen[i] = i;
        }
        else{
            blockSum[i] = blockSum[i+powers[i]]+1; nexts[i] = nexts[i+powers[i]];
            lastSeen[i] = lastSeen[i+powers[i]];
        }
    }
}

pair<int, int> query(int pos){
    pair<int, int> ret = mp(pos, 0);
    while(pos < N){
        ret.s += blockSum[pos]; ret.f = lastSeen[pos];
        pos = nexts[pos];
    }
    return ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 0; i < N; i++){ cin >> powers[i]; blockNum[i] = i/(int)sqrt(N); }
    for(int i = N-1; i > -1; i--){
        if(i+powers[i] >= N || blockNum[i+powers[i]] != blockNum[i]){
            blockSum[i] = 1; nexts[i] = i+powers[i];
            lastSeen[i] = i;
        }
        else{
            blockSum[i] = blockSum[i+powers[i]]+1; nexts[i] = nexts[i+powers[i]];
            lastSeen[i] = lastSeen[i+powers[i]];
        }
    }
    for(int i = 0; i < M; i++){
        int t, a, b; cin >> t >> a; a--;
        if(t == 0){ cin >> b; update(a, b); }
        else{
            pair<int, int> lol = query(a); lol.f++;
            cout << lol.f << ' ' << lol.s << '\n';
        }
    }
    return 0;
}
