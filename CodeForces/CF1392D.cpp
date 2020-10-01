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
	int test,n,i,j,k;
	cin>>test;
	while(test--)
	{
		string str;
		// input string consisiting of L and R.
		cin>>n>>str;
		
		int ans=0;
		i=-1;
		for(j=0;j<n-1;j++)
		{
			if(str[j]!=str[j+1])
			{
				i=j;
				break;
			}
		}
		if(i==-1)// if string consist of all L's or all R's.
		{
			ans=(n+2)/3;
		}
		else
		{
			int count=0;
			j=(i+1)%n;;
			int save=j;
			do
			{
				if(str[j]!=str[(j-1+n)%n])
				{
					ans+=(count/3);
					count=1;
				}
				else
				{
					count++;
				}
				j=(j+1)%n;
			}
			while(j!=save);
			
			ans+=(count/3);
		}


		cout<<ans<<endl;
		
	}
	return 0;
}