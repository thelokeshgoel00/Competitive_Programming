#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define endl '\n'
#define M 1000000007
//#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define omset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(NULL);ios_base::sync_with_stdio(false);cout.tie(NULL);

using namespace std;
//using namespace __gnu_pbds;

const int N = 100005;
ll fact[N]; // = {0}

void preComputeFact() {
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2 ; i<N ; i++) {
        ll num = (ll)((fact[i-1]%M)*(i%M));
        fact[i] = (num)%M;
    }
}

int power(int x, int n, int d) {
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    ll res = 1;
    x = x % d;
    while (n > 0) {
        if (n & 1) {
            res = (ll)(res*(ll)x)%(ll)d;
        }
        n = n >> 1;
        x = (ll)((ll)x*(ll)x)%(ll)d;
    }
    if (res < 0) {
        return (int)(res + d);
    }
    return (int)res;
}

ll nCr(ll n , ll r) {
    ll nFact = fact[n];
    ll rFact = fact[r];
    ll nrFact = fact[n-r];
    ll f = (nFact%M)*(power(rFact , M-2 , M)%M);
    f = f%M;
    ll s = (f%M)*(power(nrFact , M-2 , M)%M);
    s = s%M;
    return s%M;
}

int main() {

    fastio
    
    ll t;
    cin>>t;

    preComputeFact();

    while(t--) {

        ll n;
        cin>>n;
        string a , b;
        cin>>a>>b;

        ll oneA = 0 , oneB = 0;
        
        for(ll i=0 ; i<n ; i++) {
            if(a[i] == '1')
                oneA++;
        }
        for(ll i=0 ; i<n ; i++) {
            if(b[i] == '1')
                oneB++;
        }
       
        ll smaller , larger;
        if(oneA < oneB) {
            smaller = oneA;
            larger = oneB;
        }
        else {
            smaller = oneB;
            larger = oneA;
        }
        ll empty = n - larger;
        if(oneA == 0 && oneB == 0) {
            cout<<1<<endl;
            continue;
        }
        if(oneA == n && oneB == n) {
            cout<<1<<endl;
            continue;
        }
        ll sum = 0;
        for(ll i=abs(oneA - oneB) ; empty >= 0 && smaller >= 0 && i<=n ; i += 2) {
            sum = (sum%M + nCr(n , i)%M)%M;
            smaller--;
            empty--;
        }

        cout<<sum<<endl;

    }
    return 0;
}
