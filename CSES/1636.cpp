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
     
   vector< ll > dp(m+1,0);
   
   dp[0] = 1;
 
   for(ll i=0;i<n;i++){
     
     for(ll j=0;j<=m;j++){
       if(j-coins[i]>=0) dp[j]= (dp[j] + dp[j-coins[i]])%MOD;
     }
 
   }
 
    cout<<dp[m]<<endl;
 
 
  return 0;
}