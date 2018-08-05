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
#include <bitset>
#include <math.h>
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int kase;
string s;
long long dp [75][2][2][10];

bool isHill(string str){
    bool down = false;
    for(int i = 1; i < str.length(); i++){
        if(str[i] > str[i-1] && down) return false;
        if(str[i] < str[i-1]) down = true;
    }
    return true;
}

long long solveIt(int idx, int down, int match, int dig){
    if(dp[idx][down][match][dig] != -1) return dp[idx][down][match][dig];
    if(idx == s.length()) return dp[idx][down][match][dig] = 1;
    long long &ret = dp[idx][down][match][dig]; ret = 0;
    if(down){
        for(int i = 0; i <= dig; i++){
            if(match && i > s[idx]-'0') break;
            int nmatch = match && (i == s[idx]-'0');
            ret += solveIt(idx+1, down, nmatch, i);
        }
    }
    else{
        for(int i = 0; i < 10; i++){
            if(match && i > s[idx]-'0') break;
            int nmatch = match&(i == s[idx]-'0'), ndown = i < dig;
            ret += solveIt(idx+1, ndown, nmatch, i);
        }
    }
    return ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(9);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> s;
        if(!isHill(s)){
            cout << "-1\n";
            continue;
        }
        memset(dp, -1, sizeof(dp));
        cout << solveIt(0, 0, 1, 0)-1 << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
