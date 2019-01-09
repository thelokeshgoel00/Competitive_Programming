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

struct Line{
    long long x, y;
    Line(long long a, long long b){ x = a; y = b; }
};

bool operator <(Line a, Line b){
    if(a.x == b.x) return a.y > b.y;
    else return a.x > b.x;
}

template<class Line>
class CHTrick{
    public:
    bool cmp(Line a, Line b, Line c){ return (c.y-a.y)*(a.x-b.x) <= (a.x-c.x)*(b.y-a.y); }
    int sizex(){ return cht.size(); }
    void add(Line a){
        while(cht.size() > 1 && cmp(cht[cht.size()-2], cht[cht.size()-1], a)) cht.pop_back();
        cht.emplace_back(a);
    }
    long long eval(Line b, long long a){ return b.x*a+b.y; }
    void mergev(vector<Line> nhcht){
        vector<Line> newcht;
        for(int i = 0; i < nhcht.size()+cht.size(); i++) newcht.pb(Line(0, 0));
        merge(nhcht.begin(), nhcht.end(), cht.begin(), cht.end(), newcht.begin()); cht.clear();
        for(int i = 0; i < newcht.size(); i++) add(newcht[i]);
    }
    long long querymin(long long x){
        if(cht.size() == 0) return INF;
        int l = 0, r = cht.size()-1; r--;
        int ansj = -1;
        while(l <= r){
            int mid = (l+r)/2;
            if(eval(cht[mid], x) >= eval(cht[mid+1], x)){
                l = mid + 1;
                ansj = mid;
            }
            else r = mid - 1;
        }
        long long best = eval(cht.front(), x);
        if(ansj != -1) best = min(best, eval(cht[ansj], x));
        ansj++;
        if(ansj < cht.size()) best = min(best, eval(cht[ansj], x));
        return best;
    }
    vector<Line> vectorT(){ return cht; }
    void clearv(){ cht.clear(); }
    vector<Line> cht;
};

CHTrick<Line> chts [25];

void add(Line a){
    vector<Line> v;
    v.push_back(a);
    chts[0].mergev(v);
    for(int i = 0; i < 25; i++)
        if(chts[i].sizex() > (1<<i)){
            chts[i+1].mergev(chts[i].vectorT());
            chts[i].clearv();
        }
}

long long query(long long x){
    long long best = INF;
    for(int i = 0; i < 25; i++) best = min(best, chts[i].querymin(x));
    return best;
}

int N;
long long heights [100010], costs [100010];

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> heights[i];
    for(int i = 1; i <= N; i++){ cin >> costs[i]; costs[i] += costs[i-1]; }
    add(Line(-2*heights[1], heights[1]*heights[1]-costs[1]));
    for(int i = 2; i <= N; i++){
        long long val = query(heights[i])+heights[i]*heights[i]+costs[i-1];
        if(i == N) cout << val << '\n';
        else add(Line(-2*heights[i], heights[i]*heights[i]-costs[i]+val));
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
