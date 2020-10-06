#include <iostream>
using namespace std;
int recur(int val[], int l[], int idx, int cap){
    if(l[idx]>cap){
        return recur(val,l,idx-1,cap);
        // memo[idx][capa]=recur()
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int val[n],l[n];
	    for(int i=0; i<n; i++){
	        cin>>val[i];
	        l[i]=i+1;
	    }
	    int dp[n+1][n+1];
	    for(int i=0; i<n+1; i++){
	        for(int j=0; j<n+1; j++){
	            if(i==0||j==0)dp[i][j]=0;
	            else{
	                if(l[i-1]>j){
	                    dp[i][j]=dp[i-1][j];
	                }
	                else{
	                    dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][j-l[i-1]]);
	                }
	            }
	        }
	    }
	    cout<<dp[n][n]<<endl;
	}
	return 0;
}