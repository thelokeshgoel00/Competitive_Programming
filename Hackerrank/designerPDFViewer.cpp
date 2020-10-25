#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int maxLetterHeight(string,vector<int> &);
int main()
{
    vector<int> letterHeights(26);
    string word;

    for(int i=0;i<26;i++)
        cin>>letterHeights[i];

    cin>>word;

    int wordLength = word.length();
    int maxHeight = maxLetterHeight(word,letterHeights);
    int selectArea = wordLength*maxHeight;

    cout<<selectArea<<endl;
    return(0);
}

int maxLetterHeight(string word,vector<int> &charHeights)
{
    int wordLength = word.length();
    int maxCharHeight = 0;
    for(int i=0;i<wordLength;i++)
    {
        int charAscii = (int)word[i];
        int heightIndex = charAscii-97;
        int charHeight = charHeights[heightIndex];

        if(charHeight > maxCharHeight)
           maxCharHeight = charHeight;
    }
    return maxCharHeight;
}

