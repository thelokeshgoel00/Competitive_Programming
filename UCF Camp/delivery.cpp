#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string.h>

using namespace std;

int n, matrix [501][501];

int main(){
    //freopen("shufflegold.in","r",stdin); freopen("shufflegold.out","w",stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &matrix[i][j]);
    for(int i = 1; i <= n; i++)
        for(int k = i+1; k <= n; k++)
            for(int j = k+1; j <= n; j++){
                if(matrix[i][k] == -1 || matrix[k][j] == -1) continue;
                int now = matrix[i][k] + matrix[k][j];
                if(matrix[i][j] == -1 || matrix[i][j] > now) matrix[i][j] = now;
            }
    cout << matrix[1][n] << '\n';
    return 0;
}
