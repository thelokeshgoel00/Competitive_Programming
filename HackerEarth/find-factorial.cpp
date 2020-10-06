#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans = 1;
	if(n>0){
		while(n){
		ans*=n;
		n--;
		}
		cout<<ans;
	}
	else if(n==0) cout<<ans;
	else cout<<"Factorial of negative number can not be obtained...";
}

//solution-2
/*
     * Java method to calculate factorial of a large number
     * @return BigInteger factorial of given number
     */
    public static BigInteger factorial(int number) {
        BigInteger factorial = BigInteger.ONE;

        for (int i = number; i > 0; i--) {
            factorial = factorial.multiply(BigInteger.valueOf(i));
        }

        return factorial;
    }
