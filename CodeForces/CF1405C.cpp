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
		cin>>n>>k;
		string str;
		cin>>str;
		string ans=""; // default string with all question marks.
		for(i=0;i<k;i++)
		{
			ans+="?";
		}
		bool flag=true;
		int zero=0,one=0,que=0; // count of number of zeroes, ones and question marks in string.
		for(i=0;i<k;i++)
		{
			if(str[i]=='0')
			{
				zero++;
			}
			else if(str[i]=='1')
			{
				one++;
			}
			else
			{
				que++;
			}
		}
		
		int req=k/2;
		if(zero>req||one>req)
		{
			flag=false;
		}
		for(i=k;i<n;i++)
		{
			// including current char.
			if(str[i]=='0')
			{
				zero++;
			}
			else if(str[i]=='1')
			{
				one++;
			}
			else
			{
				que++;
			}

			// excluding last char.
			if(str[i-k]=='0')
			{
				zero--;
			}
			else if(str[i-k]=='1')
			{
				one--;
			}
			else
			{
				que--;
			}
			if(zero>req||one>req)
			{
				flag=false;
			}
		}
		for(i=0;i<n;i++)
		{
			if(str[i]!='?')
			{
				if(ans[i%k]=='?')
				{
					ans[i%k]=str[i];
				}
				else
				{
					if(ans[i%k]==str[i])
					{

					}
					else
					{
						flag=false;
					}
				}
			}
		}
		zero=0;
		one=0;
		for(i=0;i<k;i++)
		{
			if(ans[i]=='0')
			{
				zero++;
			}
			else if(ans[i]=='1')
			{
				one++;
			}
		}
		if(zero>req||one>req)
		{
			flag=false;
		}
		if(flag)
		{
			cy; // output YES
		}
		else
		{
			cn; // output NO.
		}
	}
	return 0;
}


 