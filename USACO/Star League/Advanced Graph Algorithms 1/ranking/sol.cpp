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
#define INF 1000000000000
#define MOD 1000000007

int N, M, ret = 0;
vector<int> adjacency [1010];
bool beenCompared [1010][1010];

void recurse(int source, int curr){
    beenCompared[source][curr] = true;
    for(int i : adjacency[curr]) recurse(source, i);
}

int main(){
    //freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);
    scanf("%d %d", &N, &M);
    memset(beenCompared, false, sizeof(beenCompared));
    for(int i = 0; i < M; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(b);
    }
    for(int i = 1; i <= N; i++) recurse(i, i);
    for(int i = 1; i <= N; i++)
        for(int j = i+1; j <= N; j++)
            if(!beenCompared[i][j] && !beenCompared[j][i])
                ret++;
    cout << ret << '\n';
    /*for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) cout << beenCompared[i][j] << " " << endl;
        cout << endl;
    }*/
    return 0;
}
