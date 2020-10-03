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
