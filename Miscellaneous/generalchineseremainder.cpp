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

int kase;
long long a [2], n [2];
pair<long long, long long> ret;

pair<pair<long long, long long>, long long> extendedGCD(long long a, long long b){
    if(b == 0) return mp(mp(1, 0), a);
    pair<pair<long long, long long>, long long> temp = extendedGCD(b, a%b);
    return mp(mp(temp.f.s, temp.f.f-a/b*temp.f.s), temp.s);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        for(int i = 0; i < 2; i++) cin >> a[i] >> n[i];
        ret = mp(a[0], n[0]);
        for(int i = 1; i < 2; i++){
            pair<pair<long long, long long>, long long> nexty = extendedGCD(ret.s, n[i]);
            long long x = nexty.f.f, d = nexty.s;
            if((a[i]-ret.f)%d != 0){
                ret.f = -1;
                break;
            }
            ret.f += (x*(a[i]-ret.f)/d)%(n[i]/d)*ret.s; ret.s = ret.s*(n[i]/d);
            ret.f %= ret.s; if(ret.f < 0) ret.f += ret.s;
        }
        if(ret.f != -1) cout << ret.f << ' ' << ret.s << '\n';
        else cout << "no solution\n";
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
