/********************
=====================
**Code By-hardikdua**
=====================
*********************/
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vec vector
#define psb push_back
#define fst first
#define scd second
#define ins insert
#define ques 998244353
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
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
// seive geeksforgeeks
#define MOD 998244353
const int mxn = 1e7, MAXN = 2e7 + 1;
int len, spf[MAXN];
void sieve_gfg()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
ll ans[11]={0};
ll find()
{
    ll status=1,i;
    for(i=0;i<10;i++)
        status*=ans[i];
    return status;
}
// yahan pe logic aaega
void cf_solve()
{
    int n;
    cin>>n;
    set<pair<int,int> > sp;
    sp.insert(make_pair(0,2));
    sp.insert(make_pair(1,2));
    sp.insert(make_pair(0,3));
    sp.insert(make_pair(0,4));
    sp.insert(make_pair(1,4));
    sp.insert(make_pair(2,4));
    sp.insert(make_pair(2,3));
    int a,b;
    a=2,b=0;
    for(int i=1;i<=n;i++)
    {
        sp.insert(make_pair(a,b));
        sp.insert(make_pair(a+1,b));
        sp.insert(make_pair(a,b+1));
        sp.insert(make_pair(a,b+2));
        sp.insert(make_pair(a+2,b));
        sp.insert(make_pair(a+2,b+1));
        sp.insert(make_pair(a+1,b+2));
        sp.insert(make_pair(a+2,b+2));
        a=a+2;
        b=b+2;
    }
    cout<<sp.size()<<'\n';
    for(auto it=sp.begin();it!=sp.end();it++)
        cout<<it->first<<" "<<it->second<<'\n';
}
// gaadi tera main() chalaega
int main()
{
    jaldi_chal();
    cf_solve();
    return 0;
}
