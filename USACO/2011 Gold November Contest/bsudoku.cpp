#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int dp [9][9][512][8][2];
char grid [9][9];

int go(int r, int c, int mc, int mb, int p){
    if(r == 9) return mc == 0 ? 0 : 100;
    if(c == 9){
        if(p > 0 || (r%3 == 2 && mb > 0)) return 100;
        return go(r+1, 0, mc, mb, 0);
    }
    if(dp[r][c][mc][mb][p] > -1) return dp[r][c][mc][mb][p];
    int x = go(r, c+1, mc, mb, p); int y = go(r, c+1, mc^(1<<c), mb^(1<<(c/3)), 1-p);
    if(grid[r][c] == '1') x++;
    else y++;
    return dp[r][c][mc][mb][p] = min(x, y);
}

int main(){
    freopen("bsudoku.in", "r", stdin); freopen("bsudoku.out", "w", stdout);
    for(int i = 0; i < 9; i++) scanf("%s", &grid[i]);
    for(int a = 0; a < 9; a++)
        for(int b = 0; b < 9; b++)
            for(int c = 0; c < 512; c++)
                for(int d = 0; d < 8; d++)
                    for(int e = 0; e < 2; e++)
                        dp[a][b][c][d][e] = -1;
    cout << go(0, 0, 0, 0, 0) << endl;
    return 0;
}
