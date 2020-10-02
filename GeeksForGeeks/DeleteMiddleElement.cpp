// Delete middle element of a stack

#include<bits/stdc++.h>
using namespace std;

stack <int> deleteMid (stack <int> s, int sizeOfStack, int current);

int main() {
	
	int testcases;
	cin >> testcases;
	
	while (testcases--) {
		
		int sizeOfStack;
		cin >> sizeOfStack;
		
		stack <int> myStack;
		
		for (int i = 0; i < sizeOfStack; i++) {
			
			int x;
			cin >> x;
			
			// Push elements into the stack
			
			myStack.push(x);
		
		}
		
		if (sizeOfStack == 1) {
			
			cout << myStack.top();
		
		}
		else {
			
			// Function call to delete middle element
			
			stack <int> modified = deleteMid(myStack, myStack.size(), 0);
			
			// Print the modified stack
			
			while (!modified.empty()){
				
				cout << modified.top() << " ";
				modified.pop();
				
			}
		}
		cout << endl;
	}
	return 0;
}

stack <int> deleteMid (stack <int> s, int n, int current)
{
    int i = 0, j = 0, a[n];
        
        // Store all elements except the middle one in an array 
        
		while (s.empty() == false) {
            
			if (i != n / 2) {
                
				a[j] = s.top();
                s.pop();
                j++;
            
			}
            else{
				
				s.pop();
			}
			
            i++;
        }
    
    // Push array into stack
    
	for (i = j - 1; i >= 0; i--) {
       
	    s.push(a[i]);
    
	}
    
	return s;
}
