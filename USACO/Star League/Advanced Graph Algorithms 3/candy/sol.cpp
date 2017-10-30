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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, Nopt, F, M, options [60], visited [40510], dp [40510];
set<int> favorites;
bool addBack = false;

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> Nopt >> F >> M; memset(visited, 0, sizeof(visited));
    memset(dp, -1, sizeof(dp)); dp[N] = 0;
    for(int i = 0; i < Nopt; i++) cin >> options[i];
    for(int i = 0; i < F; i++){
        int ff; cin >> ff;
        favorites.insert(ff);
        if(ff == N) addBack = true;
    }
    if(addBack) favorites.erase(N);
    for(int i = N; i > 0; i--){
        if(dp[i] == -1) continue;
        visited[i]++;
        if(visited[i] > F+2){ 
            cout << "-1\n";
            return 0;
        }
        // F times from favorites, 1 time from eating, 1 time from being the original value of N
        if(favorites.find(i) != favorites.end()){
            if(dp[i] > dp[i+M]){ dp[i+M] = dp[i]; i += M+1; }
            continue;
        }
        for(int j = 0; j < Nopt; j++)
            if(i-options[j] > -1)
                dp[i-options[j]] = max(dp[i-options[j]], dp[i]+options[j]);
        if(addBack){ favorites.insert(N); addBack = false; }
    }
    cout << *max_element(dp, dp+40510) << '\n';
    return 0;
}
