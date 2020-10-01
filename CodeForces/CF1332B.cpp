/******************************************
* AUTHOR : KARTIK GUPTA *
* NICK : spectre_1502 *
* INSTITUTION : NIT KURUKSHETRA *
******************************************/
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ld long double
#define fi first
#define mt make_tuple
#define s second
#define mem(x, vertexal) memset(x, vertexal, sizeof(x))
#define precision cout << setprecision(15);
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define time_bata cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define vertexec std::vector<int > vertex;
#define eps 1e-7
#define endl "\n"
#define mp make_pair
#define p_q priority queue
#define ct_set(n) __builtin_popcount(n);
#define print_arr(a,n) for(long long int i = 0; i < n; i++) cout << a[i] << " ";
#define print_vertexec(vertex) for(long long int i = 0; i < vertex.size(); i++) cout << vertex[i] << " ";
#define fm(it,m) for(it = m.begin(); it != m.end(); it++)
#define cn cout<<"NO"<<endl;
#define cy cout<<"YES"<<endl;
#define CHARS 26 
 
#define dbg(x) cout<<"#x"<<" = "<<x<<endl;
#define dbg2(x,y) cout<<"#x"<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout<<"#x"<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl;
#define dbg4(x,y,z,q) cout<<"#x"<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl;
 
 
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
 
#define rep(i,a,b) for(int i=a;i<=b;i++)
 
using namespace std;
     
bool cmp(pair<ll,ll>a,pair<ll,ll>b){
    return a.fi<b.fi;
}
 
 
bool check(int a){
    int sum=0;
    while(a>0){
        sum+=(a%10);
        a/=10;
    }
    if(sum==10) return true;
    return false;
}
// seivertexe use karloo..................................
bool prime[10005];
void seivertexe()
{
    mem(prime, 1);
    prime[0] = 0;
    prime[1] = 0;
    for(ll i = 2; i <= 10000; i++)
    {
        if(prime[i] == 1)
        {
            for(ll j = i * i; j <= 10000; j += i)
            prime[j] = 0;
        }
    }   
}
// kar liya .............................................
 
template <typename T>
std::string NumberToString ( T Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}
 
 
// prime check karlooooo.....................................
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
/// kar liya ................................................
 
 
ll power(ll x,ll y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return (power(x, y / 2)%mod * power(x, y / 2)%mod)%mod; 
    else
        return (x%mod * (power(x, y / 2)%mod* power(x, y / 2)%mod)%mod)%mod; 
} 
 
 
ll factorial1(ll n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: (n%mod * factorial1(n - 1)%mod)%mod;  
} 
ll fact(ll n) 
{ 
    ll res = 1; 
    for (int i = 2; i <= n; i++) 
        res = (res * i)%mod; 
    return res%mod; 
} 

ll nCr(ll n, ll r) 
{ 
    return fact(n)%mod / ((fact(r)%mod * fact(n - r)%mod))%mod; 
} 
  

int main()
{
    fast;
    // test cases
    ll t;
    cin>>t;
    while(t--)
    {
        //code here

      // input here
      
        ll n;
        cin>>n;
        ll a[n+1];
        // map of vectors
        map< int ,vector< int > >v1;
        ll c2[n+1];
        ll mark[n+1]={0};
        ll last_color=-1;
        f(i,n)
        {
           cin>>a[i];
           set< int > prime;
           ll y=a[i];
            while(y%2==0)
            {
                y/=2;
                prime.insert(2);
            }
            for(int j=3;j*j<=y;j++)
            {
                while(y%j==0)
                {
                    prime.insert(j);
                    y/=j;
                }
            } 
            // geeks for geeks
            if(y>2)
            {
                prime.insert(y);
            }

            for(auto it:prime)
            {
                v1[it].pb(i);
            }

        }

        // loop to calculate freq
        ll count=1;
        for(auto it:v1)
        {
            int flag=0;
            for(auto it1: it.s)
            {
                if(!mark[it1])
                {


                mark[it1]=1;
                c2[it1]=count;
                flag=1;
            }
            }
            if(flag==1)
            {
             count++;   
            }
        }
        // count-1
        // cout<<x<<endl;
        // ouput
        cout<<count-1<<endl;
        f(i,n)
        {
            cout<<c2[i]<<" ";
        }
        cout<<endl;



    }
    return 0;
    





    
}
