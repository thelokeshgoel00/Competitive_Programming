#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

struct tile{
	int a,b,c,d;
};

int solve() {
	
	ll n,m; cin>>n>>m;
     
    vector< struct tile > v(n);
    for(ll i=0;i<n;i++){
    	cin>>v[i].a>>v[i].b>>v[i].c>>v[i].d;
    }
    
     if(m%2) {
     	cout<<"NO"<<endl;
     	return 0;
     }
    for(auto i:v){
    	if(i.b == i.c){
    		cout<<"YES"<<endl;
    		return 0;
    	}
    }

    cout<<"NO"<<endl;



	return 0;
}

int main() {
	
	ll t; 
	cin>>t;

	while(t--)
		solve();

	return 0;
}

