#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long int 
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define PB push_back
#define F first
#define S second
 
 
int main(){
	 
	 ll n,m; 
	 cin>>n>>m;
	 vector< ll > coins(n);
	 for(auto &i:coins) cin>>i;
 
	 vector< ll > dp(m+1,INT_MAX);
	 dp[0] = 0;
 
	 for(ll i=1;i<=m;i++){
 
	 	for(ll j=0;j<n;j++){
	 		if(coins[j] <= i){
	 			dp[i] = min(dp[i],1 + dp[i-coins[j]]);
	 		}
	 	}
	 }
 
	 if(dp[m]==INT_MAX){
	 	cout<<-1<<endl;
	 }else{
	 	cout<<dp[m]<<endl;
	 }
 
 
 
 
	return 0;
}