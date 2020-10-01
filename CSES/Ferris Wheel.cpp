#include<bits/stdc++.h>
using namespace std;
int is(int *arr, int n, int sum)
{
	int count = 0;
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		if (arr[start] + arr[end] > sum)
		{
			count++;
			end--;
		}
		else if (arr[start] + arr[end] <= sum)
		{
			count++;
			end--;
			start++;
		}
	}
	if (start == end)
		count++;
	return count;
}
int main()
{
	int n; int sum;
	cin >> n >> sum;
	int*arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	cout << is(arr, n, sum);

}