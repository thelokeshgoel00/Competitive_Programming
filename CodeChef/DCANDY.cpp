#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int sum=0;
	    sort(arr,arr+n);
	    for(int i=n-3;i>=0;i-=3)
	    {
	        sum+=arr[i];
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
