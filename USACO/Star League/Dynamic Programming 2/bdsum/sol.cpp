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

int N, S, combo [12][12];
bool used [12], killAll = false;
vector<int> ret;

void recurse(){
    if(ret.size() == N){
        int sum = 0;
        for(int i = 0; i < N; i++) sum += ret[i]*combo[N-1][i];
        if(sum == S) killAll = true;
        return;
    }
    for(int i = 1; i <= N; i++){
        if(used[i]) continue;
        used[i] = true; ret.push_back(i);
        recurse();
        if(killAll) return;
        used[i] = false; ret.pop_back();
    }
}

int main(){
    //freopen("subrev.in", "r", stdin); freopen("subrev.out", "w", stdout);
    scanf("%d %d", &N, &S); combo[0][0] = 1; fill(used, used+12, false);
    for(int i = 1; i < 12; i++){
        combo[i][0] = 1;
        for(int j = 0; j < 12; j++) combo[i][j] = combo[i-1][j]+combo[i-1][j-1];
    }
    recurse();
    for(int i = 0; i < N-1; i++) printf("%d ", ret[i]);
    printf("%d\n", ret[N-1]);
    return 0;
}
