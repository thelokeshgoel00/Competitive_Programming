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
 
  vector< ll > dp(n+1,INT_MAX);
 
  dp[0] = 0;
 
  for(ll i=1;i<=min(n,9LL);i++){
     dp[i] = 1;
  }
 
  for(ll i=10;i<=n;i++){
     
     ll num = i;                                  // check all digits and which is min take that   
     
     while(num){
      dp[i] = min(dp[i],dp[i-num%10]+1);
      num/=10;
     }
 
  }
 
  cout<<dp[n]<<endl;
 
  return 0;
}