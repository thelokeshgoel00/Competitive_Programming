/*
ID: vamaddu1
LANG: C++11
TASK: discgf
*/

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

struct Circle{
    double x, y, r;
    Circle(){ x = y = r = 0; }
};

int N;
double H, lo, hi, ret;
Circle arr [1010];
bool visited [1010];

int main(){
    freopen("discgf.in", "r", stdin); freopen("discgf.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> H; lo = 0; hi = H/2;
    for(int i = 0; i < N; i++) cin >> arr[i].x >> arr[i].y >> arr[i].r;
    while(lo+epsilon*1000 < hi){
        double mid = (lo+hi)/2; fill(visited, visited+N, false);
        bool ok = true; queue<int> q;
        for(int i = 0; i < N; i++)
            if(arr[i].y <= 2*mid+arr[i].r){
                visited[i] = true;
                q.push(i);
            }
        while(q.size() > 0){
            int now = q.front(); q.pop();
            if(arr[now].y+2*mid+arr[now].r >= H){
                ok = false;
                break;
            }
            for(int i = 0; i < N; i++)
                if(!visited[i] && sqrt(pow(arr[now].x-arr[i].x, 2)+pow(arr[now].y-arr[i].y, 2)) <=
                   arr[now].r+arr[i].r+2*mid){
                    visited[i] = true;
                    q.push(i);
                }
        }
        if(ok){ ret = mid; lo = mid; }
        else hi = mid;
        //cout << lo << ' ' << hi << endl;
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
