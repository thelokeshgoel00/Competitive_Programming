class Solution {
public:
    void solve(set<vector<int>>&res, vector<int>& candidates, int target, int i,vector<int>& curr){
        if(target<0){
            return;
        }
        if(target==0){
            vector<int>topush(curr);
            sort(topush.begin(),topush.end());
            res.insert(topush);
            return;
        }
        for(;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            solve(res,candidates,target-candidates[i],i+1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>res;
        vector<int>curr;
        solve(res,candidates,target,0,curr);
        vector<vector<int>>ans;
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};
