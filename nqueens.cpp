#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

int n, sol [15];
bool killAll = false;

void backtrack(int cur, int mask, bool grid [15][15]){
    if(killAll) return;
    if(cur == n){
        cout << sol[0];
        for(int i = 1; i < n; i++){
            cout << " " << sol[i];
        }
        killAll = true; cout << '\n';
        return;
    }
    for(int x = 0; x < n; x++){
        if((mask&(1<<x)) != 0 || grid[cur][x]) continue;
        bool dupe [15][15];
        for(int i = 0; i < 15; i++)
            for(int j = 0; j < 15; j++)
                dupe[i][j] = grid[i][j];
        for(int i = 1; cur-i > -1 && x-i > -1; i++) dupe[cur-i][x-i] = true;
        for(int i = 1; cur-i > -1 && x+i < 15; i++) dupe[cur-i][x+i] = true;
        for(int i = 1; cur+i < 15 && x-i > -1; i++) dupe[cur+i][x-i] = true;
        for(int i = 1; cur+i < 15 && x+i < 15; i++) dupe[cur+i][x+i] = true;
        sol[cur] = x+1;
        backtrack(cur+1, mask|(1<<x), dupe);
        if(killAll) return;
    }
    if(killAll) return;
}

int main(){
    cin >> n; bool stuff [15][15];
    memset(stuff, false, sizeof(stuff));
    backtrack(0, 0, stuff);
    return 0;
}
