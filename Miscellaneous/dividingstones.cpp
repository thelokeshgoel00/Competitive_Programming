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

int kase;
long long N, P, primes [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
unordered_set<long long> lmao;

void recurseIt(long long num, int idx, long long curr){
    lmao.insert(curr);
    for(int i = idx; primes[i] <= num; i++) recurseIt(num-primes[i], i, (curr*primes[i])%P);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(9);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N >> P; lmao = unordered_set<long long>();
        recurseIt(N, 0, 1);
        cout << lmao.size() << '\n';
    }
    return 0;
}
