#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k1=0, k2=0, d, n, x, i;
		cin>>n;
		x=n;
		while(x)
		{
			d=x%10;
			if(d!=0)
				k1++;
			x/=10;
			k2++;
		}
		cout<<k1<<endl;
		x=n;
		for(i=0; i<k2; i++)
		{
			d=x%10;
			if(d)
			{
				cout<<d*pow(10,i)<<" ";
			}
			x/=10;
		}
		cout<<endl;
	}
	return 0;
}
