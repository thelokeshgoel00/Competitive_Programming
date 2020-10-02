class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i;
        sort(nums.begin(),nums.end());
        int h=nums.size();
        for(i=0;i<h-1;i++)
        {
            if(nums[i]==nums[i+1])
                break;
        }
        return nums[i];
    }
};