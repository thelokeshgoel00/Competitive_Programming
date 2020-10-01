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
     vector< ll > v(n); 
     for(auto &i:v) cin>>i;
 
     set < ll > s;
     
     ll i=0,j=0;
     ll mxlen=0;
     while(j<n && i<=n){
        if(s.find(v[j])==s.end()){
            s.insert(v[j]);
            j++;
            mxlen = max(mxlen,j-i);
        }else{
            s.erase(v[i]);
            i++;
 
        }
     }
 
     cout<<mxlen<<endl;
 
    return 0;
}
 
int main(){
    
    ll t=1;
    //    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}