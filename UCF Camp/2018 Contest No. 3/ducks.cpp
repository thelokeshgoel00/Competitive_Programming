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

int N, K, ret;
string s;
unordered_map<long long, int> dp;

long long hashState(long long preDucks, long long runsNeeded, long long curr, long long wand){
    return preDucks*pow(2010, 3)+runsNeeded*pow(2010, 2)+curr*2010+wand;
}

int solveIt(int preDucks, int runsNeeded, int curr, int wand){
    if(runsNeeded == 0 || (runsNeeded == 1 && preDucks == N)) return wand;
    if(curr == s.length()) return 2010;
    if(runsNeeded*N-preDucks+runsNeeded-1 > s.length()-curr) return 2010;
    long long hashy = hashState(preDucks, runsNeeded, curr, wand);
    if(dp.find(hashy) != dp.end()) return dp[hashy];
    int canEnd = preDucks == N, off, on;
    if(s[curr] == 'D'){
        off = wand+solveIt(min(preDucks+1, N), runsNeeded, curr+1, 0);
        on = solveIt(0, runsNeeded-canEnd, curr+1, 1);
    }
    else{
        off = wand+solveIt(0, runsNeeded-canEnd, curr+1, 0);
        on = solveIt(min(preDucks+1, N), runsNeeded, curr+1, 1);
    }
    return dp[hashy] = min(off, on);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K >> s;
    ret = solveIt(0, K, 0, 0);
    cout << (ret == 2010 ? -1 : ret) << '\n';
    return 0;
}
