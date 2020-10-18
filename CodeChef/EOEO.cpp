#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
// #define ff first
// #define ss second
// #define pb push_back
// #define mp make_pair
// #define sz(a) (ll)(a.size())
// #define loop(t) int t;cin>>t;while(t--)

ll powof2(ll x){
    ll p = 0;
    while(x%2==0){
        x/=2;
        p++;
    }
    return p;
}

ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x,p;
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>x;
        // p = __builtin_ctzll(x)+1;
        p = powof2(x)+1;
        cout<< x/ power(2,p) <<"\n";
    }
    return 0;
}