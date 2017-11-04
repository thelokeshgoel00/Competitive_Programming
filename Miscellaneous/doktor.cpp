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

int N, arr [500010], idx [500010], leftSum [500010], rightSum [500010], ret = 0, retL = 1, retR = 1;
vector<int> rotateGroup [1000010];

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; leftSum[0] = rightSum[N+1] = 0;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        idx[arr[i]] = i; rotateGroup[i+arr[i]].push_back(i);
        leftSum[i] = leftSum[i-1]+(arr[i] == i);
    }
    for(int i = 0; i < 1000010; i++) sort(rotateGroup[i].begin(), rotateGroup[i].end());
    for(int i = N; i > 0; i--) rightSum[i] = rightSum[i+1]+(arr[i] == i);
    for(int i = 1; i <= N; i++){
        int L = i, R = idx[i];
        if(L > R) swap(L, R);
        int temp = (upper_bound(rotateGroup[L+R].begin(), rotateGroup[L+R].end(), R)-
                    lower_bound(rotateGroup[L+R].begin(), rotateGroup[L+R].end(), L))+leftSum[L-1]+rightSum[R+1];
        if(temp > ret){ ret = temp; retL = L; retR = R; }
    }
    cout << arr[retL] << ' ' << arr[retR] << '\n';
    return 0;
}
