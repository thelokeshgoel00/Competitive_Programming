#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long int 
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define PB push_back
#define F first
#define S second
 
int dp[1000000];
 
int main(){
   
   ll n; cin>>n;
 
   
   dp[0]=1;
 
   for(ll i=1;i<1000000;i++){
       ll j = i;
       dp[i]=0;
       while(j>=max(i-6,0LL)){
        dp[i]=(dp[j] + dp[i])%MOD;
        j--;
       }
       if(i<6){
          dp[i] +=1;
       }
   }
 
   cout<<dp[n-1]<<endl;
 
 
 
 
  return 0;
}