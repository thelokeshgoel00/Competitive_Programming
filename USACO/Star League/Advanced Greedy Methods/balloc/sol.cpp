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
#include <cstring>
#include <sstream>
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

struct Node{
    long long mini, lazy;
    Node(){ mini = -1; lazy = 0; }
};

int N, M, ret = 0;
vector<pair<int, int>> requests;
long long original [100010];
Node tree [400010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void pushDown(int p, int L, int R){
    tree[p].mini += tree[p].lazy;
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].lazy += tree[p].lazy;
        tree[ri].lazy += tree[p].lazy;
    }
    tree[p].lazy = 0;
}

long long evalMin(int p){ return tree[p].mini+tree[p].lazy; }

void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p].mini = min(evalMin(li), evalMin(ri));
}

void build(int p, int L, int R){
    if(L == R){
        tree[p].mini = original[L];
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].mini = min(tree[li].mini, tree[ri].mini);
}

void update(int p, int L, int R, int i, int j, long long val){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){ tree[p].lazy += val; return; }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
    pullUp(p, L, R);
}

long long minQuery(int p, int L, int R, int i, int j){
    if(L > R || i > R || j < L) return INF;
    if(L >= i && R <= j) return evalMin(p);
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    long long ret = INF;
    ret = min(ret, min(minQuery(li, L, (L+R)/2, i, j), minQuery(ri, (L+R)/2+1, R, i, j)));
    pullUp(p, L, R);
    return ret;
}

int main(){
    //freopen("first.in", "r", stdin); freopen("first.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> original[i];
    build(1, 0, N-1);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b; a--; b--;
        requests.push_back(make_pair(a, b));
    }
    sort(requests.begin(), requests.end());
    for(int i = M-1; i > -1; i--){
        if(minQuery(1, 0, N-1, requests[i].first, requests[i].second) == 0) continue;
        update(1, 0, N-1, requests[i].first, requests[i].second, -1); ret++;
    }
    cout << ret << '\n';
    return 0;
}
