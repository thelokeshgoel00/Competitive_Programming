#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
 
int solve() {
	
	ll n,x;
    cin>>n>>x;
	// iteratve 
	int apartment = 0;
	int floor = 0;
 
	// if(apartment < n ){
	// 	apartment += 2;
	// 	floor++;
	// }
 
	// while(apartment<n){
	// 	apartment+=x;
	// 	floor++;
	// }
 
	// cout<<floor<<endl;
    
    n -=2; 
    floor++;
 
    if(n%x && n>0){
    	floor +=( n/x + 1);
    }else if(n>0){
    	floor += n/x;
    }
 
    cout<<floor<<endl;
	return 0;
}
 
int main() {
	
	ll t; 
	cin>>t;
 
	while(t--)
		solve();
 
	return 0;
}