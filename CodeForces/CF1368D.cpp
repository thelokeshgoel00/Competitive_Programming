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

int main() 
{
	fast;
	ll n,i,j,k;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i]; // taking input array elements.
	}
	ll bits1[n][21];
	// bits array to store all the numbers in bits form.
	memset(bits1,0,sizeof(bits1));

	ll count[21]={0}; // maintain count of each bit being set in different numbers.
	for(i=0;i<n;i++)
	{
		for(j=0;j<=20;j++) // converting into binary form and incrementing corresponding index in count.
		{
			bits1[i][j]=arr[i]%2;
			if(bits1[i][j]==1){
				count[j]++;
			}
			arr[i]/=2;
		}
	}
	ll mini=LLONG_MAX; // intialising to infinite.
	for(i=0;i<=20;i++)
	{
		if(count[i]>0) // represents that bit being set in any number.
		mini=min(mini,count[i]);
	}
	ll sum=0;
	while(mini!=LLONG_MAX)
	{
		ll ans=0;
		for(i=0;i<=20;i++) // traversing each bit.
		{
			if(count[i]>=mini)
			{
				count[i]-=mini;
				ans+=pow(2,i);
			}
		}
		sum+=(ans*ans*mini);
		mini=LLONG_MAX;
		
		for(i=0;i<=20;i++)
		{
			if(count[i]>0)
			mini=min(mini,count[i]);
		}
	}
	cout<<sum<<endl;
	return 0;
}







 