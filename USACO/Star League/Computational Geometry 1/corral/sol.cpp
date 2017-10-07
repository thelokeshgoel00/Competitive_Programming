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

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int C, N, xx, yy, idx = 0, dp [510][510], ret = 1000000;
vector<pair<int, int>> points;
set<int> tx, ty;
vector<int> xs, ys;

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d %d", &C, &N); memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++){
        int a, b; scanf("%d %d", &a, &b);
        points.push_back(make_pair(a, b));
        tx.insert(a); ty.insert(b);
    }
    sort(points.begin(), points.end());
    for(int i : tx) xs.push_back(i);
    for(int i : ty) ys.push_back(i);
    xx = xs.size(); yy = ys.size();
    xs.push_back(1000000); ys.push_back(1000000);
    for(int i = 1; i <= xx; i++)
        for(int j = 1; j <= yy; j++){
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            while(idx < N && points[idx].first == xs[i-1] && points[idx].second == ys[j-1]){
                dp[i][j]++;
                idx++;
            }
        }
    for(int x0 = 0; x0 < xx; x0++){
        int reach = 0, x1 = x0+1, y0 = 0, y1 = 1, tot = dp[x1][y1]-dp[x0][y1]-dp[x1][y0]+dp[x0][y0];
        while(true){
            //cout << x0 << " " << reach << endl;
            while(tot < C && (x1 < xx || y1 < yy)){
                reach = min(xs[x1]-xs[x0], ys[y1]-ys[y0]);
                //cout << "HI " << reach << " " << tot << endl;
                while(xs[x1]-xs[x0] <= reach) x1++;
                while(ys[y1]-ys[y0] <= reach) y1++;
                tot = dp[x1][y1]-dp[x0][y1]-dp[x1][y0]+dp[x0][y0];
            }
            if(tot < C) break;
            //cout << "HI1" << endl;
            ret = min(ret, reach+1); y0++;
            if(y0 == yy) break;
            //cout << "HI2" << endl;
            if(y0 >= y1){ y1 = y0+1; reach = 0; }
            else reach -= ys[y0]-ys[y0-1];
            while(xs[x1-1]-xs[x0] > reach) x1--;
            tot = dp[x1][y1]-dp[x0][y1]-dp[x1][y0]+dp[x0][y0];
        }
    }
    cout << ret << '\n';
    /*for(int i = 0; i < xx; i++) cout << xs[i] << " ";
    cout << endl;
    for(int i = 0; i < yy; i++) cout << ys[i] << " ";
    cout << endl;
    for(int i = 0; i <= xx; i++){
        for(int j = 0; j <= yy; j++) cout << dp[i][j] << " ";
        cout << endl;
    }*/
    return 0;
}
