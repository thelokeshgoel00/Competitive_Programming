/******************************************
* AUTHOR : PRIYAM THAKURIA*
* NICK : psiphon_hack *
* INSTITUTION : NIT Kurukshetra *
******************************************/
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

void test_case()
{
	ll n, k; cin>>n>>k;
	ll b[n]={0};
	for(ll i=0;i<n;i++) {
		ll x; cin>>x;
		if(x%k==0)
			b[i]=1;
		cout<<b[i];
	}
	cout<<"\n";
}

int main() {

	fastio
	ll t; cin >> t;
	while (t--)
		test_case();

	return 0;
}
