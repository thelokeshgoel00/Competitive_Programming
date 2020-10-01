/*
Two words are anagrams of one another if their letters can be rearranged to form the other word.

In this challenge, you will be given a string. You must split it into two contiguous substrings, then determine the minimum number 
of characters to change to make the two substrings into anagrams of one another.

For example, given the string 'abccde', you would break it into two parts: 'abc' and 'cde'. Note that all letters have been used, the substrings are 
contiguous and their lengths are
 equal. Now you can change 'a' and 'b' in the first substring to 'd' and 'e' to have 'dec' and 'cde' which are anagrams. Two changes were necessary.

*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    for(int t = 0;t<q;t++)
    {
        char str[1001];
        cin>>str;
        if(strlen(str)%2!=0)
        {
            cout<<-1;
            cout<<"\n";
        }
        else  
        {
            sort(str,str+strlen(str)/2);
            sort(str+strlen(str)/2,str+strlen(str));
            //cout<<str;
            int count =0;
            int c =0, d =n/2;
            while(c<n/2&&d<n)
            {
                if(str[c]==str[d])
                {
                    c++:
                    d++;
                }
                else 
                {
                    
                }
            }
        }
    }
    return 0;
}
