//I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                v.pb(nums[i]);
                continue;
            }
            int flag=0;
            for(int j=0; j<v.size(); j++){
                if(nums[i]%v[j]!=0 && v[j]%nums[i]!=0){
                    // continue;
                    flag=1;
                }
            }
            if(flag==0){
                v.pb(nums[i]);
            }
        }
    return v;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> ans=largestDivisibleSubset(v);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }
}