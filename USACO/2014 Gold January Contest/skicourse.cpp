#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

int rows, cols, ret;
bool isRough [110][110], isSmooth [110][110];
pair<int, int> dp [110], nexts [110]; //(rough, smooth)

int main(){
    freopen("skicourse.in", "r", stdin); freopen("skicourse.out", "w", stdout);
    cin >> rows >> cols; ret = min(rows, cols);
    for(int i = 0; i < rows; i++){
        string s; cin >> s;
        for(int j = 0; j < cols; j++){
            if(s[j] == 'R'){ isRough[i][j] = true; isSmooth[i][j] = false; }
            else{ isRough[i][j] = false; isSmooth[i][j] = true; }
        }
    }
    while(true){
        int best = -1, bestRow = -1, bestCol = -1;
        for(int i = 0; i < 110; i++) dp[i] = make_pair(0, 0);
        for(int i = rows-1; i > -1; i--){
            for(int j = cols-1; j > -1; j--){
                pair<int, int> temp;
                temp.first = isRough[i][j] ? min(min(dp[j].first, dp[j+1].first), nexts[j+1].first)+1:0;
                temp.second = isSmooth[i][j] ? min(min(dp[j].second, dp[j+1].second), nexts[j+1].second)+1:0;
                if(temp.first != temp.second)
                    if(max(temp.first, temp.second) > best){
                        best = max(temp.first, temp.second);
                        bestRow = i; bestCol = j;
                    }
                nexts[j] = temp;
            }
            for(int j = 0; j < 110; j++) dp[j] =  make_pair(nexts[j].first, nexts[j].second);
        }
        if(best == -1) break;
        ret = min(ret, best);
        for(int i = bestRow; i < bestRow+best; i++)
            for(int j = bestCol; j < bestCol+best; j++){
                isRough[i][j] = true;
                isSmooth[i][j] = true;
            }
    }
    cout << ret << '\n';
    return 0;
}
