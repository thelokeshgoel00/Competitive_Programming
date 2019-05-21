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

long long MUDA = 1000003, powa [15][15], queries [15], inverse [1000003], arr [15][15], coef [15];

long long fastPow(long long base, long long expo){
    if(expo == 0) return 1;
    long long halfy = fastPow(base, expo/2);
    halfy *= halfy; halfy %= MUDA;
    if(expo%2){ halfy *= base; halfy %= MUDA; }
    return halfy;
}

int nextVar(int i, int curVar) {
    for(int j = curVar; j < 12; j++)
        for(int k = i; k < 12; k++)
            if(arr[k][j] > 0)
                return j;
    return 12;
}

int maxRow(int row, int var){
    int res = row;
    for(int i = row+1; i < 12; i++)
        if(arr[i][var] > arr[res][var])
            res = i;
    return res;
}

void reduce(int i, int j, int curVar) {
    long long fac = arr[j][curVar]*inverse[arr[i][curVar]];
    for(int k = curVar; k <= 12; k++){
        arr[j][k] -= (fac*arr[i][k])%MUDA;
        arr[j][k] += MUDA; arr[j][k] %= MUDA;
    }
}

bool checkIt(){
    int curVar = 0;
    for(int i = 0; i < 11; i++){
        curVar = nextVar(i, curVar);
        if(curVar == 12) break;
        swap(arr[i], arr[maxRow(i, curVar)]);
        for(int j = i+1; j < 12; j++) reduce(i, j, curVar);
        curVar++;
    }
    for(int i = 11; i > -1; i--){
        bool zero = true; int sub = -1;
        for(int j = 0; j < 12; j++)
            if(arr[i][j] > 0){
                zero = false; sub = j;
                coef[i] = (arr[i][12]*inverse[arr[i][j]])%MUDA;
                break;
            }
        if(zero && arr[i][12] > 0) return false;
        if(zero){ coef[i] = 0; continue; }
        for(int j = 0; j < i; j++){
            arr[j][12] -= (coef[i]*arr[j][sub])%MUDA;
            arr[j][12] += MUDA; arr[j][12] %= MUDA;
        }
    }
    return true;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    for(int i = 1; i < MUDA; i++) inverse[i] = fastPow(i, MUDA-2);
    for(int i = 0; i < 12; i++){
        powa[i][0] = 1; arr[i][0] = powa[i][0];
        for(int j = 1; j < 12; j++){
            powa[i][j] = (powa[i][j-1]*i)%MUDA;
            arr[i][j] = powa[i][j];
        }
        cout << "? " << i << endl;
        cin >> queries[i]; arr[i][12] = queries[i];
    }
    assert(checkIt());
    //for(int i = 0; i < 12; i++) cout << "HI" << coef[i] << endl;
    for(long long a = 0; a < MUDA; a++){
        long long sum = 0;
        for(int i = 0; i < 12; i++){ sum += coef[i]*fastPow(a, i); sum %= MUDA; }
        if(sum == 0){
            cout << "! " << a << endl;
            return 0;
        }
    }
    cout << "! -1" << endl;
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
