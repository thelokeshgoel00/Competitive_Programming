/*
ID: vamaddu1
PROG: moofest
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

int N;
pair<int, int> arr [20010];
long long treeCount [20010], treeDist [20010], totalDist = 0, ret = 0;

void add(int pos, long long val){
    while(pos < 20010){
        treeCount[pos]++; treeDist[pos] += val;
        pos += (pos&-pos);
    }
}

pair<long long, long long> query(int pos){
    pair<long long, long long> lol = mp(0, 0);
    while(pos > 0){
        lol.f += treeCount[pos]; lol.s += treeDist[pos];
        pos -= (pos&-pos);
    }
    return lol;
}

int main(){
    freopen("moofest.in", "r", stdin); freopen("moofest.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i].f >> arr[i].s;
    sort(arr, arr+N);
    for(int i = 0; i < N; i++){
        pair<long long, long long> cool = query(arr[i].s);
        ret += (long long)arr[i].f*(cool.f*arr[i].s+totalDist-2*cool.s-(i-cool.f)*arr[i].s);
        add(arr[i].s, arr[i].s); totalDist += arr[i].s;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
