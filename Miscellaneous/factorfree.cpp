#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int N, prevy [1000010], nexty [1000010], lastSeen [10000010], parents [1000010];
bool isPrime [10000010];
vector<int> primes;

bool solveIt(int li, int ri, int par){
    if(li >= ri){
        if(li == ri) parents[li] = par;
        return true;
    }
    for(int i = li, j = ri; i <= j; i++, j--){
        if(prevy[i] < li && nexty[i] > ri){
            if(solveIt(li, i-1, i) && solveIt(i+1, ri, i)){
                parents[i] = par;
                return true;
            }
            return false;
        }
        else if(prevy[j] < li && nexty[j] > ri){
            if(solveIt(li, j-1, j) && solveIt(j+1, ri, j)){
                parents[j] = par;
                return true;
            }
            return false;
        }
    }
    return false;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(9);
    fill(isPrime, isPrime+10000010, true);
    for(int i = 2; i < 10000010; i++){
        if(!isPrime[i]) continue;
        primes.pb(i);
        for(int j = 2*i; j < 10000010; j += i) isPrime[j] = false;
    }
    while(cin >> N){
        for(int f : primes) lastSeen[f] = -1;
        for(int i = 1; i <= N; i++){
            prevy[i] = 0; nexty[i] = N+1;
            int x; cin >> x;
            for(int f : primes){
                if(f > sqrt(x)) break;
                if(x%f != 0) continue;
                while(x%f == 0) x /= f;
                if(lastSeen[f] > -1){
                    nexty[lastSeen[f]] = min(nexty[lastSeen[f]], i);
                    prevy[i] = max(prevy[i], lastSeen[f]);
                }
                lastSeen[f] = i;
            }
            if(!isPrime[x] || x == 1) continue;
            int f = x;
            if(lastSeen[f] > -1){
                nexty[lastSeen[f]] = min(nexty[lastSeen[f]], i);
                prevy[i] = max(prevy[i], lastSeen[f]);
            }
            lastSeen[f] = i;
        }
        if(!solveIt(1, N, 0)) cout << "impossible\n";
        else{
            for(int i = 1; i <= N-1; i++) cout << parents[i] << ' ';
            cout << parents[N] << '\n';
        }
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
