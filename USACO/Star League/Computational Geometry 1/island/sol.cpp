#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int rows, cols, dx [] = {0, 1, 0, -1}, dy [] = {1, 0, -1, 0}, startRow, startCol, curRow = -1, curCol = -1, curDirection = 0, ret = 0;
char grid [1010][1010];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < rows && y < cols; }

bool validMove(int x, int y, int d){
    int nr = x+dx[d], nc = y+dy[d];
    if(!inBounds(nr, nc) || grid[nr][nc] != '.') return false;
    curRow = nr; curCol = nc; curDirection = d;
    return true;
}

void floodfill(int r, int c){
    if(grid[r][c] != '.' || r == 0 || c == 0 || r == rows-1 || c == cols-1) return;
    bool isA [4]; int numA = 0;
    for(int i = 0; i < 4; i++){
        isA[i] = grid[r+dx[i]][c+dy[i]] == 'A';
        if(isA[i]) numA++;
    }
    if(numA < 2) return;
    if(numA == 2){
        int index = 0;
        while(isA[index]) index++;
        if(isA[(index+1)%4]) index = (index+3)%4;
        if(isA[index] || grid[r+dx[index]+dx[(index+1)%4]][c+dy[index]+dy[(index+1)%4]] != '.') return;
    }
    grid[r][c] = 'A';
    floodfill(r+1, c); floodfill(r-1, c);
    floodfill(r, c+1); floodfill(r, c-1);
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d %d", &rows, &cols);
    for(int i = 0; i < rows; i++) scanf("%s", &grid[i]);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            floodfill(i, j);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            if(grid[i][j] == 'A'){
                curRow = i-1; curCol = j;
                break;
            }
        if(curRow != -1) break;
    }
    startRow = curRow; startCol = curCol;
    while(ret == 0 || curRow != startRow || curCol != startCol){
        if(validMove(curRow, curCol, (curDirection+1)%4)){ ret++; continue; }
        if(validMove(curRow, curCol, curDirection)){ ret++; continue; }
        if(validMove(curRow, curCol, (curDirection+3)%4)){ ret++; continue; }
        printf("YOU GOOFED UP MAN!\n"); // Print Statement Debugging :)
    }
    printf("%d\n", ret);
    return 0;
}
