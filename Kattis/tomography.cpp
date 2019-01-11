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

int N, M, rowSums [1010], colSums [1010], rowTotal = 0, colTotal = 0;

int main(){
    //freopen("dirtraverse.in", "r", stdin); freopen("dirtraverse.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 0; i < N; i++){ cin >> rowSums[i]; rowTotal += rowSums[i]; }
    for(int i = 0; i < M; i++){ cin >> colSums[i]; colTotal += colSums[i]; }
    if(rowTotal != colTotal){
        cout << "No\n";
        return 0;
    }
    for(int i = 0; i < N; i++){
        int k = rowSums[i];
        if(k == 0) continue;
        sort(colSums, colSums+M, greater<int>());
        if(colSums[k-1] == 0){
            cout << "No\n";
            return 0;
        }
        for(int j = 0; j < k; j++) colSums[j]--;
    }
    if(*max_element(colSums, colSums+M) == 0) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
