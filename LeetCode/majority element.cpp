class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i,l,k=0,j,max,lmt,p;
        l=nums.size();
        p=l/2+2;
        int temp[2][p];
        for(i=0;i<p;i++)
            temp[1][i]=0;
        temp[0][0]=nums[0];
        k=1;
        for(i=0;i<l;i++)
        {
            for(j=0;j<k;j++)
            {
                if(temp[0][j]==nums[i])
                {
                    temp[1][j]++;
                    break;
                }
            }
            if(j==k)
            {
                temp[0][k]=nums[i];
                temp[1][k]=1;
                k++;
            }
        } 
        for(i=0;i<k;i++)
        {
            if(temp[1][i]>l/2)
            {
                max=temp[0][i];
                break;
            }
        }
        return max;
    }
    
};