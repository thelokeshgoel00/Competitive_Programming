class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int l1=ransomNote.length();
        int l2=magazine.length();
        int i,j;
        for(i=0;i<l1;i++)
            {
            for(j=0;j<l2;j++)
                {
                if(ransomNote[i]==magazine[j])
                    {
                    magazine[j]='#';        // # is for identification
                break;}
            }
            if(j==l2)
                return false;
        }
        return true;
    }
  
};