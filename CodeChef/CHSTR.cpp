#include<bits/stdc++.h>
using namespace std;
int isalpha(int *str, int n)
{
	int sum = 0;
	for(int i = 0; i < n-1; i++)
	{
		sum += (str[i+1] - str[i]-1);
	}
	return sum;
}
int main(){
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		for(int i =0;i<n; i++)
			cin >> arr[i];
		int ans = isalpha(arr, n);
		cout << ans << endl;

	}
}
