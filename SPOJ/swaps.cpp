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

int N, M, sqrtN = 0, arr [250010];
long long tree [510][50010], ret = 0;

void add(int block, int pos, long long val){
    for(int x = block; x <= sqrtN; x += (x&-x))
        for(int y = pos; y < 50010; y += (y&-y))
            tree[x][y] += val;
}

long long sum(int block, int pos){
    long long ans = 0;
    for(int x = block; x > 0; x -= (x&-x))
        for(int y = pos; y > 0; y -= (y&-y))
            ans += tree[x][y];
    return ans;
}

long long query(int i, int val){
    long long ans = sum(i/sqrtN, val);
    for(int j = sqrtN*(i/sqrtN); j <= i; j++)
        if(arr[j] <= val)
            ans++;
    return ans;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N; while(sqrtN*sqrtN < N) sqrtN++;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        add(i/sqrtN+1, arr[i], 1);
    }
    for(int i = 0; i < N; i++) ret += (long long)(i+1)-query(i, arr[i]);
    cin >> M;
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y; x--;
        ret -= (x-query(x-1, arr[x])-1)+(query(N-1, arr[x]-1)-query(x, arr[x]-1));
        add(x/sqrtN+1, arr[x], -1);
        arr[x] = y;
        add(x/sqrtN+1, arr[x], 1);
        ret += (x-query(x-1, arr[x])-1)+(query(N-1, arr[x]-1)-query(x, arr[x]-1));
        cout << ret << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
