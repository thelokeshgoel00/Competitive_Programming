#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s1,s2;
	    cin>>s1;
	    s2=s1;
	    reverse(s1.begin(),s1.end());
	    int n=s1.size();
	    int dp[n+1][n+1];
	    for(int i=0; i<n+1; i++){
	        for(int j=0; j<n+1; j++){
	            if(i==0||j==0){
	                dp[i][j]=0;
	            }
	            else{
	                if(s1[i-1]==s2[j-1]){
	                    dp[i][j]=dp[i-1][j-1]+1;
	                }
	                else{
	                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	                }
	            }
	        }
	    }
	    cout<<n-dp[n][n]<<endl;
	}
	return 0;
}