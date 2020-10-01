#include<bits/stdc++.h>
using namespace std;
#define ll long long
int isalpha(int *str, int n)
{
	int sum = 0;
	for(int i = 0; i < n-1; i++)
	{
		sum += (str[i+1] - str[i]-1);
	}
	return sum;
}
ll sumOFDigit(ll n)
{
	ll sum = 0;
	while(n > 0)
	{
		sum += num%10;
		n /= 10;
	}
	return sum;
}

int main(){
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		int row = n/8;
		int col = n%8;
		int i,j;
		for(i = 0;i < row; i++)
		{
			for(  k = 0; k< 8; k++)
			{
				cout <<"." << " ";
			}
			cout << endl;
		}
		for( j = 0; j < col; j++)
			cout << "." << " ";
		for(int k = j; k < 8; k++)
			cout << "X" << " ";
		cout << endl;
		if(i <=7)
		{
			for(int k = 0; k< 8; k++)
				cout << "#" << " ";
			cout << endl;
			i++;
		}
		for(int k = i; k< 8; k++){
			for(int j = 0; j< 8; j++ )
				cout << "."<< " ";
			cout << endl;
		}

	}
	return 0;
}
