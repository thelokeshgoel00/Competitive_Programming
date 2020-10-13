#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
		int l;
	char ch;
	vector <string> s;
	for(int i=0;i<n;i++)
	{
		string s1;cin>>s1;
		s.push_back(s1);
	}
	
    for(int i=0;i<n-1;i++)
	{
		string s1=s[i];
		reverse(s1.begin(),s1.end());
		for(int j=i+1;j<n;j++)
		{
			if(s[j]==s1)
			{
				l=s1.length();
				ch=s1[l/2];
				break;
			}
		}
	}
	cout<<l<<" "<<ch;
	return 0;
}