#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
     ll a,b; cin>>a>>b;
 
     if((a+b)%3) return cout<<"NO"<<endl,0;
 
     ll ab = (a+b)/3;
 
     ll x = 2*ab - a;
     ll y = a - ab;
 
     if(x<0 || y<0){
        return cout<<"NO"<<endl,0;
     }
 
     cout<<"YES"<<endl;
 
    return 0;
}
 
int main(){
    
    ll t=1;
    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}