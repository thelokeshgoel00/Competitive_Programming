#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long int lli;
using namespace std;

bool check(lli x,lli n)
{
		lli copy=n;
		lli sum=0;
		while(copy>0)
		{
			lli temp=min(copy,x);
			sum+=temp;
			copy-=temp;
			copy-=copy/10;
		}
		return(sum*2>=n);
}

lli bs(lli n)
{
	lli r=n,l=1;
	lli ans=r;
	while(r>=l)
	{
		lli mid= l+ (r-l)/2;
		if(check(mid,n))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}

int main()
{
	lli n;
	cin>>n;
	cout<<bs(n)<<"\n";
	return 0;
}
