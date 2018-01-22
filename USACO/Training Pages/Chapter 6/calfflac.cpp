/*
ID: vamaddu1
PROG: calfflac
LANG: C++11
*/

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
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, ret;
string ori, add, palin = "";
vector<pair<int, int>> chars;
long long powa [20010], reverseHash [20010];

int main(){
    freopen("calfflac.in", "r", stdin); freopen("calfflac.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(getline(cin, add)) ori += add+'\n';
    powa[0] = 1;
    for(int i = 0; i < ori.length(); i++){
        char c = ori[i];
        if(islower(c) || isupper(c)) chars.push_back(make_pair(tolower(c)-'a', i));
        powa[i+1] = (powa[i]*47ll)%MOD;
    }
    N = chars.size();
    for(int mid = min(N, 2000); mid > 0; mid--){
        bool found = false;
        long long hashy = 0;
        for(int i = N-1; i > N-1-mid; i--) hashy = (hashy*47ll+chars[i].first)%MOD;
        reverseHash[N-mid] = hashy;
        for(int i = N-1-mid; i > -1; i--){
            hashy = (hashy*47ll+chars[i].first+MOD-(powa[mid]*chars[i+mid].first)%MOD)%MOD;
            reverseHash[i] = hashy;
        }
        hashy = 0;
        for(int i = 0; i < N; i++){
            if(i < mid) hashy = (hashy*47ll+chars[i].first)%MOD;
            else hashy = (hashy*47ll+chars[i].first+MOD-(powa[mid]*chars[i-mid].first)%MOD)%MOD;
            if(i >= mid-1)
                if(hashy == reverseHash[i-mid+1]){
                    int st = i-mid+1, en = i; ret = mid;
                    palin = ori.substr(chars[st].second, chars[en].second-chars[st].second+1); found = true;
                    break;
                }
        }
        if(found) break;
    }
    cout << ret << '\n' << palin << '\n';
    return 0;
}
