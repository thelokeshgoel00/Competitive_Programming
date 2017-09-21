#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, prefixPoints [50010], suffixPoints [50010], ret = 0;
vector<int> elsieCards;
set<int> prefixSet, suffixSet;
bool used [100010];

int main(){
    freopen("cardgame.in", "r", stdin); freopen("cardgame.out", "w", stdout);
    scanf("%d", &N); memset(used, false, sizeof(used));
    for(int i = 0; i < N; i++){
        int x; scanf("%d", &x);
        elsieCards.push_back(x); used[x] = true;
    }
    for(int i = 1; i <= 2*N; i++)
        if(!used[i]){
            prefixSet.insert(i);
            suffixSet.insert(i);
        }
    prefixPoints[0] = suffixPoints[N+1] = 0;
    for(int i = 0; i < N; i++){
        prefixPoints[i+1] = prefixPoints[i];
        auto it = prefixSet.upper_bound(elsieCards[i]);
        if(it != prefixSet.end()){
            prefixPoints[i+1]++;
            prefixSet.erase(it);
        }
    }
    for(int i = N; i > 0; i--){
        suffixPoints[i] = suffixPoints[i+1];
        auto it = suffixSet.lower_bound(elsieCards[i-1]);
        if(it != suffixSet.begin()){
            it--; suffixPoints[i]++;
            suffixSet.erase(it);
        }
    }
    for(int i = 0; i <= N; i++) ret = max(ret, prefixPoints[i]+suffixPoints[i+1]);
    cout << ret << '\n';
    return 0;
}
