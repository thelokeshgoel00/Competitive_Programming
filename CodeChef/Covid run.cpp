// Covid Run

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	while (t--) {
		
		/* 
		   
		   n = No. of cities 
		   k = No. of cities to be skipped
		   x = Current city at which virus is present
		   y = City where you live
		 
		*/
		 
		int n, k, x, y;
		cin >> n >> k >> x >> y;
		
		int a = x, flag = 0;
		
		do {
			
			if (x == y) {
				
				flag = 1;
				break;
			
			}
			else {
				x = (x + k) % n;
			}
			
		} while(x != a);
		
		if (flag == 1) {
			
			cout << "YES" << endl;
		}
		
		else {
			
			cout << "NO" << endl;
		}
	}
}
