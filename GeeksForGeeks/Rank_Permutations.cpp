// Rank of the string amongst its permutations sorted lexicographically

#include <bits/stdc++.h>
using namespace std;
#define N 1000003
int fact(int n)
{
    if(n<=1)
    return 1;
    return n*fact(n-1);
}
void update(int *count,char c)
{
    for(int i=c-'a';i<26;i++)
    count[i]--;
}
int rank_lexo(string& str)
{
    int l=str.length(),rank=1,i=0;
	int count[26]={0};
	int p=fact(l);
	// count[i] contains count of characters present 
     // in str and are smaller than s[i]
	 // also checks for duplicates
	 for(i=0;i<l;i++)
	 {
	     count[str[i]-'a']++;
	     if(count[str[i]-'a']>1)
	     return 0;
	 }
	 for(i=1;i<26;i++)
	 {
	     count[i]+=count[i-1];
	 }
	 //done 
	 for(i=0;i<l;i++)
	 {
	     p=p/(l-i);  //for permutations of remaining letters
	     if(str[i]!='a')
	     rank+=((p%N)*(count[str[i]-'a'-1]%N))%N;
	   //this letter now needs to be removed from count of others
	     update(count,str[i]); 
	 }
	 return rank%N;
}
int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    string s; 
	    cin>>s;
	    cout<<rank_lexo(s)<<"\n";
	}
	return 0;
}
