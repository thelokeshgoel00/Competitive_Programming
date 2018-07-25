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

int N, Q, ori [100010], id = 0, dfsOrder [100010], dfsID [100010], maxi [100010];
int pres = 1<<15, preComp [1<<15];
stack<pair<int, int>> stk;
pair<int, int> tree [400010];
vector<int> children [100010];

int popcount(int x){
    int cnt = 0;
    while(x > 0){
        cnt += preComp[x%pres];
        x /= pres;
    }
    return cnt;
}

void dfs(int curr){
    /*dfsOrder[id] = curr; dfsID[curr] = id++;
    for(int nexty : children[curr]) dfs(nexty);
    maxi[dfsID[curr]] = id-1;*/
    stk.push(mp(0, 0));
    while(stk.size() > 0){
        pair<int, int> now = stk.top(); stk.pop();
        if(now.s == 0){ dfsOrder[id] = now.f; dfsID[now.f] = id++; }
        if(now.s < children[now.f].size()){
            stk.push(mp(now.f, now.s+1));
            stk.push(mp(children[now.f][now.s], 0));
        }
        else maxi[dfsID[now.f]] = id-1;
    }
}

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void update(int p, int L, int R, int place, int val){
    if(L == R){
        tree[p] = mp(popcount(val), val);
        return;
    }
    int li = left(p), ri = right(p);
    if(place <= (L+R)/2) update(li, L, (L+R)/2, place, val);
    if(place >= (L+R)/2+1) update(ri, (L+R)/2+1, R, place, val);
    tree[p] = max(tree[li], tree[ri]);
}

pair<int, int> query(int p, int L, int R, int i, int j){
    if(L >= i && R <= j) return tree[p];
    int li = left(p), ri = right(p);
    pair<int, int> ret = mp(0, 0);
    if((L+R)/2 >= i) ret = max(ret, query(li, L, (L+R)/2, i, j));
    if((L+R)/2+1 <= j) ret = max(ret, query(ri, (L+R)/2+1, R, i, j));
    return ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> Q; preComp[0] = 0;
    for(int i = 1; i < pres; i++) preComp[i] = preComp[i-(i&-i)]+1;
    for(int i = 0; i < N; i++) cin >> ori[i];
    for(int i = 1; i < N; i++){
        int par; cin >> par; par--;
        children[par].pb(i);
    }
    dfs(0);
    for(int i = 0; i < N; i++) update(1, 0, N-1, i, ori[dfsOrder[i]]);
    for(int i = 0; i < Q; i++){
        int t, r; cin >> t >> r; r = dfsID[r-1];
        if(t == 1) cout << query(1, 0, N-1, r, maxi[r]).s << '\n';
        else{
            int c; cin >> c;
            update(1, 0, N-1, r, c);
        }
    }
    return 0;
}
