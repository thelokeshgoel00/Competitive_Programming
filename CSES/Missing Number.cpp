#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	long long  n;
	cin >> n;
	ll a = n * (n + 1) / 2;
	ll sum = 0;
	ll b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> b;
		sum += b;
	}
	cout << a - sum;

}
