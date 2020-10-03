// I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;
 int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        int ans=1,last_max;
        // memset(dp,0,sizeof(dp));
        for(int i=0; i<nums.size(); i++){
                dp[i]=1;
                // last_max=-9999;
                for(int j=0; j<i; j++){
                        if(nums[j]<nums[i]){
                                // if(dp[nums[j]]>=dp[nums[i]])
                                dp[i]=max(dp[i],dp[j]+1);
                                // last_max=nums[j];
                                ans=max(ans,dp[i]);
                        }
                }
        }
        return ans;
}
int main(){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
                // int k
                cin>>v[i];
        }
        cout<<lengthOfLIS(v)<<endl;
}
