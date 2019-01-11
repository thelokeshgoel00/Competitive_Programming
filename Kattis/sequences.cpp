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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

string s;
long long ret = 0ll, pow2mod [500010], count1 = 0ll, totalq = 0ll, runningq = 0ll;

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> s; pow2mod[0] = 1ll;
    for(int i = 0; i < s.length(); i++){
        totalq += s[i] == '?';
        pow2mod[i+1] = (pow2mod[i]*2ll)%MOD;
    }
    if(totalq > 1ll) ret = (((totalq*(totalq-1ll)/2ll)%MOD)*pow2mod[totalq-2ll])%MOD; 
    //calculates ?-? inversions using formula f(x+1) = x*pow(2, x-1)+2*f(x)
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') count1++;
        else if(s[i] == '0'){
            ret = (ret+count1*pow2mod[totalq])%MOD; 
            //calculates 1-0 inversions
            if(runningq > 0ll) ret = (ret+(((runningq*pow2mod[runningq-1ll])%MOD)*pow2mod[totalq-runningq])%MOD)%MOD; 
            //calculates ?-0 inversions
        }
        else{
            ret = (ret+count1*pow2mod[totalq-1ll])%MOD; 
            //calculates 1-? inversions
            runningq++;
        }
    }
    cout << ret << '\n';
    return 0;
}
