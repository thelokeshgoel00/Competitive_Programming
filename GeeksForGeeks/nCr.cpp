// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int mod=1000000000+7;
    // int memo[1005][805]={{0}};
    int nCr(int n, int r){
        if(r>n)return 0;
        int dp[n+1][r+1];
        for(int i=0; i<n+1; i++){
            dp[i][0]=1;
        }
        for(int i=1; i<r+1; i++){
            dp[0][i]=-1;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<r+1; j++){
                if(j>i){
                    dp[i][j]=-1;
                }
                else{
                    if(dp[i-1][j]!=-1){
                        dp[i][j]=((dp[i-1][j]%mod)+(dp[i-1][j-1])%mod)%mod;
                    }
                    else{
                        dp[i][j]=dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[n][r];
        // if(r>n)return 0;
        // if(memo[n][r]!=0){
        //     return memo[n][r];
        // }
        // // code here
        // if(n==0&&r==0){
        //     memo[n][r]=1;
        //     return memo[n][r];
        // }
        // if(r==0||r==n){
        //     memo[n][r]=1;
        //     memo[n][n-r]=1;
        //     return memo[n][r];
        // }
        // if(r==1||r==n-1){
        //     memo[n][r]=n;
        //     memo[n][n-r]=n;
        //     return memo[n][r];
        // }
        // return ((nCr(n-1,r-1)%mod)+(nCr(n-1,r)%mod)%mod);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends