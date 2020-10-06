// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

 
int printSmallest(int a[3]) 
{ 
	int sum, sum1; 

	sort(a, a + 3); 

	int i, j, k, num; 

	
	for (int i = 0; i < 3; i++) { 
		if (a[i] % 3 == 0) 
			return a[i]; 
	} 

	
	for (i = 0; i < 3; i++) { 
		for (j = 0; j < 3; j++) { 

			// Generate the two digit number 
			num = (a[i] * 10) + a[j]; 
			if (num % 3 == 0) 
				return num; 
		} 
	} 
	return a[0]*100 + a[0]*10 + a[0]; 
} 
int main() 
{ 
	int arr[] = { 7, 7, 1 }; 
	cout << printSmallest(arr); 

	return 0; 
} 
