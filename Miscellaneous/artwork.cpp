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

int N, M, Q, parents [1000010], heights [1000010], freq [1010][1010], dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1}, compCount = 0, ret [10010];
pair<pair<int, int>, pair<int, int>> queries [10010];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < N && y < M; }

int hashy(int x, int y){ return 1000*x+y; }

int findParent(int x){
    if(x == parents[x]) return x;
    parents[x] = findParent(parents[x]);
    return parents[x];
}

bool combine(int x, int y){
    int a = findParent(x); int b = findParent(y);
    if(a == b) return false;
    if(heights[b] < heights[a]) parents[b] = a;
    else if(heights[a] < heights[b]) parents[a] = b;
    else{
        parents[b] = a;
        heights[a]++;
    }
    return true;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M >> Q;
    for(int i = 0; i < Q; i++){
        cin >> queries[i].f.f >> queries[i].f.s >> queries[i].s.f >> queries[i].s.s;
        queries[i].f.f--; queries[i].f.s--; queries[i].s.f--; queries[i].s.s--;
        if(queries[i].f > queries[i].s) swap(queries[i].f, queries[i].s);
        if(queries[i].f.f == queries[i].s.f){
            for(int j = queries[i].f.s; j <= queries[i].s.s; j++)
                freq[queries[i].f.f][j]++;
        }
        else{
            for(int j = queries[i].f.f; j <= queries[i].s.f; j++)
                freq[j][queries[i].f.s]++;
        }
    }
    for(int i = 0; i < 1000010; i++){ parents[i] = i; heights[i] = 0; }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(freq[i][j] > 0) continue;
            compCount++;
            for(int k = 0; k < 4; k++){
                int ni = i+dx[k], nj = j+dy[k];
                if(!inBounds(ni, nj) || freq[ni][nj] > 0) continue;
                if(combine(hashy(i, j), hashy(ni, nj))) compCount--;
            }
        }
    for(int i = Q-1; i > -1; i--){
        ret[i] = compCount;
        if(queries[i].f.f == queries[i].s.f){
            for(int j = queries[i].f.s; j <= queries[i].s.s; j++){
                freq[queries[i].f.f][j]--;
                if(freq[queries[i].f.f][j] > 0) continue;
                compCount++;
                for(int k = 0; k < 4; k++){
                    int ni = queries[i].f.f+dx[k], nj = j+dy[k];
                    if(!inBounds(ni, nj) || freq[ni][nj] > 0) continue;
                    if(combine(hashy(queries[i].f.f, j), hashy(ni, nj))) compCount--;
                }
            }
        }
        else{
            for(int j = queries[i].f.f; j <= queries[i].s.f; j++){
                freq[j][queries[i].f.s]--;
                if(freq[j][queries[i].f.s] > 0) continue;
                compCount++;
                for(int k = 0; k < 4; k++){
                    int ni = j+dx[k], nj = queries[i].f.s+dy[k];
                    if(!inBounds(ni, nj) || freq[ni][nj] > 0) continue;
                    if(combine(hashy(j, queries[i].f.s), hashy(ni, nj))) compCount--;
                }
            }
        }
    }
    for(int i = 0; i < Q; i++) cout << ret[i] << '\n';
    return 0;
}
