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

int N, arr [110][110], ret = -MOD;

int main(){
    //freopen("dirtraverse.in", "r", stdin); freopen("dirtraverse.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            arr[i][j] += arr[i-1][j];
        }
        for(int k = 1; k <= i; k++){
            int curr = 0;
            for(int j = 1; j <= N; j++){
                curr += arr[i][j]-arr[k-1][j];
                ret = max(ret, curr);
                curr = max(curr, 0);
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
