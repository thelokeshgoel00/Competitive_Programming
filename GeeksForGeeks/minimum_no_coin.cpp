// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	int minCoins(int coins[], int s, int v) 
	{ 
	    int dp[s+1][v+1];
	    for(int i=0; i<v+1; i++){
	        dp[0][i]=-1;
	    }
	    for(int i=0; i<s+1; i++){
	        dp[i][0]=0;
	    }
        //-1 in table means it can't be made
	    for(int i=1;i<s+1; i++){
	        for(int j=1; j<v+1; j++){
	            if(coins[i-1]>j){
	                dp[i][j]=dp[i-1][j];
	            }
	            else{
	                if(dp[i-1][j]!=-1 && dp[i][j-coins[i-1]]!=-1){
	                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
	                }
	                else if(dp[i-1][j]!=-1){
	                    dp[i][j]=dp[i-1][j];
	                }
	                else if(dp[i][j-coins[i-1]]!=-1)dp[i][j]=1+dp[i][j-coins[i-1]];
	                else dp[i][j]=-1;
	            }
	        }
	    }
	    return dp[s][v];
	    
	    // Your code goes here
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends