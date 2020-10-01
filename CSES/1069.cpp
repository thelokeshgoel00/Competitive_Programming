#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	string str;
	cin >> str;
	int res = 1;
	int count = 1;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i - 1])
		{
			count++;
			res = max(res, count);
		}
		else
		{

			count = 1;
		}
	}
	cout << res;

}
