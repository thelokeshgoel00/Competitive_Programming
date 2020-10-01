#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define fi first
#define s second
#define mem(x, vertexal) memset(x, vertexal, sizeof(x))
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define endl "\n"
#define mp make_pair
#define print_arr(a,n) for(long long int i = 0; i < n; i++) cout << a[i] << " ";
#define print_vertexec(vertex) for(long long int i = 0; i < vertex.size(); i++) cout << vertex[i] << " ";
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
using namespace std;
int main()
{
  fast;
  // test cases
  ll t;
  cin>>t;
  while(t--)
  {
    // input 
    ll n;
    cin>>n;
    ll a[n];
    // array n 
    // loop
    for(ll i=0;i<n;i++)
    {
      cin>>a[i];
    }
    // prefix array 
    ll pref[n+1]={0};
    ll count[5*n+1]={0};
    pref[0]=a[0];
    // loop
    for(ll i=1;i<n;i++)
    {
      pref[i]=pref[i-1]+a[i];
      if(pref[i]<=n)
      {
        count[pref[i]]++;
      }
    }
    
    for(ll i=1;i<n;i++)
    {
      for(ll j=i+1;j<n;j++)
      {
        // sum 
        ll sum= pref[j]-pref[i-1];
        if(sum<=n)
          count[sum]++;
      }
    }
    ll ans=0;
      
    // for(ll i=0;i<n;i++)
    // {
    //   if(count[a[i]]!=0)
    //   {
    //     ans++;
    //   }
    // }  
    for(ll i=0;i<n;i++)
    {
      if(count[a[i]]!=0)
      {
        // increment
        ans++;
      }
    }
    // ouput 
    cout<<ans<<endl;
  }
  return 0;
}

