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

int N, Q, id = 0, arr [100010], lastSeen [100010], tree [100010], ret [100010];
long long twoPow [210];
vector<int> primes;
pair<long long, long long> ori [100010];
map<pair<long long, long long>, int> casts;
pair<pair<int, int>, int> queries [100010];

void add(int pos, int x){
    while(pos < 100010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> Q; twoPow[0] = 1; memset(lastSeen, -1, sizeof(lastSeen));
    for(int i = 2; i < 1000; i++){
        bool ok = true;
        for(int j = 2; j <= (int)sqrt(i); j++)
            if(i%j == 0){
                ok = false;
                break;
            }
        if(!ok) continue;
        primes.pb(i); twoPow[primes.size()] = (twoPow[primes.size()-1]*101)%MOD;
    }
    for(int i = 1; i <= N; i++){
        int x; cin >> x;
        long long hashy = 0;
        for(int p = 0; p < primes.size(); p++){
            long long fac = 0;
            while(x%primes[p] == 0){ fac = 1-fac; x /= primes[p]; }
            hashy = (hashy+(fac*twoPow[p])%MOD)%MOD;
            if(x == 1) break;
        }
        if(casts.find(mp(hashy, x)) == casts.end()) casts[mp(hashy, x)] = id++;
        arr[i] = casts[mp(hashy, x)];
    }
    for(int i = 0; i < Q; i++){ cin >> queries[i].f.s >> queries[i].f.f; queries[i].s = i; }
    sort(queries, queries+Q);
    for(int i = 0; i < Q; i++) swap(queries[i].f.f, queries[i].f.s);
    for(int i = 1, q = 0; i <= N; i++){
        if(lastSeen[arr[i]] != -1) add(lastSeen[arr[i]], -1);
        lastSeen[arr[i]] = i; add(i, 1);
        while(q < Q && queries[q].f.s == i){
            ret[queries[q].s] = query(queries[q].f.s)-query(queries[q].f.f-1);
            q++;
        }
    }
    for(int i = 0; i < Q; i++) cout << ret[i] << '\n';
    return 0;
}
