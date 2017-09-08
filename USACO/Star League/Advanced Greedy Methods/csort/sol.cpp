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

int N, ret = 0;
pair<int, int> cows [10010];
bool visited [10010];

int main(){
    //freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);
    scanf("%d", &N); fill(visited, visited+10010, false);
    for(int i = 0; i < N; i++){ scanf("%d", &cows[i].first); cows[i].second = i; }
    sort(cows, cows+N);
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        int index = cows[i].second, cycleSize = 1;
        while(index != i){
            ret += cows[index].first;
            visited[index] = true;
            index = cows[index].second;
            cycleSize++;
        }
        ret += min((cycleSize-1)*cows[i].first, (cycleSize+1)*cows[0].first+2*cows[i].first);
    }
    cout << ret << '\n';
    return 0;
}
