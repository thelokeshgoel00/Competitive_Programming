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

int N, newPos [100010], leftMost [100010], rightMost [100010], ret [100010];
pair<pair<int, int>, int> cans [100010];
stack<int> st;
bool hasChanged = true;

void update(int i){
    while(st.size() > 0 && abs(cans[i].f.f-cans[st.top()].f.f) <= cans[i].f.s){
        int j = st.top(); st.pop();
        if(rightMost[i] < rightMost[j]){
            rightMost[i] = rightMost[j];
            hasChanged = true;
        }
        if(leftMost[i] > leftMost[j]){
            leftMost[i] = leftMost[j];
            hasChanged = true;
        }
    }
    st.push(i);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cans[i].f.f >> cans[i].f.s;
        leftMost[i] = rightMost[i] = cans[i].s = i;
    }
    sort(cans, cans+N);
    while(hasChanged){
        hasChanged = false;
        for(int i = 0; i < N; i++) update(i);
        st = stack<int>();
        for(int i = N-1; i > -1; i--) update(i);
        st = stack<int>();
    }
    for(int i = 0; i < N; i++) ret[cans[i].s] = rightMost[i]-leftMost[i]+1;
    for(int i = 0; i < N; i++) cout << ret[i] << (i < N-1 ? ' ' : '\n');
    return 0;
}
