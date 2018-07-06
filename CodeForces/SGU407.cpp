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

string add(string &a, string &b){
    int la = a.size(), lb = b.size(); string ret;
    for(int i = 0, c = 0; i < la || i < lb || c > 0; i++){
        if(i < la) c += a[i]-'0';
        if(i < lb) c += b[i]-'0';
        ret += '0'+c%10;
        c /= 10;
    }
    return ret;
}

string mult(string &a, int b){
    int la = a.size(); string ret;
    for(int i = 0, c = 0; i < la || c > 0; i++){
        if(i < la) c += (a[i]-'0')*b;
        ret += '0'+c%10;
        c /= 10;
    }
    return ret;
}

void display(string s){
    reverse(s.begin(), s.end());
    cout << s.c_str() << '\n';
}

int N, M;
string dp [2][2];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; dp[0][0] = "1"; dp[0][1] = "0";
    for(int i = 1, curr = 1; i <= M; i++, curr ^= 1){
        dp[curr][0] = mult(dp[curr^1][1], N);
        dp[curr][1] = mult(dp[curr^1][1], 2);
        dp[curr][1] = add(dp[curr][1], dp[curr^1][0]);
    }
    display(dp[M&1][0]);
    return 0;
}
