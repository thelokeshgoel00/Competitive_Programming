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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

struct Event{
    int pos, start, finish, val;
    bool operator<(const Event &other) const{ return pos < other.pos; }
};

struct Node{ int maxi, lazy; };

int N, K, ret = 0;
vector<int> xs;
Event events [200010];
Node tree [800010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void pushDown(int p, int L, int R){
    tree[p].maxi += tree[p].lazy;
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].lazy += tree[p].lazy;
        tree[ri].lazy += tree[p].lazy;
    }
    tree[p].lazy = 0;
}

long long evalMax(int p){ return tree[p].maxi+tree[p].lazy; }

void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    tree[p].maxi = max(evalMax(li), evalMax(ri));
}

void update(int p, int L, int R, int i, int j, int val){
    if(L > R || i > R || j < L) return;
    if(L >= i && R <= j){ tree[p].lazy += val; return; }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
    pullUp(p, L, R);
}

int main(){
    freopen("lazy.in", "r", stdin); freopen("lazy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int g, x, y, t, u; cin >> g >> x >> y;
        t = x+y; u = x-y; xs.push_back(t-K); xs.push_back(t+K+1);
        events[2*i] = {u-K, t-K, t+K+1, g};
        events[2*i+1] = {u+K+1, t-K, t+K+1, -g};
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    for(int i = 0; i < N; i++){
        int s = lower_bound(xs.begin(), xs.end(), events[2*i].start)-xs.begin();
        int f = lower_bound(xs.begin(), xs.end(), events[2*i].finish)-xs.begin();
        events[2*i].start = events[2*i+1].start = s;
        events[2*i].finish = events[2*i+1].finish = f;
    }
    sort(events, events+(2*N));
    for(int i = 0; i < 2*N; i++){
        int idx = i;
        while(idx < 2*N && events[i].pos == events[idx].pos){
            update(1, 0, 2*N-1, events[idx].start, events[idx].finish-1, events[idx].val);
            idx++;
        }
        ret = max(ret, tree[1].maxi);
        i = idx-1;
    }
    cout << ret << '\n';
    return 0;
}
