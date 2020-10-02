// Container with most water

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	while (t--) {
	    
		int n;
	    cin >> n;
	    
		int a[n];
	    
		for (int i = 0; i < n; i++) {
	        cin >> a[i];
	    }
	    
		int max = 0;
		
		// Finding the maximum area of water that can be contained ( 2-D Figure ) 
	    
		for (int i = 0; i < n - 1; i++) {
	        
			for (int j = i + 1; j < n; j++) {
	           
			    if (a[j] >= a[i]) {
	                
					if ((a[i] * (j - i)) >= max) {
	                    max = a[i] * (j - i);
	                }
	            
				}
	            
				else if (a[i] > a[j]) {
	               
				    if ((a[j] * (j - i)) >= max) {
	                    max = a[j] * (j - i);
	                }
	            
				}
	        }
	    }
	    cout << max << endl;
	}
	return 0;
}
