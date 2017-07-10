#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int rows, cols, ret = 0, dx [] = {1, 1, 1, 0, 0, -1, -1, -1}, dy [] = {1, 0, -1, 1, -1, 1, 0, -1};
char grid [200][200];

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < rows && y < cols; }

int main(){
    scanf("%d %d", &rows, &cols);
    for(int i = 0; i < rows; i++) scanf("%s", &grid[i]);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 'S') continue;
            int temp1 = 0; int temp2 = 0;
            for(int k = 0; k < 8; k++)
                if(inBounds(i+dx[k], j+dy[k])){
                    temp1++;
                    if(grid[i+dx[k]][j+dy[k]] == 'S') temp2++;
                }
            if(temp2*2 < temp1) ret++;
        }
    cout << ret << '\n';
    return 0;
}
