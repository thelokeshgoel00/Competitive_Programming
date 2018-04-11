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

int N, M, grid [2010][2010], maxi [2010][2010], ret;

int bruteForce(int d, int r, int c){
    if(r < 2 || c < 2) return 1;
    int dx, dy;
    if(d == 0) dx = 0, dy = grid[r][c]-grid[r][c-1];
    else{
        dx = grid[r][c]-grid[r-1][c];
        if(d == 1) dy = 0;
        else if(d == 2) dy = dx;
        else dy = -dx;
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(grid[r-i][c-j] != grid[r][c]-dx*i-dy*j)
                return 1;
    if(r < 3 || c < 3) return 2;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(grid[r-i][c-j] != grid[r][c]-dx*i-dy*j)
                return 2;
    return 3;
}

int main(){
    //freopen("nocow.in", "r", stdin); freopen("nocow.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(true){
        cin >> N >> M; ret = 0;
        if(N == 0 && M == 0) break;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                cin >> grid[i][j];
        for(int d = 0; d < 4; d++)
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= M; j++){
                    maxi[i][j] = bruteForce(d, i, j); ret = max(ret, maxi[i][j]);
                    int s = min(maxi[i-1][j], maxi[i][j-1]);
                    if(s < 3 || grid[i][j]-grid[i-1][j-1] != grid[i-1][j-1]-grid[i-2][j-2]) continue;
                    if(grid[i-s][j-s]+(grid[i][j]-grid[i-1][j-1])*s == grid[i][j]) maxi[i][j] = s+1;
                    else maxi[i][j] = s;
                    ret = max(ret, maxi[i][j]);
                }
        cout << ret*ret << '\n';
    }
    return 0;
}
