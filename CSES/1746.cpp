#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()


int solve() {
	
	ll n,m; cin>>n>>m;

	vector< ll > v(n);
	for(auto &i:v) cin>>i;

   

    vector< ll > dp(m+2,0),tempdp(m+2,0);
    
    for(ll i=0;i<n;i++){

    	for(ll j=1;j<=m;j++){
    		if(i==0){
    			if(v[i]==0 || v[i]==j){	
    		 	  dp[j]=1;
    		 	}else{
    		 		dp[j]=0;
    		 	}
    		}else{
    			if(v[i]==0 || v[i]==j){
    				dp[j] = ((tempdp[j-1]+tempdp[j])+(tempdp[j+1]))%MOD;
    			}else{
    				dp[j]=0;
    			}
    		}

    		
    	}
    	for(ll k=1;k<=m;k++){
    			tempdp[k]=dp[k];
    			// cout<<dp[k]<<" ";
    		}
    		// cout<<endl;
    }

    
     ll cnt = 0;

     for(auto i:dp){
     	cnt+=i;
     	cnt%=MOD;
     }
     
     cout<<cnt<<endl;
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

