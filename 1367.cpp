#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int i, len, j=1;
	char b[100], a[100];
	cin>>b;
	len=strlen(b);
	if(len<=2)
	{
		cout<<b<<endl;
		return;	
	}
	a[0]=b[0];
	for(i=1; i<len; i+=1)
	{
		if(i%2!=0)
		{
			a[j++]=b[i];
		}
	}
	a[j]='\0';
	cout<<a<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
