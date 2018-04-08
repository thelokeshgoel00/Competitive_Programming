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

int kase = 0, N;
long long fibo [110];
string s;

long long recurseIt(int x, string now){
    if(x < 2){
        if(x == 0 && now.compare("0") == 0) return 1;
        if(x == 1 && now.compare("1") == 0) return 1;
        return 0;
    }
    if(now.length() == 1){
        if(now[0] == '0') return fibo[x-2];
        else return fibo[x-1];
    }
    if(now.compare("11") == 0){
        if(x < 3) return 0;
        else return fibo[x-3]-x%2;
    }
    if(now.find("00") != string::npos || now.find("111") != string::npos) return 0;
    int idx = 0; string reduce = "";
    while(idx < now.length()){
        if(idx < now.length()-1 && now[idx] == '1' && now[idx+1] == '0'){
            reduce += '1';
            idx++;
        }
        else reduce += '0';
        idx++;
    }
    if(reduce[0] == '0') reduce = '1'+reduce;
    //cout << x << " " << reduce << endl;
    long long ret = recurseIt(x-1, reduce);
    if(now[now.length()-1] == '1'){
        reduce[reduce.length()-1] = '1';
        //cout << x << " " << reduce << endl;
        ret += recurseIt(x-1, reduce);
    }
    return ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    fibo[0] = fibo[1] = 1;
    for(int i = 2; i < 110; i++) fibo[i] = fibo[i-1]+fibo[i-2];
    while(cin >> N >> s){
        kase++;
        if(s[0] == '0' && s.length() > 1) s = '1'+s;
        cout << "Case " << kase << ": " << recurseIt(N, s) << '\n';
    }
    return 0;
}
