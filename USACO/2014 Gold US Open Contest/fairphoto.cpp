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
#include <sstream>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, K, cumSum [100010][8], backMasks [100010][8], forwardMasks [100010][8], ret = -1;
pair<int, int> cows [100010];
map<vector<int>, int> hashPos [256];

int main(){
    freopen("fairphoto.in", "r", stdin); freopen("fairphoto.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K;
    for(int i = 1; i <= N; i++){ cin >> cows[i].first >> cows[i].second; cows[i].second--; }
    sort(cows+1, cows+N+1);
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 8; j++) cumSum[i][j] = cumSum[i-1][j];
        cumSum[i][cows[i].second]++;
    }
    for(int i = 1; i <= N; i++){
        int x = 1<<cows[i].second;
        backMasks[i][0] = x;
        for(int j = 1; j < 8; j++){
            if((backMasks[i-1][j]&x) > 0) backMasks[i][j] = backMasks[i-1][j];
            else backMasks[i][j] = backMasks[i-1][j-1] | x;
        }
    }
    for(int i = N; i >= 1; i--){
        int x = 1<<cows[i].second;
        forwardMasks[i][0] = x;
        for(int j = 1; j < 8; j++){
            if((forwardMasks[i+1][j]&x) > 0) forwardMasks[i][j] = forwardMasks[i+1][j];
            else forwardMasks[i][j] = forwardMasks[i+1][j-1] | x;
        }
    }
    for(int distinctBreeds = K; distinctBreeds <= 8; distinctBreeds++){
        vector<int> curHash(8); for(int i = 0; i < 256; i++) hashPos[i] = map<vector<int>, int>();
        for(int i = N; i >= 1; i--){
            int mask = forwardMasks[i][distinctBreeds-1], sub = -1;
            if(__builtin_popcount(mask) < distinctBreeds) continue;
            for(int j = 0; j < 8; j++){
                if((mask&(1<<j)) > 0){
                    if(sub == -1) sub = cumSum[i-1][j];
                    curHash[j] = cumSum[i-1][j]-sub;
                }
                else curHash[j] = cumSum[i-1][j];
            }
            hashPos[mask][curHash] = cows[i].first;
        }
        for(int i = 1; i <= N; i++){
            int mask = backMasks[i][distinctBreeds-1], sub = -1;
            if(__builtin_popcount(mask) < distinctBreeds) continue;
            for(int j = 0; j < 8; j++){
                if((mask&(1<<j)) > 0){
                    if(sub == -1) sub = cumSum[i][j];
                    curHash[j] = cumSum[i][j]-sub;
                }
                else curHash[j] = cumSum[i][j];
            }
            auto it = hashPos[mask].find(curHash);
            if(it != hashPos[mask].end()) ret = max(ret, cows[i].first-it->second);
        }
    }
    cout << ret << '\n';
    return 0;
}
