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

int kase, N, id;
tuple<int, int, long long> intervals [10010]; // end, start, value
set<int> allEnd;
unordered_map<int, int> compress;
long long tree [40050], ret;

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void update(int p, int L, int R, int place, long long val){
    if(L > place || R < place) return;
    if(L == R){
        tree[p] = max(tree[p], val);
        return;
    }
    int li = left(p); int ri = right(p);
    update(li, L, (L+R)/2, place, val); update(ri, (L+R)/2+1, R, place, val);
    tree[p] = max(tree[li], tree[ri]);
}

long long query(int p, int L, int R, int i, int j){
    if(j < L || i > R) return 0;
    if(L >= i && R <= j) return tree[p];
    int li = left(p); int ri = right(p);
    return max(query(li, L, (L+R)/2, i, j), query(ri, (L+R)/2+1, R, i, j));
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; id = 0; allEnd.clear(); allEnd.insert(0); compress.clear(); memset(tree, 0, sizeof(tree)); ret = 0;
        for(int i = 0; i < N; i++){
            int s, d; long long v; cin >> s >> d >> v;
            intervals[i] = make_tuple(s+d, s, v);
            allEnd.insert(s+d);
        }
        sort(intervals, intervals+N);
        for(auto it = allEnd.begin(); it != allEnd.end(); it++){ compress[*it] = id; id++; }
        for(int i = 0; i < N; i++){
            auto it = allEnd.lower_bound(get<1>(intervals[i]));
            while(it == allEnd.end() || *it > get<1>(intervals[i])) it--;
            int idx1 = compress[*it], idx2 = compress[get<0>(intervals[i])];
            long long now = get<2>(intervals[i])+query(1, 0, N-1, 0, idx1);
            ret = max(ret, now); update(1, 0, N-1, idx2, now);
        }
        cout << ret << '\n';
    }
    return 0;
}
