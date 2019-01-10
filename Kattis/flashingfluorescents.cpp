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
#define INF 5000000000000000000
#define MOD 1000000007

int N, goal = 0;
string s;
unordered_set<int> dp [2];

int main(){
    //freopen("disrupt.in", "r", stdin); freopen("disrupt.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> s; N = s.length();
    for(int i = 0; i < N; i++){
        goal *= 2;
        if(s[i] == '0') goal++;
    }
    if(goal == 0){
        cout << "0\n";
        return 0;
    }
    dp[0].insert(0);
    for(int i = 1; i <= N; i++){
        dp[i%2].clear();
        for(int mask : dp[(i-1)%2]){
            dp[i%2].insert(mask);
            int modify = ((1<<i)-1)<<(N-i);
            while(modify > 0){
                dp[i%2].insert(mask^modify);
                modify /= 2;
            }
        }
        if(dp[i%2].find(goal) != dp[i%2].end()){
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}
