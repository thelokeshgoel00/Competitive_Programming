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

int a, b, c, d, prime [10000010], sign [10000010];

long long solveIt(int x, int y){
    long long ret = 0;
    for(int i = 1; i <= min(x, y); i++) ret += (long long)(x/i)*(long long)(y/i)*sign[i];
    return ret;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> a >> b >> c >> d; sign[1] = 1;
    for(int i = 2; i < 10000010; i++){
        if(!prime[i]){
            prime[i] = i;
            if(i < 5000)
                for(int j = i*i; j < 10000010; j += i)
                    if(!prime[j])
                        prime[j] = i;
        }
        int temp = i, s = 1;
        while(temp > 1){
            int divi = prime[temp];
            temp /= divi;
            if(prime[temp] == divi){
                s = 0;
                break;
            }
            s *= -1;
        }
        sign[i] = s;
    }
    cout << solveIt(b, d)-solveIt(a-1, d)-solveIt(b, c-1)+solveIt(a-1, c-1) << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
