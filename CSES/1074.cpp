#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
     ll n ; cin>>n;
     vector< ll > v(n);
     for(auto &i:v) cin>>i;
 
// median as target      
      sort(all(v));
     ll target = v[n/2];
     ll sum=0;
     for(auto i:v){
        sum+= abs(target-i);
     }
 
     cout<<sum<<endl;
 
  
    return 0;
}
 
int main(){
    
    ll t=1;
    //    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}