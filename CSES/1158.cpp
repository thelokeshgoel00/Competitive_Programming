#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
 
int solve() {
	
	ll n,x; 
	cin>>n>>x;
 
	vector< pair< ll , ll > > v(n);
               // cost , pages
	for(ll i=0;i<n;i++){
		cin>>v[i].first;
	}
	for(ll i=0;i<n;i++){
		cin>>v[i].second;
	}
 
   vector< ll > dp(x+1,0),tempdp(x+1,0);
 
   for(ll i=0;i<n;i++){
   	for(ll j=1;j<x+1;j++){
   		if(j>=v[i].first){
   			dp[j] = max(v[i].second + tempdp[j-v[i].first],tempdp[j]);
   		}
   	}
   	for(ll k=0;k<x+1;k++){
   		tempdp[k] = dp[k];
   		// cout<<tempdp[k]<<" ";
   	} //cout<<endl;
   }
 
   cout<<dp[x]<<endl;
 
	return 0;
}
 
int main() {
	
	ll t; 
	t = 1;
	//cin>>t;
 
	while(t--)
		solve();
 
	return 0;
}