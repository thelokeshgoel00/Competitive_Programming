#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define MOD 1000000007

//https://math.stackexchange.com/questions/1234696/number-of-ways-you-can-form-pairs-with-a-group-of-people-when-certain-people-can
//https://math.stackexchange.com/questions/2093921/number-of-ways-to-make-n-pairs?rq=1

int kase;
long long waysToFormPairs [5001], comboIt [5001][5001];
map<int, long long> speedup;

int main(){
    waysToFormPairs[0] = 1; comboIt[0][0] = 1;
    for(int i = 1; i < 5001; i++){ waysToFormPairs[i] = (waysToFormPairs[i-1]*(long long)(2*i-1))%MOD; }
    for(int i = 1; i < 5001; i++){
        comboIt[i][0] = 1;
        for(int j = 1; j <= i; j++) comboIt[i][j] = (comboIt[i-1][j]+comboIt[i-1][j-1])%MOD;
    }
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        int x; cin >> x; if(x%2 == 1) x++;
        if(speedup.find(x) != speedup.end()){ cout << speedup[x] << '\n'; continue; }
        long long sum = 0; int i = x/2, counter = 0;
        while(i > -1){
            long long add = (comboIt[x/2][counter]*waysToFormPairs[i])%MOD;
            if(counter%2 == 1) add *= -1;
            sum = (sum+add+MOD)%MOD;
            i--; counter++;
        }
        cout << sum << '\n';
        speedup[x] = sum;
    }
    return 0;
}
