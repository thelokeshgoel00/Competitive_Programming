#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    set<int> s;
	    for(int i=0; i<3; i++){
	        int k;
	        cin>>k;
	        s.insert(k);
	    }
	    auto it=s.begin();
	    vector<int> v;
	    for(;it!=s.end(); it++){
	        v.push_back(*it);
	    }
	    int l=v.size();
	    int dp[l+1][n+1];
	    for(int i=0; i<n+1; i++){
	        dp[0][i]=-1;
	    }
	    for(int i=0; i<l+1; i++){
	        dp[i][0]=0;
	    }
	    for(int i=1; i<l+1; i++){
	        for(int j=1; j<n+1; j++){
	            if(v[i-1]>j){
	                dp[i][j]=dp[i-1][j];
	            }
	            else{
	                if(dp[i-1][j]!=-1&& dp[i][j-v[i-1]]!=-1){
	                    dp[i][j]=max(dp[i-1][j],1+dp[i][j-v[i-1]]);
	                }
	                else if(dp[i-1][j]!=-1){
	                    dp[i][j]=dp[i-1][j];
	                }
	                else if(dp[i][j-v[i-1]]!=-1){
	                    dp[i][j]=1+dp[i][j-v[i-1]];
	                }
	                else dp[i][j]=-1;
	            }
	        }
	    }
	    cout<<dp[l][n]<<endl;
	}
	return 0;
}