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
#define epsilon 1e-9
#define INF 5e18
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int N, arr [200010], sparse [200010][19], logs [200010], lefty [200010], righty [200010], pos [200010], ret = 0;

void makeSparseTable(){
    for(int i = 0; i < N; i++) sparse[i][0] = arr[i];
    for(int j = 1; j <= 18; j++)
        for(int i = 0; i+(1<<j) <= N; i++)
            sparse[i][j] = max(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
    for(int i = 2; i <= N; i++) logs[i] = logs[i/2]+1;
}

int maxQuery(int L, int R){
    int j = logs[R-L+1];
    return max(sparse[L][j], sparse[R-(1<<j)+1][j]);
}

void findLeft(int x){
    int lo = 0, hi = x-1; lefty[x] = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(maxQuery(mid, x) > arr[x]){ lefty[x] = mid; lo = mid+1;}
        else hi = mid-1;
    }
}

void findRight(int x){
    int lo = x+1, hi = N-1; righty[x] = N;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(maxQuery(x, mid) > arr[x]){ righty[x] = mid; hi = mid-1; }
        else lo = mid+1;
    }
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    makeSparseTable();
    for(int i = 0; i < N; i++){
        findLeft(i);
        findRight(i);
        //cout << i << ' ' << lefty[i] << ' ' << righty[i] << endl;
    }
    for(int i = 0; i < N; i++){
        if(i-lefty[i] < righty[i]-i){
            for(int j = lefty[i]+1; j < i; j++)
                ret += pos[arr[i]-arr[j]] > i && pos[arr[i]-arr[j]] < righty[i];
        }
        else{
            for(int j = i+1; j < righty[i]; j++)
                ret += pos[arr[i]-arr[j]] < i && pos[arr[i]-arr[j]] > lefty[i];
        }
    }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
