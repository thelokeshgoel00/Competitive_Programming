#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>

using namespace std;

long long x, y, ret, val;
string a, b;
map<long long, long long> pRep, dp [20][2][2];

long long PRCalc(long long prod){
    long long curr = prod;
    if(pRep.find(prod) == pRep.end()){
        while(curr >= 10){
            long long next = 1;
            while(curr > 0){
                next *= curr%10;
                curr /= 10;
            }
            curr = next;
        }
        pRep[prod] = curr;
    }
    return pRep[prod];
}

long long recurse(int digit, int match, int nonzero, long long prod, string cap){
    if(digit == cap.length()){
        long long save = PRCalc(prod);
        if(save == val) return 1;
        return 0;
    }
    if(dp[digit][match][nonzero].find(prod) != dp[digit][match][nonzero].end())
        return dp[digit][match][nonzero][prod];
    long long sum = 0;
    for(int place = 0; place < 10; place++){
        if(match == 1 && place > cap[digit]-'0') break;
        long long nprod = prod; int nmatch = match, nnz = nonzero;
        if(place == 0 && nonzero == 1) nprod = 0;
        if(place > 0){ nprod *= place; nnz = 1; }
        if(place < cap[digit]-'0') nmatch = 0;
        sum += recurse(digit+1, nmatch, nnz, nprod, cap);
    }
    dp[digit][match][nonzero][prod] = sum;
    return sum;
}


int main(){
    cin >> x >> y >> val; x--;
    a = to_string(x); b = to_string(y);
    ret = recurse(0, 1, 0, 1, b);
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k].clear();
    ret -= recurse(0, 1, 0, 1, a);
    cout << ret << '\n';
    return 0;
}
