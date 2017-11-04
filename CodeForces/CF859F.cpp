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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, idx = 0;
long long C, numSize [400010], sumSizes [400010], retSum [200010];
deque<int> dq;

long long getSum(long long arr [], int x, int y){ return arr[y]-arr[x-1]; }
long long getVal(int x, int y){ return getSum(sumSizes, x*2-1, y*2-1)-getSum(retSum, x, y-1); }

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> C; sumSizes[0] = retSum[0] = 0;
    for(int i = 1; i < 2*N; i++){
        cin >> numSize[i];
        sumSizes[i] = sumSizes[i-1]+numSize[i];
    }
    for(int i = 1; i <= N; i++){
        while(dq.size() > 0 && getVal(dq.back(), i) < numSize[i*2-1]) dq.pop_back();
        dq.push_back(i);
        while(dq.size() > 0 && getSum(sumSizes, dq.front()*2-1, i*2-1) >= C) dq.pop_front();
        while(idx+1 <= N && getSum(sumSizes, (idx+1)*2-1, i*2-1) >= C) idx++;
        long long add = 0;
        if(idx != 0) add = max(add, C-getSum(retSum, idx, i-1));
        if(dq.size() > 0) add = max(add, getVal(dq.front(), i));
        retSum[i] = retSum[i-1]+add;
        //cout << retSum[i] << " " << idx << endl;
    }
    cout << retSum[N] << '\n';
    return 0;
}
