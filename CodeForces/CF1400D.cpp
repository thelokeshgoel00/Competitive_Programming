#include<bits/stdc++.h>
using namespace std;
#define ll int long long
#define mp make_pair
//#define for(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define N 1000000007
#define pq priority queue
#define pb push_back
#define pf push_front
#define mt make_tuple
#define prec(a) fixed<<setprecision(9)<<a
#define endl "\n"
#define fast_set s.max_load_factor(0.25);s.reserve(500);
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
const long double PI = (long double)(3.1415926535897932384626433832795);

// prefix count array
int  co[3001][3001];
int main() 
{
	fast;
	ll test,i,j,k,l,n;
	cin>>test;
	while(test--)
	{
		cin>>n;
		ll arr[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		ll ans=0;
		
		// prefix count array initialised to zero.
		memset(co,0,sizeof(co));

		// constructing prefix count array.
		for(i=0;i<n;i++)
		{
			for(j=0;j<=3000;j++)
			{
				if(j!=arr[i])
				co[i+1][j]=co[i][j];
				else
					co[i+1][j]=co[i][j]+1;
			}
		}
		for(j=0;j<n;j++)
		{
			
			for(k=n-1;k>j;k--)
			{
				ans+=((co[j][arr[k]]-co[0][arr[k]])*(co[n][arr[j]]-co[k+1][arr[j]]));		
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}










