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

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, freq [1000010], ret = 1;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(freq, 0, sizeof(freq));
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        freq[x]++;
    }
    for(int i = 2; i < 1000010; i++){
        int cnt = 0;
        for(int j = i; j < 1000010; j += i){
            cnt += freq[j];
            if(cnt > 1) break;
        }
        if(cnt > 1) ret = i;
    }
    cout << ret << '\n';
    return 0;
}
