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

int kase, N, arr [100010], prevy [100010], nexty [100010];
unordered_map<int, int> lastSeen;

bool solveIt(int li, int ri){
    if(li >= ri) return true;
    for(int i = li, j = ri; i <= j; i++, j--){
        if(prevy[i] < li && nexty[i] > ri)
            return solveIt(li, i-1) && solveIt(i+1, ri);
        else if(prevy[j] < li && nexty[j] > ri)
            return solveIt(li, j-1) && solveIt(j+1, ri);
    }
    return false;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; lastSeen = unordered_map<int, int>();
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            prevy[i] = -1; nexty[i] = N;
            if(lastSeen.find(arr[i]) != lastSeen.end()){
                int other = lastSeen[arr[i]];
                prevy[i] = other;
                nexty[other] = i;
            }
            lastSeen[arr[i]] = i;
        }
        cout << solveIt(0, N-1) << '\n';
    }
    return 0;
}
