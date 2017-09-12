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

int N;
long long L, C, maxSpeed = 0, tree [100010], ret = 0ll, floorSum = 0ll;
pair<long long, pair<long long, int>> cows [100010]; //speed, mod, modRank

bool cowModComp(pair<long long, pair<long long, int>> a, pair<long long, pair<long long, int>> b){
    return a.second.first < b.second.first;
}

void add(int pos, long long x){
    while(pos < 100010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long sum = 0ll;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    //freopen("grass.in", "r", stdin); freopen("grass.out", "w", stdout);
    scanf("%d %lld %lld", &N, &L, &C); memset(tree, 0ll, sizeof(tree));
    for(int i = 0; i < N; i++){ scanf("%lld", &cows[i].first); maxSpeed = max(maxSpeed, cows[i].first); }
    for(int i = 0; i < N; i++) cows[i].second.first = (L*cows[i].first*C)%(maxSpeed*C);
    sort(cows, cows+N, cowModComp);
    for(int i = 0, curRank = 1; i < N; curRank++){
        int j = i;
        while(j < N && cows[j].second.first == cows[i].second.first){ cows[j].second.second = curRank; j++; }
        i = j;
    }
    sort(cows, cows+N);
    for(int i = 0; i < N; i++){
        long long floory = (L*cows[i].first)/maxSpeed;
        ret += (floory-1ll)*(long long)i-floorSum+query(cows[i].second.second);
        floorSum += floory; add(cows[i].second.second, 1ll);
    }
    cout << ret << '\n';
    return 0;
}
