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

int N, mini, ret = 0;
long long K;
pair<long long, int> cumSum [1000010];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K; cumSum[0] = mp(0, 0);
    for(int i = 1; i <= N; i++){
        cin >> cumSum[i].f; cumSum[i].f -= K;
        cumSum[i].f += cumSum[i-1].f; cumSum[i].s = -i;
    }
    sort(cumSum, cumSum+N+1); mini = -cumSum[N].s;
    for(int i = N-1; i > -1; i--){
        ret = max(ret, -cumSum[i].s-mini);
        mini = min(mini, -cumSum[i].s);
    }
    cout << ret << '\n';
    return 0;
}
