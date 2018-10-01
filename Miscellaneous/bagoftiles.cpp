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

int kase, M, N, T, arr [35], combo [35][35], ret;
map<pair<int, int>, int> freq;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> kase; combo[0][0] = 1;
    for(int i = 1; i < 35; i++){
        combo[i][0] = 1;
        for(int j = 1; j < 35; j++) combo[i][j] = combo[i-1][j]+combo[i-1][j-1];
    }
    for(int kk = 1; kk <= kase; kk++){
        cin >> M; freq = map<pair<int, int>, int>(); ret = 0;
        for(int i = 0; i < M; i++) cin >> arr[i];
        cin >> N >> T;
        for(int mask = 0; mask < (1<<((M+1)/2)); mask++){
            int sum = 0, num = 0;
            for(int i = 0; i < (M+1)/2; i++)
                if(mask&(1<<i)){
                    sum += arr[i];
                    num++;
                }
            if(sum <= T && num >= N-(M-(M+1)/2) && num <= N) freq[mp(sum, num)]++;
        }
        for(int mask = 0; mask < (1<<(M-(M+1)/2)); mask++){
            int sum = 0, num = 0;
            for(int i = 0; i < M-(M+1)/2; i++)
                if(mask&(1<<i)){
                    sum += arr[i+(M+1)/2];
                    num++;
                }
            if(freq.find(mp(T-sum, N-num)) != freq.end()) ret += freq[mp(T-sum, N-num)];
        }
        cout << "Game " << kk << " -- " << ret << " : " << combo[M][N]-ret << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
