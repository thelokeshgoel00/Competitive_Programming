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

int R, C, K, grid [760][760];
set<int> columnsWithColor [562510];
vector<int> trees [562510]; // 0 : ways disregarding color :: 1-562500 : ways from square of same color
unordered_map<int, int> compress [562510];

void add(int color, int pos, int val){
    while(pos < trees[color].size()){
        trees[color][pos] = (trees[color][pos]+val)%MOD;
        pos += (pos&-pos);
    }
}

int query(int color, int pos){
    int sum = 0;
    while(pos > 0){
        sum = (sum+trees[color][pos])%MOD;
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    freopen("hopscotch.in", "r", stdin); freopen("hopscotch.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            cin >> grid[i][j];
            columnsWithColor[grid[i][j]].insert(j);
        }
    for(int i = 0; i < 760; i++) trees[0].push_back(0);
    for(int i = 1; i <= K; i++){
        int idx = 1; trees[i].push_back(0);
        for(int j : columnsWithColor[i]){
            compress[i][j] = idx++;
            trees[i].push_back(0);
        }
    }
    for(int i = R-1; i > -1; i--)
        for(int j = 0; j < C; j++){
            int ret = 0;
            if(i != R-1 || j != C-1){
                // ways disregarding color - ways from square of same color
                ret = (ret+query(0, C-1)-query(0, j)+MOD)%MOD;
                ret = (ret-(query(grid[i][j], trees[grid[i][j]].size()-1)-query(grid[i][j], compress[grid[i][j]][j])+MOD)%MOD+MOD)%MOD;
            }
            else ret = 1;
            add(grid[i][j], compress[grid[i][j]][j], ret);
            if(j != 0) add(0, j, ret);
            else if(i == 0) cout << ret << '\n';
        }
    return 0;
}
