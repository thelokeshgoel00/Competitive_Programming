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

int N, M, cumSum [300010][110], reach [300010][110];
vector<pair<int, int>> ret;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < M; j++)
            reach[i][j] = 300010;
    for(int i = 1; i <= N; i++){
        int x; cin >> x; x--;
        for(int j = 0; j < M; j++) cumSum[i][j] = cumSum[i-1][j];
        cumSum[i][x]++; reach[cumSum[i][x]][x] = i;
    }
    ret.pb(mp(1, N));
    for(int g = 2; g <= N; g++){
        int pos = 0, numGroups = 0;
        while(pos <= N){
            int mini = 300010;
            for(int i = 0; i < M; i++)
                if(cumSum[pos][i]+g <= N)
                    mini = min(mini, reach[cumSum[pos][i]+g][i]);
            pos = mini; numGroups++;
            if(pos >= N){
                if(pos == N) ret.pb(mp(g, numGroups));
                break;
            }
        }
    }
    cout << ret.size() << '\n';
    for(int i = 0; i < ret.size(); i++) cout << ret[i].f << ' ' << ret[i].s << '\n';
    return 0;
}
