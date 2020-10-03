
#include<iostream> 
using namespace std; 


long int evenFib(int n) 
{ 
	if (n < 1) 
	return n; 
	if (n == 1) 
	return 2; 
	return ((4 * evenFib(n-1)) + 
			evenFib(n-2)); 
} 

int main () 
{ 
	int n = 7; 
	cout << evenFib(n); 
	return 0; 
} 
