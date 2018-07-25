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

string a, b, c;
int dp [300010], ret;

string combineIt(string s, string t){
    string w = t+'#'+s; dp[0] = 0;
    for(int i = 1, j = 0; i < w.length(); i++){
        while(j > 0 && w[i] != w[j]) j = dp[j-1];
        if(w[i] == w[j]) j++;
        dp[i] = j;
    }
    for(int i = t.length()+1; i < w.length(); i++)
        if(dp[i] == t.length())
            return s;
    stringstream concat; concat << s;
    for(int i = dp[w.length()-1]; i < t.length(); i++) concat << t[i];
    return concat.str();
}

int testIt(string x, string y, string z){
    string s = x;
    s = combineIt(s, y); s = combineIt(s, z);
    return s.length();
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> a >> b >> c; ret = a.length()+b.length()+c.length();
    ret = min(ret, testIt(a, b, c)); ret = min(ret, testIt(a, c, b));
    ret = min(ret, testIt(b, a, c)); ret = min(ret, testIt(b, c, a));
    ret = min(ret, testIt(c, a, b)); ret = min(ret, testIt(c, b, a));
    cout << ret << '\n';
    return 0;
}
