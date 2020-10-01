#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans = 1;
	while(n){
		ans*=n;
		n--;
	}
	cout<<ans<<endl;
}
