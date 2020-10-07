#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

int solve() {
	
	ll n; cin>>n;

	ll mn = INT_MAX;
    ll steps=0;
	for(ll i=1;i<=sqrt(n);i++){
		steps = i-1;
		if((n-i)%i){
			steps += (n-i)/i + 1;
		}else{
			steps += (n-i)/i;
		}

		mn = min(steps,mn);
	}

	cout<<mn<<endl;

	return 0;
}

int main() {
	
	ll t; 
	cin>>t;

	while(t--)
		solve();

	return 0;
}

