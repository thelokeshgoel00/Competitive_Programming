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
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int kase = 1, N, M, nexts [100010];
long long arr [100010], tree [100010];

void add(int pos, long long x){
    while(pos < 100010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

int findNext(int x){
    if(x == nexts[x]) return x;
    return nexts[x] = findNext(nexts[x]);
}

void update(int a, int b){
    for(int i = findNext(a); i <= b; i = findNext(i+1)){
        if(arr[i] == 1){ nexts[i] = max(nexts[i], i+1); continue; }
        add(i, -arr[i]);
        arr[i] = (long long)sqrt(arr[i]);
        add(i, arr[i]);
        if(arr[i] == 1) nexts[i] = i+1;
    }
}

long long query(int pos){
    long long sum = 0ll;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    while(cin >> N){
        fill(tree, tree+N+1, 0); nexts[N+1] = N+1;
        for(int i = 1; i <= N; i++){
            cin >> arr[i];
            add(i, arr[i]); nexts[i] = i;
        }
        cin >> M; cout << "Case #" << kase << ":\n";
        for(int i = 0; i < M; i++){
            int type, a, b; cin >> type >> a >> b;
            if(a > b) swap(a, b);
            if(type == 0) update(a, b);
            else cout << query(b)-query(a-1) << '\n';
        }
        cout << '\n'; kase++;
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
