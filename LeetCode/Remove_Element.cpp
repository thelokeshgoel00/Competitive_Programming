// Using Two pointers approach
// Space Complexity : O(n)
class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int i=0,j=arr.size()-1;
        for(i=0;i<j;i++)
        {
            if(arr[i]==val)    
            {
                while(arr[j]==val && j>0) // starting from end, find first element not equal to val
                    j--;
                if(i<j)
                {
                    arr[i]=arr[j];   
                    j--;               // decrease array length by one
                }
            }
        }
        if(i==j && arr[i]==val)       
            j--;
        if(j==0 && arr[j]==val)  
            return 0;
        if(j<0)
            return 0;
        return j+1;
    }
};
