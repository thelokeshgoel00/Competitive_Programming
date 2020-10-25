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
  //code here
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,k;
    cin>>n>>k;
    ll a[n];
    ll f=0;
    for(ll i=0;i<n;i++)
    {
      cin>>a[i];
      if(a[i]==k)
      {
        f=1;
      }

    }
    if(f)
    { 
      f=0;
      if(n==1)
      {
        cy;
        continue;
      }
      for(ll i=0;i<n;i++)
      {
        if((i>0 && a[i]>=k && a[i-1]>=a[i])||((i>1 && a[i]>=k && a[i-2]>=a[i]))||(i<n-1 && a[i]>=k && a[i+1]>=a[i])||(i<n-2 && a[i]>=k && a[i+2]>=a[i])){
          f=1;
          break;
        }
      }
      if(f)
      {
        cy;
      }
      else
      {
        cn;
      }
    }
    else
    {
      cn;
    }
  }
  return 0;
}

