#include<bits/stdc++.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		int *arr = new int[n];
		long long sum=0;
		for(int i=0; i<n; i++){

			cin>>arr[i];
			if(arr[i] > k){
				sum+= (arr[i]-k);
			}
		}
		cout<<sum<<endl;
		delete []arr;

	}
}
