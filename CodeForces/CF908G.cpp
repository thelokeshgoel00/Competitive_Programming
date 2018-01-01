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

string s;
int freq [10], cnt = 0;
long long powTen [710], sumPow [710], dp [710][710][10], ret = 0;

long long solveIt(int idx, int amt, int dig){
    if(dp[idx][amt][dig] != -1) return dp[idx][amt][dig];
    if(idx == 0){
        if(amt == 0) return dp[idx][amt][dig] = 0;
        return dp[idx][amt][dig] = (sumPow[amt-1]*(long long)dig)%MOD;
    }
    dp[idx][amt][dig] = (solveIt(idx-1, amt, dig)*(long long)(dig+10*(9-dig)))%MOD; // add digit below and digit above
    dp[idx][amt][dig] = (dp[idx][amt][dig]+solveIt(idx-1, amt+1, dig))%MOD; // add digit equal to
    return dp[idx][amt][dig];
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> s; memset(freq, 0, sizeof(freq)); memset(dp, -1, sizeof(dp));
    powTen[0] = sumPow[0] = 1;
    for(int i = 1; i < 710; i++){
        powTen[i] = (powTen[i-1]*10)%MOD;
        sumPow[i] = (sumPow[i-1]+powTen[i])%MOD;
    }
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < (s[i]-'0'); j++){
            freq[j]++;
            int ri = i+1-freq[0];
            for(int k = 1; k < 10; k++){
                ri -= freq[k];
                ret = (ret+(solveIt(s.length()-i-1, freq[k], k)*powTen[ri])%MOD)%MOD;
            }
            freq[j]--;
        }
        freq[s[i]-'0']++;
    }
    for(int i = 9; i > 0; i--)
        while(freq[i] > 0){
            ret = (ret+(long long)i*powTen[cnt])%MOD;
            freq[i]--; cnt++;
        }
    cout << ret << '\n';
    return 0;
}
