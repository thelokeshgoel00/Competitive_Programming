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

int maxCoord = 2000010, kase, N, prevX;
pair<pair<long long, long long>, long long> tree [8000100];
pair<long long, long long> ret;
pair<pair<long long, long long>, pair<int, int>> events [200010];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void build(int p, int L, int R){
    if(L == R){
        tree[p].f.f = tree[p].s = 0;
        tree[p].f.s = 1;
        return;
    }
    int li = left(p), ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p].f.f = tree[p].s = 0;
    tree[p].f.s = tree[li].f.s+tree[ri].f.s;
}

void resetStuff(){
    build(1, 0, maxCoord);
    ret.f = ret.s = 0;
}

void pushDown(int p, int L, int R){
    tree[p].f.f += tree[p].s;
    int li = left(p), ri = right(p);
    if(L != R){
        tree[li].s += tree[p].s;
        tree[ri].s += tree[p].s;
    }
    tree[p].s = 0;
}

pair<long long, long long> eval(int p){ return mp(tree[p].f.f+tree[p].s, tree[p].f.s); }

void pullUp(int p, int L, int R){
    int li = left(p), ri = right(p);
    pair<long long, long long> lt = eval(li), rt = eval(ri);
    if(lt.f == rt.f){ tree[p].f.f = lt.f; tree[p].f.s = lt.s+rt.s; }
    else tree[p].f = max(lt, rt);
}

void update(int p, int L, int R, int i, int j, long long val){
    if(i > R || j < L) return;
    if(L >= i && R <= j){ tree[p].s += val; return; }
    pushDown(p, L, R);
    int li = left(p), ri = right(p);
    update(li, L, (L+R)/2, i, j, val); update(ri, (L+R)/2+1, R, i, j, val);
    pullUp(p, L, R);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N; resetStuff();
        for(int i = 0; i < N; i++){
            int a, b, c, d, s; cin >> a >> b >> c >> d >> s;
            b += 1000000; d += 1000000-1;
            events[2*i].f.f = a; events[2*i].f.s = s;
            events[2*i].s.f = b; events[2*i].s.s = d;
            events[2*i+1].f.f = c; events[2*i+1].f.s = -s;
            events[2*i+1].s.f = b; events[2*i+1].s.s = d;
        }
        sort(events, events+2*N); prevX = events[0].f.f;
        for(int i = 0; i < 2*N; ){
            long long dx = events[i].f.f-prevX, maxi = tree[1].f.f+tree[1].s;
            if(maxi > ret.f){ ret.f = maxi; ret.s = dx*tree[1].f.s; }
            else if(maxi == ret.f) ret.s += dx*tree[1].f.s;
            int j = i;
            while(j < 2*N && events[j].f.f == events[i].f.f){
                update(1, 0, maxCoord, events[j].s.f, events[j].s.s, events[j].f.s);
                j++;
            }
            prevX = events[i].f.f; i = j;
        }
        cout << ret.f << ' ' << ret.s << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
