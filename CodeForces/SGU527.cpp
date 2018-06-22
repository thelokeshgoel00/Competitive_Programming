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

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, M, bitCounts [1<<25], rowMasks [1<<25], ret = 25;
char grid [25][25];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; rowMasks[0] = bitCounts[0] = 0;
    for(int i = 1; i < (1<<25); i++) bitCounts[i] = bitCounts[i-(i&-i)]+1;
    for(int i = 0; i < N; i++){
        cin >> grid[i];
        rowMasks[1<<i] = 0;
        for(int j = 0; j < M; j++)
            if(grid[i][j] == '*')
                rowMasks[1<<i] |= (1<<j);
    }
    for(int i = 1; i < (1<<N); i++) rowMasks[i] = rowMasks[i-(i&-i)] | rowMasks[(i&-i)];
    for(int i = 0; i < (1<<N); i++){
        int nmask = rowMasks[((1<<N)-1)^i];
        ret = min(ret, max(bitCounts[i], bitCounts[nmask]));
    }
    cout << ret << '\n';
    return 0;
}
