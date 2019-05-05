#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

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

int N, ret [1010], numInv [1010], tree [1010];

void add(int pos, int x){
    while(pos < 1010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 1; i <= N; i++) add(i, 1);
    for(int i = 2; i <= N; i++){
        cout << "? 1 " << i << endl;
        cin >> numInv[i];
    }
    for(int i = N; i > 0; i--){
        int produced = numInv[i]-numInv[i-1];
        int targ = i-produced, lo = 0, hi = N, temp;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(query(mid) < targ){ lo = mid+1; temp = mid; }
            else hi = mid-1;
        }
        temp++; ret[i] = temp; add(ret[i], -1);
        //cout << i << ' ' << ret[i] << ' ' << targ << endl;
    }
    cout << "!";
    for(int i = 1; i <= N; i++) cout << ' ' << ret[i];
    cout << endl;
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
