#include<bits/stdc++.h>
using namespace std;
#define ll long long
int isalpha(int *str, int n)
{
	int sum = 0;
	for(int i = 0; i < n-1; i++)
	{
		sum += (str[i+1] - str[i]-1);
	}
	return sum;
}
ll sumOFDigit(ll n)
{
	ll sum = 0;
	while(n > 0)
	{
		sum += num%10;
		n /= 10;
	}
	return sum;
}

int main(){
	int test;
	cin >> test;
	while(test--)
	{
		ll n;
		vector<ll> a,b;
		ll x, y;
		ll sum = 0;
		ll l=0;
		for(ll i = 0; i< n; i++)
		{
			cin >> x >> y;
			ll ans1 += sumOFDigit(x);
			ll ans2 += sumOFDigit(y);


		}
		if(ans1 > ans2)
		{
			cout << 0 << " "<< ans1-ans2 << endl;
		}
		else if(ans1 < ans2)
		{
			cout << 1 << " "<< ans2-ans1 << endl;
		}
		else
		{
			cout << 2 << " " << ans1 << endl;
		}

	}
	return 0;
}
