#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
int main()
{
	int t;
	long long int x1, y1, x2, y2, c;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2;
		cout<<(x2-x1)*(y2-y1)+1<<'\n';
	}
	return 0;
}
