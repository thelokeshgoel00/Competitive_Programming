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
 
template <typename T, bool isMin>
struct ConvexHullTrick{
    using P = pair<T, T>;
    deque<P> L;
    inline T getY(const P &a,const T &x){ return a.first*x+a.second; }
    inline bool check(const P &a,const P &b,const P &c){
        return (b.first-a.first)*(c.second-b.second)
        >= (b.second-a.second)*(c.first-b.first);
    }
    void add(T a, T b){
        if(!isMin) a *= -1, b*= -1;
        P line(a, b);
        if(!L.empty() && L.back().first == a){
            line.second = min(line.second, L.back().second);
            L.pop_back();
        }
        while(L.size() > 1 && check(L[L.size()-2], L[L.size()-1], line)) L.pop_back();
        L.emplace_back(line);
    }
    T get(T x){
        if(L.empty()) return isMin ? INF : -INF;
        int lo = -1, hi = L.size()-1;
        while(lo+1 < hi){
            int mid = (lo+hi)/2;
            if(getY(L[mid], x) >= getY(L[mid+1],x)) lo = mid;
            else hi = mid;
        }
        return (!isMin ? -1 : 1)*getY(L[hi], x);
    }
};
 
int N;
long long C, arr [1000010];
ConvexHullTrick<long long, true> cht;
 
int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> C;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cht.add(-2*arr[0], arr[0]*arr[0]);
    for(int i = 1; i < N; i++){
        long long val = cht.get(arr[i])+arr[i]*arr[i]+C;
        if(i == N-1) cout << val << '\n';
        else cht.add(-2*arr[i], val+arr[i]*arr[i]);
    }
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
