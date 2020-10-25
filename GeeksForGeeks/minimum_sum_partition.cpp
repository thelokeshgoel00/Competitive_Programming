class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
	   // memset(dp,0,sizeof(dp));
	    int s=n,sum=0;
	    for(int i=0; i<s; i++){
	        sum+=arr[i];
	    }
	    bool dp[s+1][sum+1];
	    for(int i=0; i<sum+1; i++){
	        dp[0][i]=0;
	    }
	    for(int i=0; i<s+1; i++){
	        dp[i][0]=1;
	    }
	    for(int i=1;i<s+1; i++){
	        for(int j=1; j<sum+1; j++){
	            if(arr[i-1]>j){
	                dp[i][j]=dp[i-1][j];
	            }
	            else{
	                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
	            }
	        }
	    }
	    vector<int> v;
	    for(int i=0; i<sum+1; i++){
            if(dp[s][i]){
                v.push_back(i);
	           // cout<<i<<" ";
            }
	    }
	    int ans=INT_MAX;
	    for(int i=0; i<v.size()/2; i++){
	        ans=min(ans,sum-2*v[i]);
	    }
	    if(v.size()%2!=0){
	        ans=min(ans,sum-2*v[v.size()/2]);
	    }
	    return ans;
	    // Your code goes here
	} 
};