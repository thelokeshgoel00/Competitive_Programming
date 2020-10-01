/********************
=====================
**Code By-hardikdua**
=====================
*********************/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define jaldi_chal() ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
ll mod=1000000007;
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
        if (prime[p])
            cout << p << " ";
}
ll fact_mod(ll x)
{
    ll res=x;
    while(x--)
    {
        if(x==0)
            break;
        res=(res*x)%mod;
    }
    return res;
}
// jyada bada number ho toh
ll pw_mod(ll a,ll b)
{
    ll res=1;
    while(b!=0)
    {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}
ll ans1(ll n)
{
    ll a=1;
    while(a<=(n>>1))
        a<<=1;
    if(a>n)
        a>>=1;
    return a;
}
int pos[8000100]={0};
// KMP gfg
void kmp(string s)
{
    int n=(int)s.length(),i;
    for(i=0;i<n+1;i++)
        pos[i]=0;
    for(i=1;i<n;i++)
    {
        int j=pos[i-1];
        while(j>0&&s[i]!=s[j])
            j=pos[j-1];
        if (s[i]==s[j])
            j++;
        pos[i]=j;
    }
}
// function from geeksforgeeks
bool subsum(vector<ll>v, ll sum)
{
    ll n=v.size();
    bool subset[n + 1][sum + 1];
 
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < v[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= v[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - v[i - 1]];
        }
    }
    return subset[n][sum];
}
// yahan pe logic aaega
ll mod_lo = 1e9+7;
void cf_solve()
{
    ll t;
    cin>>t;
    for(ll tc=1;tc<=t;tc+=1)
    {
        //ll t;
        //cin>>t;
        //while(t--)
        //{
            ll n;
            cin >> n;
            ll a[2 * n + 1];
            for (ll i = 0; i < 2 * n; i++)
                cin >> a[i];
            ll c = 1, x = a[0], i = 1;
            vector<ll> vc;
            while (i < 2 * n)
            {
                while (i < 2 * n && a[i] < x)
                {
                    i++;
                    c++;
                }
                if (i < 2 * n)
                {
                    vc.push_back(c);
                    c = 1;
                    x = a[i];
                    i += 1;
                }
            }
            vc.push_back(c);
            if (subsum(vc, n))
                cout << "YES\n";
            else
                cout << "NO\n";
    }
}
// gaadi tera main() chalaega
int main()
{
    jaldi_chal();
    cf_solve();
    return 0;
}
