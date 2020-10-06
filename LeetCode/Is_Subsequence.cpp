class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j=0;                  //keeping j=0 initially
        if(t.length()<s.length())
            return false;
        for(i=0;i<t.length();i++)
        {
            if(t[i]==s[j])
            {
                j++;                //incrementing j by 1, so as to compare next character
                if(j==s.length())
                    break;
            }
        }
        if(j==s.length())
            return true;
        else 
            return false;
    }
};