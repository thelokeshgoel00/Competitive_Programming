#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n1,n2,n3;
	    cin>>n1>>n2>>n3;
	    string s1,s2,s3;
	    cin>>s1>>s2>>s3;
	    int dp[n1+1][n2+1][n3+1];
	    for(int i=0; i<n1+1; i++){
	        for(int j=0; j<n2+1; j++){
	            for(int k=0; k<n3+1; k++){
	                if(i==0||j==0||k==0){
	                    dp[i][j][k]=0;
	                }
	                else{
	                    if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1]){
	                        dp[i][j][k]=dp[i-1][j-1][k-1]+1;
	                    }
	                    else{
	                        dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
	                    }
	                }
	            }
	        }
	    }
	    cout<<dp[n1][n2][n3]<<endl;
	}
	return 0;
}