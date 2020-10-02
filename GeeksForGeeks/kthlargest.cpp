/* Finding the Kth largest element in an array  */

#include <bits/stdc++.h>
using namespace std;

int KthLargest(int arr[], int n, int k);

int main() {
	
	int t;
	cin >> t;
	
	while (t--) {
		int n, k;
		cin >> n >> k;
		
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		cout << KthLargest(arr, n, k) << endl; 
	}
	
	return 0;
}

/* Function which returns the Kth largest element using Priority queue */

int KthLargest(int arr[], int n, int k) {
	
	priority_queue <int> pq(arr, arr + n);
	k -= 1;
	
	while (k--) {
		pq.pop();
	}
	
	return pq.top();
}
