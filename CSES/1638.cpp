#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long int 
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define PB push_back
#define F first
#define S second
 
 
int main(){
   
  ll n; cin>>n;
  vector< string > v(n);
 
  for(auto &i:v) cin>>i;
  
  if(v[0][0]=='*' || v[n-1][n-1]=='*') return cout<<0<<endl,0;
 
  vector < vector< ll > > dp(n,vector< ll > (n,0));
 
  // for(ll i=0;i<n;i++){
  //   for(ll j=0;j<n;j++){
  //     if(v[i][j]=='*'){
  //       dp[i][j] = -1;
  //     }
  //   }
  // }
 
  dp[0][0] = 1;
   
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
      if(i==0 && j==0) continue;
      else{
        if(i-1<0 || v[i-1][j]=='*') dp[i][j] +=0;
        else dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
 
        if(j-1<0 || v[i][j-1]=='*') dp[i][j]+=0;
        else dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
      }
    }
  }
 
  cout<<dp[n-1][n-1]<<endl;
 
  return 0;
}