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

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, B, pos, ret = 2000000000;
pair<int, int> bales [100010];

int main(){
    freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> B;
    for(int i = 0; i < N; i++) cin >> bales[i].second >> bales[i].first;
    sort(bales, bales+N); pos = upper_bound(bales, bales+N, make_pair(B, -1))-bales;
    for(int i = pos-1, j = pos; i > -1; i--)
        while(j < N && bales[j].first-bales[i].first <= bales[i].second){
            ret = min(ret, bales[j].first-bales[i].first-bales[j].second);
            j++;
        }
    for(int i = pos, j = pos-1; i < N; i++)
        while(j > -1 && bales[i].first-bales[j].first <= bales[i].second){
            ret = min(ret, bales[i].first-bales[j].first-bales[j].second);
            j--;
        }
    if(ret == 2000000000) cout << "-1\n";
    else cout << max(ret, 0) << '\n';
    return 0;
}
