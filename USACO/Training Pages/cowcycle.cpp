/*
ID: vamaddu1
PROG: cowcycle
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

int F, R, flo, fhi, rlo, rhi, tempf [5], tempr [10], retf [5], retr [10];
double minVar = INF;

void testIt(){
    vector<double> quotients;
    for(int i = 0; i < F; i++)
        for(int j = 0; j < R; j++)
            quotients.push_back(double(tempf[i])/double(tempr[j]));
    sort(quotients.begin(), quotients.end());
    double avg = 0.0, var = 0.0;
    for(int i = 1; i < quotients.size(); i++) avg += quotients[i]-quotients[i-1];
    avg /= double(quotients.size()-1);
    for(int i = 1; i < quotients.size(); i++) var += pow(quotients[i]-quotients[i-1]-avg, 2.0);
    if(var < minVar){
        minVar = var;
        for(int i = 0; i < F; i++) retf[i] = tempf[i];
        for(int i = 0; i < R; i++) retr[i] = tempr[i];
    }
}

void dfsR(int pos, int lo){
    if(pos == R){
        if(tempf[F-1]*tempr[R-1] >= 3*tempf[0]*tempr[0]) testIt();
        return;
    }
    for(int i = lo; i <= rhi; i++){
        tempr[pos] = i;
        dfsR(pos+1, i+1);
    }
}

void dfsF(int pos, int lo){
    if(pos == F){
        dfsR(0, rlo);
        return;
    }
    for(int i = lo; i <= fhi; i++){
        tempf[pos] = i;
        dfsF(pos+1, i+1);
    }
}

int main(){
    freopen("cowcycle.in", "r", stdin); freopen("cowcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> F >> R >> flo >> fhi >> rlo >> rhi;
    dfsF(0, flo);
    for(int i = 0; i < F; i++){
        cout << retf[i];
        if(i != F-1) cout << ' ';
        else cout << '\n';
    }
    for(int i = 0; i < R; i++){
        cout << retr[i];
        if(i != R-1) cout << ' ';
        else cout << '\n';
    }
    return 0;
}
