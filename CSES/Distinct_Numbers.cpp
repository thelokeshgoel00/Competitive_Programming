#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
     ll n; cin>>n;
 
     
     set< ll > s;
 
     ll val;
 
     while(n--) {
        cin>>val;
        s.insert(val);
     }
     ll sz = s.size();
     cout<<sz<<endl;
 
 
    return 0;
}
 
int main(){
    
    ll t=1;
    // cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}