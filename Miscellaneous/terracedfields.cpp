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

int kase;
string s;
long long N, cumSum [125], dp [25][2][2][25], ret;

long long solveIt(int idx, bool isUnder, bool isZero, long long cnt){
    if(dp[idx][isUnder][isZero][cnt] != -1) return dp[idx][isUnder][isZero][cnt];
    if(idx == 20) return dp[idx][isUnder][isZero][cnt] = cnt;
    dp[idx][isUnder][isZero][cnt] = 0;
    for(int dig = 0; dig < 10; dig++){
        if(dig > s[idx]-'0' && !isUnder) break;
        bool nZero = dig == 0 && isZero, nUnder = isUnder || dig < s[idx]-'0';
        int ncnt = cnt+(dig == 6 || dig == 8);
        dp[idx][isUnder][isZero][cnt] += solveIt(idx+1, nUnder, nZero, ncnt);
    }
    return dp[idx][isUnder][isZero][cnt];
}

int main(){
    //freopen("greedy.in", "r", stdin); freopen("greedy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase; cumSum[0] = 0;
    for(int i = 1; i < 125; i++){
        int lol = 8*i; cumSum[i] = cumSum[i-1];
        while(lol > 0){
            if(lol%10 == 6 || lol%10 == 8) cumSum[i]++;
            lol /= 10;
        }
    }
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; s = "";
        if(N > 999){
            s = to_string(N); s = s.substr(0, s.length()-3);
            while(s.length() < 20) s = '0'+s;
            memset(dp, -1, sizeof(dp));
        }
        if(s.length() > 0){
            long long cnt = 0;
            for(int i = 0; i < s.length(); i++)
                if(s[i] == '6' || s[i] == '8')
                    cnt++;
            ret = (N/1000)*cumSum[124]+cumSum[(int)(N%1000)/8]+solveIt(0, false, true, 0)*125
                -cnt*(124-(N%1000)/8);
        }
        else ret = cumSum[(int)N/8];
        if(N%8 != 0){
            s = to_string(N);
            for(int i = 0; i < s.length(); i++)
                if(s[i] == '6' || s[i] == '8')
                    ret++;
        }
        cout << ret << '\n';
    }
    return 0;
}
