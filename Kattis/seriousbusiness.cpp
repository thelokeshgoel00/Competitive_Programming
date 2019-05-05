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
#define MOD 998244353

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

string a, b, s;
long long dp [100010][2][2][2][2][2][2], ret; //idx, evenpre, oddpre, curpre, scarypar, match, zero

void resetIt(){
    for(int i = 0; i < 100010; i++)
        for(int mask = 0; mask < 64; mask++)
            dp[i][(mask&32) > 0][(mask&16) > 0][(mask&8) > 0][(mask&4) > 0][(mask&2) > 0][(mask&1) > 0] = -1;
}

long long solveIt(int idx, int evenpre, int oddpre, int curpre, int scarypar, int match, int zero){
    if(dp[idx][evenpre][oddpre][curpre][scarypar][match][zero] != -1) return dp[idx][evenpre][oddpre][curpre][scarypar][match][zero];
    if(idx == s.length()) return dp[idx][evenpre][oddpre][curpre][scarypar][match][zero] = scarypar;
    dp[idx][evenpre][oddpre][curpre][scarypar][match][zero] = 0;
    for(int dig = 0; dig < 10; dig++){
        if(match && dig > s[idx]-'0') break;
        if(dig == 0 && zero){
            int nmatch = match&(dig == s[idx]-'0');
            dp[idx][evenpre][oddpre][curpre][scarypar][match][zero] += solveIt(idx+1, evenpre, oddpre, curpre, scarypar, nmatch, 1);
            dp[idx][evenpre][oddpre][curpre][scarypar][match][zero] %= MOD;
        }
        else{
            int ncurpre = (curpre+dig)%2, nmatch = match&(dig == s[idx]-'0');
            int nscarypar = scarypar;
            if(ncurpre%2) nscarypar += oddpre;
            else nscarypar += evenpre;
            nscarypar %= 2;
            int nevenpre = (evenpre+(ncurpre%2 == 0))%2, noddpre = (oddpre+(ncurpre%2 == 1))%2;
            dp[idx][evenpre][oddpre][curpre][scarypar][match][zero] += solveIt(idx+1, nevenpre, noddpre, ncurpre, nscarypar, nmatch, 0);
            dp[idx][evenpre][oddpre][curpre][scarypar][match][zero] %= MOD;
        }
    }
    return dp[idx][evenpre][oddpre][curpre][scarypar][match][zero];
}

bool isLucky(){
    int evenpre = 1, oddpre = 0, curpre = 0, scarypar = 0;
    for(int i = 0; i < s.length(); i++){
        int dig = s[i]-'0';
        int ncurpre = (curpre+dig)%2;
        int nscarypar = scarypar;
        if(ncurpre%2) nscarypar += oddpre;
        else nscarypar += evenpre;
        nscarypar %= 2;
        int nevenpre = (evenpre+(ncurpre%2 == 0))%2, noddpre = (oddpre+(ncurpre%2 == 1))%2;
        evenpre = nevenpre; oddpre = noddpre; curpre = ncurpre; scarypar = nscarypar;
    }
    return scarypar;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> a >> b;
    s = b; resetIt(); ret = solveIt(0, 1, 0, 0, 0, 1, 1);
    s = a; resetIt(); ret = (ret-solveIt(0, 1, 0, 0, 0, 1, 1)+MOD)%MOD;
    ret = (ret+isLucky())%MOD;
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
