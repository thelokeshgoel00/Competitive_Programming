/*
ID: vamaddu1
LANG: C++11
TASK: distinct
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
#include <bitset>
#include <math.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, K, Q, blockSize = 350, li = 0, ri = 0, total = 0, arr [100010], cnt [100010], ret [100010];
pair<pair<int, int>, int> queries [100010];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.f.f/blockSize != b.f.f/blockSize) return a.f.f/blockSize < b.f.f/blockSize;
    return a.f.s < b.f.s;
}

void add(int pos){
	cnt[arr[pos]]++;
	if(cnt[arr[pos]] == 1) total = (total+arr[pos]+1000000)%1000000;
}

void subtract(int pos){
	cnt[arr[pos]]--;
	if(cnt[arr[pos]] == 0) total = (total-arr[pos]+1000000)%1000000;
}

int main(){
    freopen("distinct.in", "r", stdin); freopen("distinct.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> K >> Q;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < Q; i++){
        cin >> queries[i].f.f >> queries[i].f.s;
        queries[i].f.f--; queries[i].f.s--;
        queries[i].s = i;
    }
    sort(queries, queries+Q, cmp);
    for(int i = 0; i < Q; i++){
        int L = queries[i].f.f, R = queries[i].f.s;
        while(li < L) subtract(li++);
        while(li > L) add(--li);
        while(ri <= R) add(ri++);
        while(ri > R+1) subtract(--ri);
        ret[queries[i].s] = total;
    }
    for(int i = 0; i < Q; i++) cout << ret[i] << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
