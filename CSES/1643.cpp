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
 
     ll gm=INT_MIN,lm=INT_MIN;
 
     for(auto i:v){
        if(lm + i > i){
            lm = lm + i;
        }else{
            lm = i;
        }
        gm = max(lm,gm);
     }
 
     cout<<gm<<endl;
 
    return 0;
}
 
int main(){
    
    ll t=1;
    //    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}