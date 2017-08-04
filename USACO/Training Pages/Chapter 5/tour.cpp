/*
ID: vamaddu1
PROG: tour
LANG: C++11
*/

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

int numPlaces, numFlights, dp [110][110], ret = 1;
map<string, int> placeToIndex;
set<int> adjacency [110];

int main(){
    freopen("tour.in", "r", stdin); freopen("tour.out", "w", stdout);
    cin >> numPlaces >> numFlights;
    for(int i = 0; i < numPlaces; i++){
        string s; cin >> s;
        placeToIndex[s] = i;
    }
    for(int i = 0; i < numFlights; i++){
        string a, b; cin >> a >> b;
        adjacency[placeToIndex[a]].insert(placeToIndex[b]);
        adjacency[placeToIndex[b]].insert(placeToIndex[a]);
    }
    memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
    for(int i = 0; i < numPlaces; i++)
        for(int j = i+1; j < numPlaces; j++)
            for(int k = 0; k < j; k++)
                if(adjacency[k].find(j) != adjacency[k].end() && dp[i][k] > 0)
                    dp[i][j] = dp[j][i] = max(dp[i][j], dp[i][k]+1);
    for(int i = 0; i < numPlaces-1; i++)
        if(adjacency[i].find(numPlaces-1) != adjacency[i].end())
            ret = max(ret, dp[i][numPlaces-1]);
    cout << ret << '\n';
    return 0;
}
