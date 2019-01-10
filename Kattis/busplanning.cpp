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

int N, K, C, dp [1<<20], prevy [1<<20];
string people [20];
map<string, int> peopleToIndex;
unordered_set<int> adjacency [20];
bool isClique [1<<20];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K >> C; isClique[0] = false; dp[0] = 0;
    for(int i = 0; i < N; i++){
        cin >> people[i]; peopleToIndex[people[i]] = i;
        for(int j = 0; j < N; j++) adjacency[i].insert(j);
    }
    for(int i = 0; i < K; i++){
        string a, b; cin >> a >> b;
        adjacency[peopleToIndex[a]].erase(peopleToIndex[b]);
        adjacency[peopleToIndex[b]].erase(peopleToIndex[a]);
    }
    for(int mask = 1; mask < (1<<N); mask++){
        if(__builtin_popcount(mask) > C){ isClique[mask] = false; continue; }
        isClique[mask] = true;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                if((mask&(1<<i)) == 0 || (mask&(1<<j)) == 0) continue;
                if(adjacency[i].find(j) == adjacency[i].end()){
                    isClique[mask] = false;
                    break;
                }
            }
    }
    for(int mask = 1; mask < (1<<N); mask++){
        dp[mask] = 20;
        for(int submask = mask; submask > 0; submask = (submask-1)&mask)
            if(isClique[submask])
                if(dp[mask^submask]+1 < dp[mask]){
                    dp[mask] = dp[mask^submask]+1;
                    prevy[mask] = mask^submask;
                }
    }
    cout << dp[(1<<N)-1] << '\n';
    for(int mask = (1<<N)-1; mask > 0; ){
        int clique = mask^prevy[mask];
        for(int i = 0; i < N; i++)
            if((clique&(1<<i)) > 0)
                cout << people[i] << ' ';
        cout << '\n';
        mask = prevy[mask];
    }
    return 0;
}
