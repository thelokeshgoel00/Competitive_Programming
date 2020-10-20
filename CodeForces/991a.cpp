#include <bits/stdc++.h>
using namespace std;
int main()
{
  int x,y,b,n,a,c,d;
	cin>>x>>y>>b>>n;
	//n=a+b+c+d
	a=x-b;
	c=y-b;
	d=n-a-b-c;
	if(a<0||c<0||d<1)
	{
		cout<<"-1";
	}
	else
	{
		cout<<d;
	}
	return 0;
}
