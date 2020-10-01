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
  ll t;
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    ll a[n+1];
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
      cin>>a[i];
      sum+=a[i];
    }
    ll alice=a[0],bob=0,turns=1;
    ll now=a[0];
    ll chance=1;
    ll last=a[0];
    ll start=1;
    while(now!=sum)
    {
      ll p=0;
      if(chance==1)//BOB
      {
        p=0;
        while(n>start && p<=last)
        {
          n--;
          p+=a[n];
        }
        last=p;
        bob+=p;chance=0;
      }
      else//ALICE
      {
        p=0;
        while(start<n && p<=last)
        {
          p+=a[start];
          start++;
        }
        last=p;
        alice+=p;
        chance=1;

      }
      now+=p;
      turns++;
    }
    cout<<turns<<" "<<alice<<" "<<bob<<endl;

  }
  return 0;
}

