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

int N, M, arr [100010];
vector<pair<int, int>> nums;
vector<int> tree [400010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        tree[p].pb(nums[L].s);
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    merge(tree[li].begin(), tree[li].end(), tree[ri].begin(), tree[ri].end(), back_inserter(tree[p]));
}

int query(int p, int L, int R, int i, int j, int k){
    if(L == R) return tree[p][0];
    int li = left(p), ri = right(p);
    int tot = upper_bound(tree[li].begin(), tree[li].end(), j)-lower_bound(tree[li].begin(), tree[li].end(), i);
    if(tot >= k) return query(li, L, (L+R)/2, i, j, k);
    else return query(ri, (L+R)/2+1, R, i, j, k-tot);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(9);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        nums.pb(mp(arr[i], i));
    }
    sort(nums.begin(), nums.end());
    build(1, 0, N-1);
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c; a--; b--;
        cout << arr[query(1, 0, N-1, a, b, c)] << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
