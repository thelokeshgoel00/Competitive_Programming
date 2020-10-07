//Find the first non repeating character in given string

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    string str; 
	    cin>>str;
	    pair<int, int> arr[26];
	    for(int i=0;i<n;i++)
	    {
	        (arr[str[i]-'a'].first)++;
	       (arr[str[i]-'a'].second)=i;     // stores index of occurence
	    }
	    int res=n,i;
	    for(i=0;i<26;i++)
	    {
	        if(arr[i].first==1)
	        {
	            if(arr[i].second<res)
	            res=arr[i].second;
	        }
	    }
	    if(res<n)
	    cout<<str[res];
	    else               // if all characters are repeating
	    cout<<"-1";
	    cout<<"\n";
	}
	return 0;
}
