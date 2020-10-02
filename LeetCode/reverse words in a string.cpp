 class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp;
        s.push_back(' ');       //adding space after last word to make identification of words easier
        int i,l=s.length(),strt=0,wrd_len;
        while(s[strt]==' ')     //skipping the beggining extra spaces
            strt++;
        for(i=strt;i<l;i++)
        {
            if(s[i]==' ')
            {
                wrd_len=temp.length();
                if(wrd_len!=0)
                    words.push_back(temp);
                temp.erase(temp.begin(),temp.end());
            }
            else
            {
                temp.push_back(s[i]);
            }
        }
        int len=words.size();
        s.clear();          //using the string s , to store the reverse string
        for(i=len-1;i>=0;i--)
        {
            s.append(words[i]);
            if(i!=0)
                s.push_back(' ');
        }
        return s;
    }
};