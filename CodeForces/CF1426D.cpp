#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

int solve() {
	
	 ll n; cin>>n;
	 vector< ll > v(n);
	 
	 for(auto &i:v) cin>>i;

	 ll sum = 0;
	 set < ll  > s;  // track of previous sum value
	 s.insert(0);  // initiall no element

	 ll cnt = 0; 
    
     for(auto i:v){
     	sum += i;

     	if(s.find(sum) != s.end()){
     		cnt++; 
     		sum = i;
     		s.clear();
     		s.insert(0);
     	}
     	s.insert(sum);
     }

     cout<<cnt<<endl;



	return 0;
}

int main() {
	
	ll t; 
	t=1;
	// cin>>t;

	while(t--)
		solve();

	return 0;
}

