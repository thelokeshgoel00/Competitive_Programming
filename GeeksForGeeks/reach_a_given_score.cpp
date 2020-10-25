#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	int ar[]={3,5,10};
	while(t--){
	    int n;
	    cin>>n;
	    int dp[4][n+1];
	    for(int i=0; i<n+1;i++){
	        dp[0][i]=0;
	    }
	    for(int i=0; i<4;i++){
	        dp[i][0]=1;
	    }
	    for(int i=1; i<4; i++){
	        for(int j=1; j<n+1; j++){
	            if(ar[i-1]>j){
	                dp[i][j]=dp[i-1][j];
	            }
	            else{
	                dp[i][j]=dp[i-1][j]+dp[i][j-ar[i-1]];
	            }
	        }
	    }
	    cout<<dp[3][n]<<endl;
	    
	}
	return 0;
}