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

int k, n, m, cost [50], benefit [50], dp [22][101][51][4], dish [22][101][51][4], ret, curMoney, curDish, curStreak, prevDish;

int solve(int night, int money, int lastDish, int streak){
    if(dp[night][money][lastDish][streak] != -1) return dp[night][money][lastDish][streak];
    if(night == k) return dp[night][money][lastDish][streak] = 0;
    int best = -2;
    for(int i = 0; i < n; i++){
        if(money-cost[i] < 0) continue;
        int now;
        if(i == lastDish) now = solve(night+1, money-cost[i], i, min(streak+1, 3));
        else now = solve(night+1, money-cost[i], i, 1);
        if(now == -2) continue;
        if(i != lastDish) now += benefit[i];
        else if(streak == 1) now += benefit[i]/2;
        if(best < now || (best == now && cost[i] < cost[dish[night][money][lastDish][streak]])){
            best = now;
            dish[night][money][lastDish][streak] = i;
        }
    }
    return dp[night][money][lastDish][streak] = best;
}

int main(){
    while(true){
        scanf("%d %d %d", &k, &n, &m);
        if(k == 0 && n == 0 && m == 0) break;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &cost[i], &benefit[i]); benefit[i] *= 2;
        }
        memset(dp, -1, sizeof(dp));
        ret = solve(0, m, 50, 1);
        if(ret == -2){ cout << "0.0\n\n"; continue; }
        cout << ret/2;
        if(ret%2 == 0) cout << ".0\n";
        else cout << ".5\n";
        curMoney = m; curDish = 50; curStreak = 1;
        for(int i = 0; i < k-1; i++){
            cout << (dish[i][curMoney][curDish][curStreak]+1) << " ";
            prevDish = curDish;
            curDish = dish[i][curMoney][curDish][curStreak];
            curMoney -= cost[curDish];
            if(prevDish == curDish) curStreak = min(curStreak+1, 3);
            else curStreak = 1;
        }
        cout << (dish[k-1][curMoney][curDish][curStreak]+1) << "\n\n";
    }
    return 0;
}
