#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
	int n,av,a[101],sum=0;
	cin >> n;
	loop(i,0,n)
		cin >> a[i],sum+=a[i];
	sort(a,a+n);
	av=round(float(sum)/n);
	if(av==5)
		cout << 0 << "\n";
	else
	{
		int cr=0;
		loop(i,0,n)
		{
			sum+=(5-a[i]);
			av=round(float(sum)/n),cr++;
			if(av==5){
				cout << cr << "\n";
				exit(0);
			}
		}
	}
	return 0;
}
