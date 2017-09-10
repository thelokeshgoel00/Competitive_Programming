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

int N, M, start, fin, parent [2010];
double oriVal, dist [2010];
vector<pair<int, double>> adjacency [2010];

int main(){
    //freopen("grassplant.in", "r", stdin); freopen("grassplant.out", "w", stdout);
    scanf("%d %d %lf %d %d", &N, &M, &oriVal, &start, &fin);
    for(int i = 0; i < M; i++){
        int a, b; double c; scanf("%d %d %lf", &a, &b, &c);
        adjacency[a].push_back(make_pair(b, log(c)));
    }
    fill(dist, dist+2010, INF); dist[start] = 0.0; fill(parent, parent+2010, -1);
    /* Repeatedly Relaxing the Edges */
    for(int i = 1; i < N; i++)
        for(int j = 1; j <= N; j++)
            for(pair<int, double> edge : adjacency[j])
                if(dist[j]+edge.second < dist[edge.first]){
                    dist[edge.first] = dist[j]+edge.second;
                    parent[edge.first] = j;
                }
    /* Checking for a Negative-Weight Cycle */
    for(int j = 1; j <= N; j++)
        for(pair<int, double> edge : adjacency[j])
            if(dist[j]+edge.second < dist[edge.first]){
                cout << "0\n";
                return 0;
            }
    cout << (long long)(oriVal*exp(dist[fin])) << '\n';
    return 0;
}
