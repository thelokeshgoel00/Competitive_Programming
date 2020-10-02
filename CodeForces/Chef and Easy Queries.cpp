// Chef and Easy Queries

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	while (t--) {
		
		long n, k;
		cin >> n >> k;
		
		long arr[n];
		
		for (long i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		long j = 0, index = 1;
		
		// First day when queries to be solved are less than k
		
		while (arr[j] >= k) {
			
			if (j == n - 1) {
				
				index += arr[j] / k;
				break; 
			
			}
			
			else {
				
				arr[j] -= k;
				j++;
				
				arr[j] += arr[j - 1];
				index++;
			}
		}
		
		cout << index << endl;
	}
	return 0;
}
