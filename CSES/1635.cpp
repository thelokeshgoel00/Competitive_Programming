#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
	
     ll n,m;
     cin>>n>>m;
     vector< ll > coins(n);
     for(auto &i:coins) cin>>i;
 
     sort(all(coins));
 
     vector< ll > dp(m+1,0);
 
     for(ll i=0;i<n;i++){
     	 if(coins[i]<=m) dp[coins[i]]=1;
     }
 
 
     for(ll i=0;i<=m;i++){
 
     	 for(ll j=0;j<n;j++){
     	 	 if(i-coins[j]>=0){
                dp[i]= ( dp[i] + dp[i-coins[j]] )%MOD; 
     	 	 }else break;
     	 }
     }
     cout<<dp[m]<<endl;
 
	return 0;
}
 
int main(){
	
	ll t=1;
    //	cin>>t;
 
	while(t--)
		solve();
 
 
	return 0;
}