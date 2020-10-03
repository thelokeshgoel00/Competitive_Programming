#include <bits/stdc++.h>
using namespace std;
int dp[999]={-1};
int recur(int n){
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n==0){
        return dp[n]=1;
    }
    return dp[n]=recur(n-1)+recur(n-2)+recur(n-3);
}
int main() {
    int t;
    cin>>t;
    // int ar[]={1,2,3};
    while(t--){
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
        cout<<recur(n)<<endl;
    }
	//code
	return 0;
}a